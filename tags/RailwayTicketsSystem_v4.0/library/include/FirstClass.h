//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_FIRSTCLASS_H
#define RAILWAYTICKETSSYSTEM_FIRSTCLASS_H

#include "Ticket.h"

class FirstClass : public Ticket{
public:
    double getPrice() const override;
    std::string info() const override;
};


#endif //RAILWAYTICKETSSYSTEM_FIRSTCLASS_H
