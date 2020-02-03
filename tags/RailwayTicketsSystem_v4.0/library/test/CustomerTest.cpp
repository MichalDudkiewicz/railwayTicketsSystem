//
// Created by student on 25.01.2020.
//

#include "Customer.h"
#include <boost/test/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(CustomerCreationCase){
        Customer c1("Jan","Kowalski");
        BOOST_TEST_MESSAGE(c1.info());
        BOOST_REQUIRE_EQUAL(c1.getDiscount(), 0);
        BOOST_REQUIRE_EQUAL(c1.getBalance(), 0);
        BOOST_CHECK_EQUAL(c1.getID().length(),36);
        BOOST_CHECK_EQUAL(c1.getFullName(),"Jan Kowalski");
        }

BOOST_AUTO_TEST_CASE(CustomerRegularCase){
        Customer c1("Jan","Kowalski");
        c1.setBalance();
        c1.setBalance();
        c1.setBalance();
        c1.setBalance();
        BOOST_REQUIRE_EQUAL(c1.getDiscount(), 0.7);
        BOOST_REQUIRE_EQUAL(c1.getBalance(), 4);
        BOOST_TEST_MESSAGE(c1.info());
    }

BOOST_AUTO_TEST_CASE(CustomerModificationCase){
        Customer c1("Jan","Kowalski");
        c1.setSurname("Nowak");
        c1.setType(1);
        BOOST_REQUIRE_EQUAL(c1.getDiscount(), 0.5);
        BOOST_TEST_MESSAGE(c1.info());
    }

BOOST_AUTO_TEST_SUITE_END()
