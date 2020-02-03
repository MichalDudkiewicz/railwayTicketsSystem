//
// Created by student on 25.01.2020.
//

//
// Created by student on 25.01.2020.
//

#include "Train.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(TrainCreationCase)
    {
        Train t1("TGV11", 3);
        BOOST_TEST_MESSAGE(t1.info());
        BOOST_REQUIRE_EQUAL(t1.getFreeSpace(),t1.getCapacity());
        BOOST_REQUIRE_EQUAL(t1.getName(),"TGV11");
        BOOST_REQUIRE_EQUAL(t1.getCapacity(),3);
    }

    BOOST_AUTO_TEST_CASE(TrainBookingCase)
    {
        Train t1("TGV11", 3);
        t1.addBooking();
        BOOST_TEST_MESSAGE(t1.info());
        BOOST_REQUIRE_EQUAL(t1.getFreeSpace(),2);
        t1.removeBooking();
        BOOST_REQUIRE_EQUAL(t1.getFreeSpace(),t1.getCapacity());
    }

BOOST_AUTO_TEST_SUITE_END()
