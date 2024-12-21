#include "file.hpp"
#include<sstream>
#include<fstream>
#include<iostream>

File::File(){};


std::vector<Record> File::readRecordCSV(std::string fileName) {
    std::ifstream inFile(fileName);
    if (!inFile) {
        std::cerr << "Error opening CSV file" << fileName << " for reading!" << std::endl;
        return {};
    }
    std::string line;

    while(std::getline(inFile, line)) {
        std::stringstream entry(line);
        std::string name;
        int age;

        std::getline(entry, name, ',');
        entry >> age;

        records.push_back(Record(age, name));
    }
    
    inFile.close();

    return records;
}

void File::addFixedRecord(std::string file) {
    std::ofstream outFile(file, std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening bin file " << file << " for writing!" << std::endl;
        return;
    }

    Buffer buffer;
    for ( const auto& rec : records) {
        buffer.writeFixedRecord(rec, outFile);
    }
    
    outFile.close();
}

std::vector<Record> File::readRecordFixed(std::string file) {
    std::ifstream inFile(file, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening bin file " << file << " for reading!" << std::endl;
        return {};
    }

    std::vector<Record> readRecords;
    Buffer buffer;

    // Read all records from the binary file
    while (inFile.peek() != EOF ) {
        Record rec = buffer.readFixedRecord(inFile);
        readRecords.push_back(rec);
    }

    inFile.close();
    return readRecords;
}
