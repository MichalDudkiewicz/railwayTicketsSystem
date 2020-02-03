//
// Created by student on 25.01.2020.
//

#include "Booking.h"
#include <boost/test/unit_test.hpp>
#include "BookingManager.h"
#include <iostream>
#include "CustomerRepository.h"
#include "TrainRepository.h"
#include "BookingRepository.h"
#include "Customer.h"


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(BookingManagerCase){
        BOOST_TEST_MESSAGE(BookingManager::getInstance().info());
        BOOST_CHECK_EQUAL(BookingManager::getInstance().getAll().size(),0);
        bookingPtr b1 = std::make_shared<Booking>(CustomerRepository::getInstance().getAll()[0],TrainRepository::getInstance().getAll()[0],2,3);
        bookingPtr b2 = std::make_shared<Booking>(CustomerRepository::getInstance().getAll()[0],TrainRepository::getInstance().getAll()[1],4,2);
        bookingPtr b3 = std::make_shared<Booking>(CustomerRepository::getInstance().getAll()[0],TrainRepository::getInstance().getAll()[0],8,1);
        bookingPtr b4 = std::make_shared<Booking>(CustomerRepository::getInstance().getAll()[2],TrainRepository::getInstance().getAll()[1],6,3);
        bookingPtr b5 = std::make_shared<Booking>(CustomerRepository::getInstance().getAll()[2],TrainRepository::getInstance().getAll()[0],3,2);
        bookingPtr b6 = std::make_shared<Booking>(CustomerRepository::getInstance().getAll()[1],TrainRepository::getInstance().getAll()[0],4,3);
        bookingPtr b7 = std::make_shared<Booking>(CustomerRepository::getInstance().getAll()[1],TrainRepository::getInstance().getAll()[2],10,2);
        BookingManager::getInstance().add(b1);
        BookingManager::getInstance().add(b2);
        BookingManager::getInstance().add(b3);
        BookingManager::getInstance().add(b4);
        BookingManager::getInstance().add(b5);
        BookingManager::getInstance().add(b6);
        BookingManager::getInstance().add(b7);
        BOOST_CHECK_EQUAL(BookingManager::getInstance().getAll().size(),7);
        BOOST_CHECK_EQUAL(BookingManager::getInstance().getAll()[0]->getID(),b1->getID());
        BOOST_CHECK_EQUAL(BookingManager::getInstance().get(BookingManager::getInstance().getAll()[0]->getID())->getID(),b1->getID());
        BOOST_CHECK_EQUAL(BookingManager::getInstance().getAll()[1]->getCustomer()->getMyBookings().size(),3);
        BookingManager::getInstance().remove(2);
        BOOST_CHECK_EQUAL(BookingManager::getInstance().getAll()[1]->getCustomer()->getMyBookings().size(),2);
        BOOST_CHECK_EQUAL(BookingManager::getInstance().getAll().size(),6);
    }

BOOST_AUTO_TEST_SUITE_END()
