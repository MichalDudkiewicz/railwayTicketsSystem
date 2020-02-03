//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_CUSTOMERREPOSITORY_H
#define RAILWAYTICKETSSYSTEM_CUSTOMERREPOSITORY_H

#include "Repository.h"
class Customer;
typedef std::shared_ptr<Customer> customerPtr;

class CustomerRepository : public Repository<Customer>{
private:
    std::vector<customerPtr> customers;
public:
    void add(const customerPtr &customer) override;
    void remove(const customerPtr &customer) override;
    const std::vector<customerPtr>& getAll() const override;
    const customerPtr& get(const std::string &id) const override;
    std::string info() const override;
};


#endif //RAILWAYTICKETSSYSTEM_CUSTOMERREPOSITORY_H
