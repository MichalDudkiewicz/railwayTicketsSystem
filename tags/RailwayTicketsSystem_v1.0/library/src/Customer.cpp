//
// Created by student on 24.01.2020.
//

#include "Customer.h"
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "Student.h"
#include "Normal.h"
#include "Pensioner.h"
#include "Regular.h"
#include <iostream>
#include <sstream>

static const customerTypePtr student = std::make_shared<Student>();
static const customerTypePtr pensioner = std::make_shared<Pensioner>();
static const customerTypePtr normal = std::make_shared<Normal>();
static const customerTypePtr regular = std::make_shared<Regular>();

Customer::Customer(std::string name, std::string surname) : id(boost::uuids::random_generator()()), name(std::move(name)), surname(std::move(surname)), balance(0), type(normal)
{}

double Customer::getDiscount() const {
    return type->getDiscount();
}

void Customer::setBalance()
{
    balance += 1;
    if(balance == 3)
    {
        setType(3);
    }
}

void Customer::setType(unsigned int customerTypeID)
{
    switch(customerTypeID) {
        case 0:
            type = normal;
            break;
        case 1:
            type = student;
            break;
        case 2:
            type = pensioner;
            break;
        case 3:
            type = regular;
            break;
        default: //optional
            std::cout<<"exception";
    }
}

void Customer::setSurname(const std::string &lastName) {
    surname = lastName;
}

std::string Customer::info() const {
    std::ostringstream out;
    out << "Customer ID: " << id << std::endl;
    out << "Full name: " << name << " " << surname << std::endl;
    out << "Customer type: " << type->info() << std::endl;
    out << "Current balance: " << balance << std::endl;
    return out.str();
}

unsigned int Customer::getBalance() const {
    return balance;
}

std::string Customer::getID() const {
    return boost::uuids::to_string(id);
}
