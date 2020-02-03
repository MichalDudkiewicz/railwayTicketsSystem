//
// Created by student on 25.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_TRAIN_H
#define RAILWAYTICKETSSYSTEM_TRAIN_H

#include <string>
#include <stdexcept>

class FullTrainException : public std::logic_error{
public:
    explicit FullTrainException(const std::string &message);
    std::string message() const;
};

class EmptyTrainException : public std::logic_error{
public:
    explicit EmptyTrainException(const std::string &message);
    std::string message() const;
};

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
    bool operator>(Train &train) const;
};


#endif //RAILWAYTICKETSSYSTEM_TRAIN_H
