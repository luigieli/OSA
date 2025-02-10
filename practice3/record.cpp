#include "record.hpp"
#include<cstring>
#include<sstream>
#include<string.h>

Record::Record(int ID, std::string title, std::string author, int publishedYear, std::string gender)
    : ID(ID), title(title), author(author), publishedYear(publishedYear), gender(gender) {};

std::string Record::packWithDelimiter() const{
    return std::to_string(ID) + "|" + title + "|" + author + "|" + std::to_string(publishedYear) + "|" + gender + "\n";
};

void Record::unpackWithDelimiter(const std::string& data) {
    std::stringstream ss(data);
    ss >> ID;
    ss.ignore(1,';');
    std::getline(ss, title, ';');
    std::getline(ss, author, ';');
    ss >> publishedYear;
    ss.ignore(1,';');
    std::getline(ss, gender, '\n');
}
