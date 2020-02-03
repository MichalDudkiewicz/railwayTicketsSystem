//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSFSOCIETY_CUSTOMERMANAGER_H
#define RAILWAYTICKETSFSOCIETY_CUSTOMERMANAGER_H

#include <memory>
#include <vector>
#include <fstream>

class Customer;
typedef std::shared_ptr<Customer> customerPtr;

class CustomerManager {
private:
    CustomerManager()= default;
public:
    static CustomerManager& getInstance();
    CustomerManager(const CustomerManager&)=delete;
    void operator=(const CustomerManager&)=delete;
    static void add(const customerPtr &customer);
    static void remove(unsigned int index);
    const std::vector<customerPtr>& getAll() const;
    customerPtr get(const std::string &id) const;
    std::string info() const;
    friend std::ofstream& operator<<(std::ofstream& output, const CustomerManager& manager);
};


#endif //RAILWAYTICKETSSYSTEM_CUSTOMERMANAGER_H
