//
// Created by student on 25.01.2020.
//

#include "../include/Booking.h"
#include "Customer.h"
#include "Train.h"
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <boost/regex.hpp>
#include <boost/test/test_tools.hpp>


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(BookingCreationCase){
        trainPtr t1 = std::make_shared<Train>("ciapong",10);
        customerPtr c1 = std::make_shared<Customer>("Adam","Sandler");
        bookingPtr b1 = std::make_shared<Booking>(c1,t1,2,1);
        BOOST_TEST_MESSAGE(b1->info());
        BOOST_CHECK_EQUAL(b1->getTotalPrice(),40);
        BOOST_CHECK_EQUAL(t1->getFreeSpace(),10);
        BOOST_CHECK_EQUAL(c1->getBalance(),0);
        BOOST_CHECK_EQUAL(b1->getID().length(),36);
    }

    BOOST_AUTO_TEST_CASE(BookingDeleteCase){
        trainPtr t1 = std::make_shared<Train>("ciapong",10);
        customerPtr c1 = std::make_shared<Customer>("Adam","Sandler");{
            bookingPtr b1 = std::make_shared<Booking>(c1,t1,2,1);
            BOOST_TEST_MESSAGE(b1->info());
            BOOST_CHECK_EQUAL(b1->getTotalPrice(),40);
            BOOST_CHECK_EQUAL(t1->getFreeSpace(),10);
            BOOST_CHECK_EQUAL(c1->getBalance(),0);
            BOOST_CHECK_EQUAL(b1->getID().length(),36);
        }
        BOOST_CHECK_EQUAL(t1->getFreeSpace(),10);
        BOOST_CHECK_EQUAL(c1->getBalance(),0);
    }

BOOST_AUTO_TEST_SUITE_END()
