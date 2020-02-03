//
// Created by student on 25.01.2020.
//

#include "Customer.h"
#include <boost/test/unit_test.hpp>
#include <CustomerRepository.h>


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(CustomerRepositoryCase)
    {
        customerPtr c1 = std::make_shared<Customer>("Adam","Sandler");
        customerPtr c2 = std::make_shared<Customer>("Adam","Nowak");
        customerPtr c3 = std::make_shared<Customer>("Jan","Brzeczyszczykiewicz");
        customerPtr c4 = std::make_shared<Customer>("Tinky","Winky");
        customerPtr c5 = std::make_shared<Customer>("Elliot","Alderson");
        CustomerRepository::getInstance().add(c1);
        CustomerRepository::getInstance().add(c2);
        CustomerRepository::getInstance().add(c3);
        CustomerRepository::getInstance().add(c4);
        CustomerRepository::getInstance().add(c5);
        BOOST_TEST_MESSAGE(CustomerRepository::getInstance().info());
        BOOST_CHECK_EQUAL(CustomerRepository::getInstance().getAll().size(),5);
        BOOST_CHECK_EQUAL(CustomerRepository::getInstance().get(CustomerRepository::getInstance().getAll().back()->getID())->getFullName(),"Elliot Alderson");
        CustomerRepository::getInstance().remove(CustomerRepository::getInstance().getAll().size());
        BOOST_CHECK_EQUAL(CustomerRepository::getInstance().getAll().size(),4);
        BOOST_CHECK_EQUAL(CustomerRepository::getInstance().get(CustomerRepository::getInstance().getAll().back()->getID())->getFullName(),"Tinky Winky");
    }

BOOST_AUTO_TEST_SUITE_END()
