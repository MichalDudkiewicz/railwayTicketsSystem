//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_REPOSITORY_H
#define RAILWAYTICKETSSYSTEM_REPOSITORY_H

#include <vector>
#include <memory>
#include <string>

template <class T>
class Repository
{
    virtual void add(const std::shared_ptr<T>&)=0;
    virtual void remove(unsigned int index)=0;
    virtual const std::vector<std::shared_ptr<T>>& getAll() const=0;
    virtual std::shared_ptr<T> get(const std::string&) const=0;
    virtual std::string info() const=0;
};

#endif //RAILWAYTICKETSSYSTEM_REPOSITORY_H
