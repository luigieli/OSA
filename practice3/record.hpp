#ifndef RECORD_HPP
#define RECORD_HPP

#include<string>

class Record{
public:
    int ID;
    std::string title;
    std::string author;
    int publishedYear;
    std::string gender;

    Record() = default;

    Record(int ID, std::string title, std::string author, int publishedYear, std::string gender);

    std::string packWithDelimiter() const;

    void unpackWithDelimiter(const std::string& data);
};

#endif
