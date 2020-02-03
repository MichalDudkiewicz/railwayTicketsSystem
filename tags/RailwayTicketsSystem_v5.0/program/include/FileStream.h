//
// Created by student on 26.01.2020.
//

#ifndef RAILWAYTICKETSSYSTEM_FILESTREAM_H
#define RAILWAYTICKETSSYSTEM_FILESTREAM_H

#include <string>
#include <stdexcept>

class FileException : public std::logic_error
{
private:
    std::string path;
public:
    explicit FileException(const std::string &message, std::string path);
    std::string message() const;
};

namespace input
{
    void customerRepository(const std::string&);
    void trainRepository(const std::string&);
}

namespace output
{
    void customerRepository(const std::string&);
    void trainRepository(const std::string&);
}


#endif //RAILWAYTICKETSSYSTEM_FILESTREAM_H
