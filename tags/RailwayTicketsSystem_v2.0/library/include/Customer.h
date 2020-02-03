//
// Created by student on 24.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_CUSTOMER_H
#define RAILWAYTICKETSSYSTEM_CUSTOMER_H

#include <boost/uuid/uuid.hpp>
#include <string>
#include <memory>

class CustomerType;
typedef std::shared_ptr<CustomerType> customerTypePtr;

class Customer {
private:
    boost::uuids::uuid id;
    std::string name;
    std::string surname;
    int balance;
    customerTypePtr type;
public:
    Customer(std::string name, std::string surname);
    double getDiscount() const;
    void setBalance();
    void setType(unsigned int customerTypeID);
    void setSurname(const std::string &surname);
    std::string info() const;
    unsigned int getBalance() const;
    std::string getID() const;
    std::string getFullName() const;
};


#endif //RAILWAYTICKETSSYSTEM_CUSTOMER_H
