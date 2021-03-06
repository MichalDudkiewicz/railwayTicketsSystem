//
// Created by student on 25.01.2020.
//

#include <iostream>
#include <sstream>
#include "Train.h"

FullTrainException::FullTrainException(const std::string &message) : logic_error(message)
{}

std::string FullTrainException::message() const{
    std::ostringstream out;
    out << "ERROR 102: " << what() << std::endl;
    return out.str();
}

EmptyTrainException::EmptyTrainException(const std::string &message) : logic_error(message)
{}

std::string EmptyTrainException::message() const{
    std::ostringstream out;
    out << "ERROR 101: " << what() << std::endl;
    return out.str();
}

Train::Train(std::string name, int capacity) : name(std::move(name)), capacity(capacity), seatsTaken(0)
{}

int Train::getCapacity() const{
    return capacity;
}

int Train::getFreeSpace() const {
    return capacity - seatsTaken;
}

void Train::addBooking(){
    if(getFreeSpace()>0){
        seatsTaken += 1;
    }
    else{
        throw FullTrainException("I am sorry, but the train is full and no more bookings are available");
    }
}

void Train::removeBooking(){
    if(seatsTaken > 0){
        seatsTaken -= 1;
    }
    else{
        std::cout << "exception";
    }
}

const std::string& Train::getName() const{
    return name;
}

std::string Train::info() const {
    std::ostringstream out;
    out << "Train name: " << name << std::endl;
    out << "Capacity: " << capacity << std::endl;
    out << "Free space: " << getFreeSpace() << std::endl;
    return out.str();
}

bool Train::operator>(Train &train) const {
    return this->capacity > train.capacity;
}
