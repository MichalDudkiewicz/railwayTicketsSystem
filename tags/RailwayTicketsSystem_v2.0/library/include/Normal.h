//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_NORMAL_H
#define RAILWAYTICKETSSYSTEM_NORMAL_H

#include "CustomerType.h"

class Normal : public CustomerType{
public:
    double getDiscount() const override;
    std::string info() const override;
};


#endif //RAILWAYTICKETSSYSTEM_NORMAL_H
