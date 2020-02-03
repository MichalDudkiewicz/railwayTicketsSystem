//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSFSOCIETY_BOOKINGMANAGER_H
#define RAILWAYTICKETSFSOCIETY_BOOKINGMANAGER_H

#include <memory>
#include <vector>
#include "BookingRepository.h"

class Booking;
typedef std::shared_ptr<Booking> bookingPtr;

class BookingManager {
private:
    BookingManager()= default;
    BookingRepository bookingRepository;
public:
    static BookingManager& getInstance();
    BookingManager(const BookingManager&)=delete;
    void operator=(const BookingManager&)=delete;
    void add(const bookingPtr &booking);
    void remove(unsigned int index);
    const std::vector<bookingPtr>& getAll() const;
    bookingPtr get(const std::string &id) const;
    std::string info() const;
};


#endif //RAILWAYTICKETSSYSTEM_CUSTOMERMANAGER_H
