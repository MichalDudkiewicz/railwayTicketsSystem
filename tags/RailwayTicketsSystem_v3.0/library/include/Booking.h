//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_BOOKING_H
#define RAILWAYTICKETSSYSTEM_BOOKING_H

#include <memory>
#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include "Ticket.h"

class Customer;
class Train;
typedef std::shared_ptr<Train> trainPtr;
typedef std::shared_ptr<Customer> customerPtr;

class Booking {
private:
    boost::uuids::uuid id;
    customerPtr customer;
    trainPtr train;
    unsigned int numberOfStops;
    boost::local_time::local_date_time *currentTime;
    Ticket* ticket;
public:
    Booking(customerPtr  customer, trainPtr  train, unsigned int numberOfStops, unsigned int category);
    ~Booking();
    std::string info() const;
    double getTotalPrice() const;
    std::string getID() const;
    const customerPtr& getCustomer() const;
};


#endif //RAILWAYTICKETSSYSTEM_BOOKING_H
