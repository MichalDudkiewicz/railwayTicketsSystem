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
        TrainRepository::getInstance().add(t1);
        TrainRepository::getInstance().add(t2);
        TrainRepository::getInstance().add(t3);
        TrainRepository::getInstance().add(t4);
        TrainRepository::getInstance().add(t5);
        BOOST_TEST_MESSAGE(TrainRepository::getInstance().info());
        BOOST_CHECK_EQUAL(TrainRepository::getInstance().getAll().size(),5);
        BOOST_CHECK_EQUAL(TrainRepository::getInstance().get(TrainRepository::getInstance().getAll().back()->getName())->getName(),"TGV5");
        TrainRepository::getInstance().remove(TrainRepository::getInstance().getAll().size());
        BOOST_CHECK_EQUAL(TrainRepository::getInstance().getAll().size(),4);
        BOOST_CHECK_EQUAL(TrainRepository::getInstance().get(TrainRepository::getInstance().getAll().back()->getName())->getName(),"TGV4");
    }

BOOST_AUTO_TEST_SUITE_END()
