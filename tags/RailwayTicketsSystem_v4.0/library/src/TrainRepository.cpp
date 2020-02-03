//
// Created by student on 25.01.2020.
//

#include "TrainRepository.h"
#include "Train.h"
#include <sstream>
#include <algorithm>

void TrainRepository::add(const trainPtr &train) {
    trains.push_back(train);
    // exception
}

void TrainRepository::remove(unsigned int index) {
    trains.erase(trains.begin()+index-1);
}

const std::vector<trainPtr> &TrainRepository::getAll() const {
    return trains;
}

trainPtr TrainRepository::get(const std::string &name) const {
    for(const auto &train : trains){
        if(train -> getName() == name){
            return train;
        }
    }
    return trains[0];
    //exception
}

std::string TrainRepository::info() const {
    std::ostringstream out;
    unsigned int it = 1;
    out << "Train Repository: " << std::endl;
    for(const auto &train : trains){
        out << it << ":" << std::endl;
        out << train -> info() << std::endl;
        ++it;
    }
    return out.str();
}

TrainRepository &TrainRepository::getInstance() {
    static TrainRepository instance;
    return instance;
}

void TrainRepository::sortTrains(){
    std::sort(trains.begin(), trains.end(), compareTrainsCapacity());
}

bool compareTrainsCapacity::operator()(const trainPtr &t1, const trainPtr &t2) const {
    return (*t1) > (*t2);
}
