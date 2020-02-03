//
// Created by student on 25.01.2020.
//

#include "CustomerManager.h"
#include "CustomerRepository.h"
#include "Customer.h"
#include <iostream>

void CustomerManager::add(const customerPtr &customer) {
    CustomerRepository::getInstance().add(customer);
}

customerPtr CustomerManager::get(const std::string &id) const {
    return CustomerRepository::getInstance().get(id);
}

const std::vector<customerPtr> &CustomerManager::getAll() const {
    return CustomerRepository::getInstance().getAll();
}

void CustomerManager::remove(unsigned int index) {
    if(!CustomerRepository::getInstance().getAll()[index - 1]->getMyBookings().empty())
        std::cout<<"exception";
    CustomerRepository::getInstance().remove(index);
}

std::string CustomerManager::info() const {
    return CustomerRepository::getInstance().info();
}

CustomerManager &CustomerManager::getInstance() {
    static CustomerManager instance;
    return instance;
}


