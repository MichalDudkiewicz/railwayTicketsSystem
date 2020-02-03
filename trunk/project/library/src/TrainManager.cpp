//
// Created by student on 25.01.2020.
//

#include "TrainManager.h"
#include "TrainRepository.h"
#include "Train.h"
#include <iostream>

void TrainManager::add(const trainPtr &train) {
    TrainRepository::getInstance().add(train);
}

trainPtr TrainManager::get(const std::string &id) const {
    return TrainRepository::getInstance().get(id);
}

const std::vector<trainPtr> &TrainManager::getAll() const {
    return TrainRepository::getInstance().getAll();
}

void TrainManager::remove(unsigned int index) {
    if(TrainRepository::getInstance().getAll()[index-1]->getFreeSpace()!=TrainRepository::getInstance().getAll()[index-1]->getCapacity())
        std::cout<<"exception";
    TrainRepository::getInstance().remove(index);
}

std::string TrainManager::info() const {
    return TrainRepository::getInstance().info();
}

TrainManager &TrainManager::getInstance() {
    static TrainManager instance;
    return instance;
}

std::ofstream &operator<<(std::ofstream &output, const TrainManager &manager) {
    for (const auto &train : manager.getAll()) {
        output << train->getName() << "," << train->getCapacity() << "," << std::endl;
    }
    return output;
}
