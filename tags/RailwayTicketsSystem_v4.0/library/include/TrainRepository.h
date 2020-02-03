//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_TRAINREPOSITORY_H
#define RAILWAYTICKETSSYSTEM_TRAINREPOSITORY_H

#include "Repository.h"
class Train;
typedef std::shared_ptr<Train> trainPtr;

class TrainRepository : public Repository<Train>{
private:
    std::vector<trainPtr> trains;
    TrainRepository()= default;
public:
    static TrainRepository& getInstance();
    TrainRepository(const TrainRepository&)=delete;
    void operator=(const TrainRepository&)=delete;
    void add(const trainPtr &customer) override;
    void remove(unsigned int index) override;
    const std::vector<trainPtr>& getAll() const override;
    trainPtr get(const std::string &name) const override;
    std::string info() const override;
    void sortTrains();
};

struct compareTrainsCapacity{
    bool operator()(const trainPtr&, const trainPtr&) const;
};


#endif //RAILWAYTICKETSSYSTEM_TRAINREPOSITORY_H
