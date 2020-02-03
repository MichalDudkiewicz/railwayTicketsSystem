//
// Created by student on 25.01.2020.
//

#include "../include/Booking.h"
#include <boost/test/unit_test.hpp>
#include "BookingRepository.h"
#include "TrainRepository.h"
#include "CustomerRepository.h"
typedef std::shared_ptr<Train> trainPtr;
typedef std::shared_ptr<Customer> customerPtr;


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(BookingRepositoryCase)
    {
        bookingPtr b1 = std::make_shared<Booking>(CustomerRepository::getInstance().getAll()[0],TrainRepository::getInstance().getAll()[0],2,3);
        bookingPtr b2 = std::make_shared<Booking>(CustomerRepository::getInstance().getAll()[0],TrainRepository::getInstance().getAll()[1],4,2);
        bookingPtr b3 = std::make_shared<Booking>(CustomerRepository::getInstance().getAll()[0],TrainRepository::getInstance().getAll()[0],8,1);
        bookingPtr b4 = std::make_shared<Booking>(CustomerRepository::getInstance().getAll()[2],TrainRepository::getInstance().getAll()[1],6,3);
        bookingPtr b5 = std::make_shared<Booking>(CustomerRepository::getInstance().getAll()[2],TrainRepository::getInstance().getAll()[0],3,2);
        bookingPtr b6 = std::make_shared<Booking>(CustomerRepository::getInstance().getAll()[3],TrainRepository::getInstance().getAll()[0],4,3);
        bookingPtr b7 = std::make_shared<Booking>(CustomerRepository::getInstance().getAll()[3],TrainRepository::getInstance().getAll()[2],10,2);
        BookingRepository allBookings;
        allBookings.add(b1);
        allBookings.add(b2);
        allBookings.add(b3);
        allBookings.add(b4);
        allBookings.add(b5);
        allBookings.add(b6);
        allBookings.add(b7);
        BOOST_TEST_MESSAGE(allBookings.info());
        BOOST_CHECK_EQUAL(allBookings.getAll().size(),7);
        BOOST_CHECK_EQUAL(allBookings.get(allBookings.getAll().back()->getID())->getID(),b7->getID());
        allBookings.remove(allBookings.getAll().size());
        BOOST_CHECK_EQUAL(allBookings.getAll().size(),6);
        BOOST_CHECK_EQUAL(allBookings.getAll().back()->getID(),b6->getID());
    }

BOOST_AUTO_TEST_SUITE_END()
