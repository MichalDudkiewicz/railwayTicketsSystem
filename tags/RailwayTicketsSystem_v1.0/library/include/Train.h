//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_TRAIN_H
#define RAILWAYTICKETSSYSTEM_TRAIN_H

#include <string>

class Train {
private:
    std::string name;
    int capacity;
    int seatsTaken;
public:
    Train(std::string name, int capacity);
    int getCapacity() const;
    int getFreeSpace() const;
    void addBooking();
    void removeBooking();
    const std::string& getName() const;
    std::string info() const;
};


#endif //RAILWAYTICKETSSYSTEM_TRAIN_H
