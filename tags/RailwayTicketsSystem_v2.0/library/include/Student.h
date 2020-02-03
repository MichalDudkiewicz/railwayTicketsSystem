//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_STUDENT_H
#define RAILWAYTICKETSSYSTEM_STUDENT_H

#include "CustomerType.h"

class Student : public CustomerType{
public:
    double getDiscount() const override;
    std::string info() const override;
};


#endif //RAILWAYTICKETSSYSTEM_STUDENT_H
