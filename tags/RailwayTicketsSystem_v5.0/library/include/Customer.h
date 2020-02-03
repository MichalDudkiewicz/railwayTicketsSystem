//
// Created by student on 24.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_CUSTOMER_H
#define RAILWAYTICKETSSYSTEM_CUSTOMER_H

#include <boost/uuid/uuid.hpp>
#include <string>
#include <memory>
#include <vector>

class CustomerType;
typedef std::shared_ptr<CustomerType> customerTypePtr;
class Booking;
typedef std::shared_ptr<Booking> bookingPtr;

class CustomerTypeException : public std::logic_error{
public:
    explicit CustomerTypeException(const std::string &message);
    std::string message() const;
};

class Customer {
private:
    boost::uuids::uuid id;
    std::string name;
    std::string surname;
    int balance;
    customerTypePtr type;
    std::vector<bookingPtr> myBookings{};
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
    const std::vector<bookingPtr>& getMyBookings() const;
    void addBooking(const bookingPtr& booking);
    void removeBooking(const bookingPtr& booking);
    const std::string& getName() const;
    const std::string& getSurname() const;
};


#endif //RAILWAYTICKETSSYSTEM_CUSTOMER_H
