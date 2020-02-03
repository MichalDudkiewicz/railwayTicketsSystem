//
// Created by student on 26.01.2020.
//

#include "FileStream.h"
#include "CustomerManager.h"
#include "TrainManager.h"
#include "Train.h"
#include "Customer.h"
#include <vector>
#include <fstream>
#include <sstream>

FileException::FileException(const std::string &message, std::string path) : logic_error(message), path(std::move(path))
{}

std::string FileException::message() const
{
    std::ostringstream out;
    out << what() << " (path: '" << path << "')" << std::endl;
    return out.str();
}

void input::customerRepository(const std::string &path){
    std::ifstream customerRepositoryStream;
    customerRepositoryStream.open(path);
    if(!customerRepositoryStream.is_open()) throw FileException("File of the path doesn't exist",path);
    std::vector<std::string> row;
    unsigned int columnNumber = 0;
    std::string cell, employeeID;
    while (customerRepositoryStream.good()) {
        getline(customerRepositoryStream, cell, ',');
        row.push_back(cell);
        ++columnNumber;
        if (columnNumber == 2) {
            getline(customerRepositoryStream, cell, '\n');
            columnNumber = 0;
            customerPtr customer = std::make_shared<Customer>(row[0],row[1]);
            try{
                CustomerManager::getInstance().add(customer);
            }catch(CustomerTypeException &error)
            {
                throw FileException(error.message(),path);
            }
            row.clear();
        }
    }
    customerRepositoryStream.close();
}

void input::trainRepository(const std::string &path){
    std::ifstream trainRepositoryStream;
    trainRepositoryStream.open(path);
    if(!trainRepositoryStream.is_open()) throw FileException("File of the path doesn't exist",path);
    std::vector<std::string> row;
    unsigned int columnNumber = 0;
    std::string cell, employeeID;
    while (trainRepositoryStream.good()) {
        getline(trainRepositoryStream, cell, ',');
        row.push_back(cell);
        ++columnNumber;
        if (columnNumber == 2) {
            getline(trainRepositoryStream, cell, '\n');
            columnNumber = 0;
            trainPtr train = std::make_shared<Train>(row[0],stoi(row[1]));
            TrainManager::getInstance().add(train);
            row.clear();
        }
    }
    trainRepositoryStream.close();
}

void output::customerRepository(const std::string &path) {
    std::ofstream customerRepositoryStream;
    customerRepositoryStream.open(path);
    if(!customerRepositoryStream.is_open()) throw FileException("File of the path doesn't exist or You have no permission to write files",path);
    customerRepositoryStream << CustomerManager::getInstance();
    customerRepositoryStream.close();
}

void output::trainRepository(const std::string &path) {
    std::ofstream trainRepositoryStream;
    trainRepositoryStream.open(path);
    if(!trainRepositoryStream.is_open()) throw FileException("File of the path doesn't exist or You have no permission to write files",path);
    trainRepositoryStream << TrainManager::getInstance();
    trainRepositoryStream.close();
}