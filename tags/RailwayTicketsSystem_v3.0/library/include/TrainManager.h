//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_TRAINMANAGER_H
#define RAILWAYTICKETSSYSTEM_TRAINMANAGER_H

#include <memory>
#include <vector>

class Train;
typedef std::shared_ptr<Train> trainPtr;

class TrainManager {
private:
    TrainManager()= default;
public:
    static TrainManager& getInstance();
    TrainManager(const TrainManager&)=delete;
    void operator=(const TrainManager&)=delete;
    static void add(const trainPtr &train);
    static void remove(unsigned int index);
    const std::vector<trainPtr>& getAll() const;
    trainPtr get(const std::string &id) const;
    std::string info() const;
};


#endif //RAILWAYTICKETSSYSTEM_TRAINMANAGER_H
