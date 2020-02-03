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
        CustomerRepository allCustomers;
        allCustomers.add(c1);
        allCustomers.add(c2);
        allCustomers.add(c3);
        allCustomers.add(c4);
        allCustomers.add(c5);
        BOOST_TEST_MESSAGE(allCustomers.info());
        BOOST_CHECK_EQUAL(allCustomers.getAll().size(),5);
        BOOST_CHECK_EQUAL(allCustomers.get(allCustomers.getAll().back()->getID())->getFullName(),"Elliot Alderson");
        allCustomers.remove(allCustomers.get(allCustomers.getAll().back()->getID()));
        BOOST_CHECK_EQUAL(allCustomers.getAll().size(),4);
        BOOST_CHECK_EQUAL(allCustomers.get(allCustomers.getAll().back()->getID())->getFullName(),"Tinky Winky");
    }

BOOST_AUTO_TEST_SUITE_END()
