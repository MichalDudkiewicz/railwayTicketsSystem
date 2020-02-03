//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_BOOKINGREPOSITORY_H
#define RAILWAYTICKETSSYSTEM_BOOKINGREPOSITORY_H

#include "Repository.h"
class Booking;
typedef std::shared_ptr<Booking> bookingPtr;

class BookingRepository : public Repository<Booking>{
private:
    std::vector<bookingPtr> bookings;
public:
    void add(const bookingPtr &customer) override;
    void remove(const bookingPtr &customer) override;
    const std::vector<bookingPtr>& getAll() const override;
    const bookingPtr& get(const std::string &id) const override;
    std::string info() const override;
};


#endif //RAILWAYTICKETSSYSTEM_BOOKINGREPOSITORY_H
