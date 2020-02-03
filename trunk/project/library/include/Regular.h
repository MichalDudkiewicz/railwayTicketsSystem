//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_REGULAR_H
#define RAILWAYTICKETSSYSTEM_REGULAR_H

#include "CustomerType.h"

class Regular : public CustomerType{
public:
    double getDiscount() const override;
    std::string info() const override;
};


#endif //RAILWAYTICKETSSYSTEM_REGULAR_H
