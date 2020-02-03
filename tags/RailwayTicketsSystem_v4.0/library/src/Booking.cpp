//
// Created by student on 25.01.2020.
//

#include "Booking.h"
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sstream>
#include "Customer.h"
#include "Train.h"
#include "FirstClass.h"
#include "SecondClass.h"
#include "ThirdClass.h"

static boost::local_time::time_zone_ptr timeZone(new boost::local_time::posix_time_zone("CET+0"));

BookingCategoryException::BookingCategoryException(const std::string &message) : logic_error(message){}

std::string BookingCategoryException::message() const{
    std::ostringstream out;
    out << "ERROR 104: " << what() << std::endl;
    return out.str();
}

Booking::Booking(customerPtr customer, trainPtr train, unsigned int numberOfStops, unsigned int category) : id(boost::uuids::random_generator()()), customer(std::move(customer)), train(std::move(train)), numberOfStops(numberOfStops), currentTime(new boost::local_time::local_date_time(boost::posix_time::second_clock::local_time(), timeZone)){
    switch(category){
        case 1:
            ticket = new FirstClass;
            break;
        case 2:
            ticket = new SecondClass;
            break;
        case 3:
            ticket = new ThirdClass;
            break;
        default:
            throw BookingCategoryException("There is no such class in train...");
    }
}

Booking::~Booking(){
    delete ticket;
    delete currentTime;
}

std::string Booking::info() const{
    std::ostringstream out;
    out << "Booking nr " << id << std::endl;
    out << "made by: " << std::endl << customer -> info() << std::endl;
    out << "train: " << std::endl << train -> info() << std::endl;
    out << "number of stops: " << numberOfStops << std::endl;
    out << "class: " << ticket -> info() << std::endl;
    out << "total price: " << getTotalPrice() << std::endl;
    out << "time: " << *currentTime << std::endl;
    return out.str();
}

double Booking::getTotalPrice() const {
    return numberOfStops*ticket->getPrice()*(1 - customer->getDiscount());
}

std::string Booking::getID() const {
    return boost::uuids::to_string(id);
}

const customerPtr &Booking::getCustomer() const {
    return customer;
}

const trainPtr &Booking::getTrain() const {
    return train;
}


