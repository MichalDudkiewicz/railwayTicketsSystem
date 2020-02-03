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
public:
    void add(const trainPtr &customer) override;
    void remove(const trainPtr &customer) override;
    const std::vector<trainPtr>& getAll() const override;
    const trainPtr& get(const std::string &name) const override;
    std::string info() const override;
};


#endif //RAILWAYTICKETSSYSTEM_TRAINREPOSITORY_H
