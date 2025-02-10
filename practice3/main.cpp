#include "record.hpp"
#include "buffer.hpp"
#include <iostream>
#include <fstream>

int main(){
    std::string fileName = "booksDummy.csv";
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;
    }

    Buffer delimiterBuffer("bookset.txt");
    std::string line;
    std::getline(inputFile, line);

    while (std::getline(inputFile, line)) {
        Record record;
        record.unpackWithDelimiter(line);
        delimiterBuffer.writeRecordWithDelimiter(record);
    }
    inputFile.close();

    auto recordsWithDelimiter = delimiterBuffer.readRecordWithDelimiter();
    for (const auto& record : recordsWithDelimiter) {
        std::cout << record.ID << "|" << record.title << "|" << record.author << "|" << record.publishedYear << "|" << record.gender << std::endl;
    }

    return 0;
}
