//
// Created by student on 25.01.2020.
//

#include "Train.h"
#include <boost/test/unit_test.hpp>
#include <TrainRepository.h>


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(TrainRepositoryCase)
    {
        trainPtr t1 = std::make_shared<Train>("TGV1",100);
        trainPtr t2 = std::make_shared<Train>("TGV2",120);
        trainPtr t3 = std::make_shared<Train>("TGV3",300);
        trainPtr t4 = std::make_shared<Train>("TGV4",100);
        trainPtr t5 = std::make_shared<Train>("TGV5",50);
        TrainRepository allTrains;
        allTrains.add(t1);
        allTrains.add(t2);
        allTrains.add(t3);
        allTrains.add(t4);
        allTrains.add(t5);
        BOOST_TEST_MESSAGE(allTrains.info());
        BOOST_CHECK_EQUAL(allTrains.getAll().size(),5);
        BOOST_CHECK_EQUAL(allTrains.get(allTrains.getAll().back()->getName())->getName(),"TGV5");
        allTrains.remove(allTrains.get(allTrains.getAll().back()->getName()));
        BOOST_CHECK_EQUAL(allTrains.getAll().size(),4);
        BOOST_CHECK_EQUAL(allTrains.get(allTrains.getAll().back()->getName())->getName(),"TGV4");
    }

BOOST_AUTO_TEST_SUITE_END()
