#include "buffer.hpp"
#include<fstream>
#include<iostream>

Buffer::Buffer() {}

void Buffer::writeFixedRecord(Record rec, std::ofstream& out) {
    std::string serialized_data = rec.serialize();

    out.write(serialized_data.c_str(), serialized_data.size());
};

Record Buffer::readFixedRecord(std::ifstream& in) {
    std::string data;
    std::getline(in, data);

    Record rec;
    rec.deserialize(data);

    return rec;
};
