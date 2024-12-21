#include "record.hpp"
#include<cstring>
#include<sstream>

Record::Record() : age(-1) {
    memset(name, '\0', sizeof(name));
}

Record::Record(int value, const std::string& string) : age(value) {
    memset(name, '\0', sizeof(name));
    strncpy(name, string.c_str(), sizeof(name) - 1);
};

std::string Record::serialize(){
    char buf[34];
    memset(buf, '\0', sizeof(buf));
    memcpy(buf, name, sizeof(name));
    memcpy(buf + sizeof(name), &age, sizeof(int));

    return std::string(buf, sizeof(buf));
};

void Record::deserialize(const std::string& buffer) {
    memcpy(name, buffer.c_str(), sizeof(name));
    memcpy(&age, buffer.c_str() + sizeof(name), sizeof(int));
    name[sizeof(name) - 1] = '\0';
}

