#include "record.hpp"
#include "buffer.hpp"
#include <iostream>
#include <fstream>

int main(){
    std::string fileName = "Dados.txt";
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Error opening file Dados.txt for reading!" << std::endl;
        return 1;
    }

    Buffer delimiterBuffer("records_delimiter.txt");
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
        std::cout << record.name << "|" << record.surname << "|" << record.phone << "|" << record.birthDate << std::endl;
    }

    return 0;
}
