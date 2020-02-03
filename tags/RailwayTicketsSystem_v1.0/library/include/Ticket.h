//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_TICKET_H
#define RAILWAYTICKETSSYSTEM_TICKET_H

#include <string>

class Ticket {
public:
    virtual double getPrice() const=0;
    virtual std::string info() const=0;
    virtual ~Ticket()= default;
};


#endif //RAILWAYTICKETSSYSTEM_TICKET_H
