//
// Created by student on 25.01.2020.
//

#include "../include/Booking.h"
#include <boost/test/unit_test.hpp>
#include "BookingRepository.h"
#include "Customer.h"
#include "Train.h"
typedef std::shared_ptr<Train> trainPtr;
typedef std::shared_ptr<Customer> customerPtr;


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(BookingRepositoryCase)
    {
        customerPtr c1 = std::make_shared<Customer>("Adam","Sandler");
        customerPtr c2 = std::make_shared<Customer>("Adam","Nowak");
        customerPtr c3 = std::make_shared<Customer>("Jan","Brzeczyszczykiewicz");
        customerPtr c4 = std::make_shared<Customer>("Tinky","Winky");
        customerPtr c5 = std::make_shared<Customer>("Elliot","Alderson");
        trainPtr t1 = std::make_shared<Train>("TGV1",100);
        trainPtr t2 = std::make_shared<Train>("TGV2",120);
        bookingPtr b1 = std::make_shared<Booking>(c1,t1,2,3);
        bookingPtr b2 = std::make_shared<Booking>(c1,t2,4,2);
        bookingPtr b3 = std::make_shared<Booking>(c2,t1,8,1);
        bookingPtr b4 = std::make_shared<Booking>(c3,t2,6,3);
        bookingPtr b5 = std::make_shared<Booking>(c3,t1,3,2);
        bookingPtr b6 = std::make_shared<Booking>(c4,t2,1,1);
        bookingPtr b7 = std::make_shared<Booking>(c4,t1,4,3);
        bookingPtr b8 = std::make_shared<Booking>(c5,t1,10,2);
        BookingRepository allBookings;
        allBookings.add(b1);
        allBookings.add(b2);
        allBookings.add(b3);
        allBookings.add(b4);
        allBookings.add(b5);
        allBookings.add(b6);
        allBookings.add(b7);
        allBookings.add(b8);
        BOOST_TEST_MESSAGE(allBookings.info());
        BOOST_CHECK_EQUAL(allBookings.getAll().size(),8);
        BOOST_CHECK_EQUAL(allBookings.get(allBookings.getAll().back()->getID())->getID(),b8->getID());
        allBookings.remove(allBookings.get(allBookings.getAll().back()->getID()));
        BOOST_CHECK_EQUAL(allBookings.getAll().size(),7);
        BOOST_CHECK_EQUAL(allBookings.get(allBookings.getAll().back()->getID())->getID(),b7->getID());
    }

BOOST_AUTO_TEST_SUITE_END()
