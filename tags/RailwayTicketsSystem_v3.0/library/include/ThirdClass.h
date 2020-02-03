//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_THIRDCLASS_H
#define RAILWAYTICKETSSYSTEM_THIRDCLASS_H

#include "Ticket.h"

class ThirdClass : public Ticket{
public:
    double getPrice() const override;
    std::string info() const override;
};


#endif //RAILWAYTICKETSSYSTEM_THIRDCLASS_H
