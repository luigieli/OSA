#include "record.hpp"
#include<cstring>
#include<sstream>
#include<string.h>

Record::Record(const std::string& name, const std::string& surname, const std::string& phone, const std::string& birthDate) 
    : name(name), surname(surname), phone(phone), birthDate(birthDate) {};

std::string Record::packWithDelimiter() const{
    return name + "|" + surname + "|" + phone + "|" + birthDate + "\n";
};

void Record::unpackWithDelimiter(const std::string& data) {
    std::stringstream ss(data);
    std::getline(ss, name, '|');
    std::getline(ss, surname, '|');
    std::getline(ss, phone, '|');
    std::getline(ss, birthDate, '\n');
}

std::string Record::packWithSizeDescriptor() const {
    std::string data = name + "|" + surname + "|" + phone + "|" + birthDate;
    int size = data.size() + sizeof(int);

    std::string packed;
    packed.resize(sizeof(int) + size);
    memcpy(&packed[0], &size, sizeof(int));
    memcpy(&packed[0] + sizeof(int), data.data(), data.size());
    return packed;
};

void Record::unpackWithSizeDescriptor(const std::string& data) {
    int size;
    memcpy(&size, data.data(), sizeof(int));
    std::string  content(data.data() + sizeof(int), size - sizeof(int));

    std::stringstream ss(content);
    std::getline(ss, name, '|');
    std::getline(ss, surname, '|');
    std::getline(ss, phone, '|');
    std::getline(ss, birthDate, '|');
}
