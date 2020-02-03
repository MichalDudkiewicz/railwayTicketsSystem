//
// Created by student on 25.01.2020.
//

#include "TrainRepository.h"
#include "Train.h"
#include <sstream>

void TrainRepository::add(const trainPtr &train) {
    trains.push_back(train);
    // exception
}

void TrainRepository::remove(const trainPtr &train) {
    unsigned int it = 0;
    for(auto &availableTrain : trains)
    {
        if(availableTrain->getName()==train->getName())
        {
            trains.erase(trains.begin()+it);
        }
        ++it;
    }
}

const std::vector<trainPtr> &TrainRepository::getAll() const {
    return trains;
}

const trainPtr &TrainRepository::get(const std::string &name) const {
    for(const auto &train : trains)
    {
        if(train -> getName() == name)
        {
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
    for(const auto &train : trains)
    {
        out << it << ":" << std::endl;
        out << train -> info() << std::endl;
        ++it;
    }
    return out.str();
}
