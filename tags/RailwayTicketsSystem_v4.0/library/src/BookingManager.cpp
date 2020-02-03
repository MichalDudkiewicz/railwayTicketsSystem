//
// Created by student on 25.01.2020.
//

#include "BookingManager.h"
#include "BookingRepository.h"



void BookingManager::add(const bookingPtr &booking) {
    bookingRepository.add(booking);
}

bookingPtr BookingManager::get(const std::string &id) const {
    return bookingRepository.get(id);
}

const std::vector<bookingPtr> &BookingManager::getAll() const {
    return bookingRepository.getAll();
}

void BookingManager::remove(unsigned int index) {
    bookingRepository.remove(index);
}

std::string BookingManager::info() const {
    return bookingRepository.info();
}

BookingManager &BookingManager::getInstance() {
    static BookingManager instance;
    return instance;
}


