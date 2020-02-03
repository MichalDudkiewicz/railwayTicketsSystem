//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_PENSIONER_H
#define RAILWAYTICKETSSYSTEM_PENSIONER_H

#include "CustomerType.h"

class Pensioner : public CustomerType{
public:
    double getDiscount() const override;
    std::string info() const override;
};


#endif //RAILWAYTICKETSSYSTEM_PENSIONER_H
