//
// Created by student on 25.01.2020.
//

#include "CustomerRepository.h"
#include "Customer.h"
#include <sstream>

void CustomerRepository::add(const customerPtr &customer) {
    customers.push_back(customer);
    // exception
}

void CustomerRepository::remove(const customerPtr &customer) {
    unsigned int it = 0;
    for(auto &availableCustomer : customers)
    {
        if(availableCustomer->getID()==customer->getID())
        {
            customers.erase(customers.begin()+it);
        }
        ++it;
    }
}

const std::vector<customerPtr> &CustomerRepository::getAll() const {
    return customers;
}

const customerPtr &CustomerRepository::get(const std::string &id) const {
    for(const auto &customer : customers)
    {
        if(customer -> getID() == id)
        {
            return customer;
        }
    }
    return customers[0];
    //exception
}

std::string CustomerRepository::info() const {
    std::ostringstream out;
    unsigned int it = 1;
    out << "Customer Repository: " << std::endl;
    for(const auto &customer : customers)
    {
        out << it << ":" << std::endl;
        out << customer -> info() << std::endl;
        ++it;
    }
    return out.str();
}
