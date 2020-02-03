//
// Created by student on 25.01.2020.
//

#include "Train.h"
#include <boost/test/unit_test.hpp>
#include "TrainManager.h"
#include <iostream>



BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(TrainManagerCase)
    {
        BOOST_TEST_MESSAGE(TrainManager::getInstance().info());
        BOOST_CHECK_EQUAL(TrainManager::getInstance().getAll().size(),4);
        BOOST_CHECK_EQUAL(TrainManager::getInstance().getAll().back()->getName(),"TGV4");
        TrainManager::getInstance().remove(4);
        BOOST_CHECK_EQUAL(TrainManager::getInstance().getAll().size(),3);
        BOOST_CHECK_EQUAL(TrainManager::getInstance().get(TrainManager::getInstance().getAll().back()->getName())->getName(),"TGV3");
    }

BOOST_AUTO_TEST_SUITE_END()