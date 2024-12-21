#ifndef RECORD_HPP
#define RECORD_HPP

#include<string>

class Record{
public:
    char name[30];
    int age;


    Record();
    Record(int value, const std::string& str);

    std::string serialize();

    void deserialize(const std::string& buffer);
};

#endif
