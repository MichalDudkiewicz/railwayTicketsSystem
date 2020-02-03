//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_CUSTOMERTYPE_H
#define RAILWAYTICKETSSYSTEM_CUSTOMERTYPE_H

#include <string>

class CustomerType {
public:
    virtual double getDiscount() const=0;
    virtual std::string info() const=0;
    virtual ~CustomerType()= default;
};


#endif //RAILWAYTICKETSSYSTEM_CUSTOMERTYPE_H
