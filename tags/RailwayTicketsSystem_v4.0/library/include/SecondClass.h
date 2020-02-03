//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_SECONDCLASS_H
#define RAILWAYTICKETSSYSTEM_SECONDCLASS_H

#include "Ticket.h"

class SecondClass : public Ticket{
public:
    double getPrice() const override;
    std::string info() const override;
};


#endif //RAILWAYTICKETSSYSTEM_SECONDCLASS_H
