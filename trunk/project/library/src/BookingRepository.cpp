//
// Created by student on 25.01.2020.
//

#include "BookingRepository.h"
#include "Booking.h"
#include "Customer.h"
#include "Train.h"
#include <sstream>

void BookingRepository::add(const bookingPtr &booking) {
    booking -> getTrain() -> addBooking();
    booking -> getCustomer() -> setBalance();
    bookings.push_back(booking);
    booking -> getCustomer() -> addBooking(booking);
    // exception
}

void BookingRepository::remove(unsigned int index) {
    bookings[index - 1] -> getTrain() -> removeBooking();
    bookings[index - 1]->getCustomer()->removeBooking(bookings[index - 1]);
    bookings.erase(bookings.begin()+index-1);
}

const std::vector<bookingPtr> &BookingRepository::getAll() const {
    return bookings;
}

bookingPtr BookingRepository::get(const std::string &id) const {
    for(const auto &booking : bookings)
    {
        if(booking -> getID() == id)
        {
            return booking;
        }
    }
    return bookings[0];
    //exception
}

std::string BookingRepository::info() const {
    std::ostringstream out;
    unsigned int it = 1;
    out << "Booking Repository: " << std::endl;
    for(const auto &booking : bookings)
    {
        out << it << ":" << std::endl;
        out << booking -> info() << std::endl;
        ++it;
    }
    return out.str();
}
