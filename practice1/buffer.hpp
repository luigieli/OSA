#ifndef BUFFER_HPP
#define BUFFER_HPP

#include<string>
#include"record.hpp"

class Buffer{
public:
    Buffer();

    void writeFixedRecord(Record rec, std::ofstream& out);
    Record readFixedRecord(std::ifstream& in);
};

#endif
