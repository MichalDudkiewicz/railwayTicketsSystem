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
    CustomerRepository()= default;
public:
    static CustomerRepository& getInstance();
    CustomerRepository(const CustomerRepository&)=delete;
    void operator=(const CustomerRepository&)=delete;
    void add(const customerPtr &customer) override;
    void remove(unsigned int index) override;
    const std::vector<customerPtr>& getAll() const override;
    customerPtr get(const std::string &id) const override;
    std::string info() const override;
};


#endif //RAILWAYTICKETSSYSTEM_CUSTOMERREPOSITORY_H
