#ifndef RECORD_HPP
#define RECORD_HPP

#include<string>

class Record{
public:
    std::string name;
    std::string surname;
    std::string phone;
    std::string birthDate;

    Record() = default;

    Record(const std::string& name, const std::string& surname, const std::string& phone, const std::string& birthDate);

    std::string packWithDelimiter() const;

    void unpackWithDelimiter(const std::string& data);
    
    std::string packWithSizeDescriptor() const;

    void unpackWithSizeDescriptor(const std::string& data);
};

#endif
