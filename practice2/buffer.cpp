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

void Buffer::writeRecordWithSizeDescriptor(const Record& record) {
    std::ofstream outFile(fileName, std::ios::binary | std::ios::app);
    if(!outFile) {
        std::cerr << "Error opening file for writing: " << fileName << std::endl;
        return;
    }
    std::string packed = record.packWithSizeDescriptor();
    outFile.write(packed.data(), packed.size());
    outFile.close();
}

std::vector<Record> Buffer::readRecordWithSizeDescriptor(){
    std::ifstream inFile(fileName, std::ios::binary);
    if(!inFile) {
        std::cerr << "Error opening file for reading: " << fileName << std::endl;
        return {};
    }
    std::vector<Record> records;
    while (inFile.peek() != EOF) {
        int size;
        inFile.read(reinterpret_cast<char*>(&size), sizeof(int));
        if(inFile.gcount() < sizeof(int)) break;

        std::string buffer(size - sizeof(int), '\0');
        inFile.read(&buffer[0], size - sizeof(int));
        if(inFile.gcount() < size - sizeof(int)) break;

        Record record;
        record.unpackWithSizeDescriptor(std::string(reinterpret_cast<char*>(&size), sizeof(int)) + buffer);
        records.push_back(record);

    }
    inFile.close();
    return records;
}
