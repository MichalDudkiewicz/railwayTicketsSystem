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

    BOOST_AUTO_TEST_CASE(BookingCreationCase)
    {
        trainPtr t1 = std::make_shared<Train>("ciapong",10);
        customerPtr c1 = std::make_shared<Customer>("Adam","Sandler");
        Booking b1(c1,t1,2,1);
        BOOST_TEST_MESSAGE(b1.info());
        BOOST_CHECK_EQUAL(b1.getTotalPrice(),40);
        BOOST_CHECK_EQUAL(t1->getFreeSpace(),9);
        BOOST_CHECK_EQUAL(c1->getBalance(),1);
        BOOST_CHECK_EQUAL(b1.getID().length(),36);
    }

    BOOST_AUTO_TEST_CASE(BookingDeleteCase)
    {
        trainPtr t1 = std::make_shared<Train>("ciapong",10);
        customerPtr c1 = std::make_shared<Customer>("Adam","Sandler");
        Booking *b1 = new Booking(c1,t1,2,1);
        BOOST_TEST_MESSAGE(b1->info());
        BOOST_CHECK_EQUAL(b1->getTotalPrice(),40);
        BOOST_CHECK_EQUAL(t1->getFreeSpace(),9);
        BOOST_CHECK_EQUAL(c1->getBalance(),1);
        BOOST_CHECK_EQUAL(b1->getID().length(),36);
        delete b1;
        BOOST_CHECK_EQUAL(t1->getFreeSpace(),10);
        BOOST_CHECK_EQUAL(c1->getBalance(),1);
    }

BOOST_AUTO_TEST_SUITE_END()
