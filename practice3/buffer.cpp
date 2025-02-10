#include "buffer.hpp"
#include "record.hpp"
#include<fstream>
#include<iostream>

Buffer::Buffer( const std::string& fileName) : fileName(fileName) {}

void Buffer::writeRecordWithDelimiter(const Record& record) {
    std::ofstream outFile(fileName, std::ios::app);
    if(!outFile) {
        std::cerr << "Error opening file for writing: " << fileName << std::endl;
        return;
    }
    outFile << record.packWithDelimiter();
    outFile.close();
};

std::vector<Record> Buffer::readRecordWithDelimiter() {
    std::ifstream inFile(fileName);
    if(!inFile) {
        std::cerr << "Error opening file for reading: " << fileName << std::endl;
        return {};
    }

    std::vector<Record> records;
    std::string line;
    while (std::getline(inFile, line)) {
        Record record;
        record.unpackWithDelimiter(line);
        records.push_back(record);
    }
    inFile.close();
    return records;
};
