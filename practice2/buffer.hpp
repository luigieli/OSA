#ifndef BUFFER_HPP
#define BUFFER_HPP

#include"record.hpp"
#include<string>
#include<vector>

class Buffer{
private:
    std::string fileName;
public:
    Buffer(const std::string& fileName);

    void writeRecordWithDelimiter(const Record& record);

    std::vector<Record> readRecordWithDelimiter();

    std::vector<Record> writeRecordWithSizeDescriptor();

    std::vector<Record> readRecordWithSizeDescriptor();
};

#endif