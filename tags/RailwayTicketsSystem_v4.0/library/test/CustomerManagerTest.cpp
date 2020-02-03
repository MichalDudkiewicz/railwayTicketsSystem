//
// Created by student on 25.01.2020.
//

#include "Customer.h"
#include <boost/test/unit_test.hpp>
#include "CustomerManager.h"
#include <iostream>


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(CustomerManagerCase){
        BOOST_TEST_MESSAGE(CustomerManager::getInstance().info());
        BOOST_CHECK_EQUAL(CustomerManager::getInstance().getAll().size(),4);
        BOOST_CHECK_EQUAL(CustomerManager::getInstance().get(CustomerManager::getInstance().getAll()[1]->getID())->getFullName(),"Adam Nowak");
        CustomerManager::getInstance().remove(2);
        BOOST_CHECK_EQUAL(CustomerManager::getInstance().getAll().size(),3);
        BOOST_CHECK_EQUAL(CustomerManager::getInstance().get(CustomerManager::getInstance().getAll()[1]->getID())->getFullName(),"Jan Brzeczyszczykiewicz");
    }

BOOST_AUTO_TEST_SUITE_END()
