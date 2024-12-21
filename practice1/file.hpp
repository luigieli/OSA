#ifndef FILE_HPP
#define FILE_HPP

#include<string>
#include<vector>
#include"buffer.hpp"

class File{
public:
    std::vector<Record> records;

    File();

    std::vector<Record> readRecordCSV(std::string file);

    void addFixedRecord(std::string file);

    std::vector<Record> readRecordFixed(std::string file);
};

#endif
