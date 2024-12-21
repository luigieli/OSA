#include "file.hpp"
#include<iostream>

int main(){
    File file;
    std::string output;
    int i = 1;
    std::vector<Record> out;

    std::vector<std::string> csvFiles = {
    "./files/Nomes_Idades_1.csv",
    "./files/Nomes_Idades_2.csv",
    "./files/Nomes_Idades_3.csv",
    "./files/Nomes_Idades_4.csv",
    "./files/Nomes_Idades_5.csv"
    };

    for (std::string dirFile : csvFiles){
        output = "./files/fileout/OutPut-" + std::to_string(i++);

        file.readRecordCSV(dirFile);
        file.addFixedRecord(output + ".bin");

       out = file.readRecordFixed(output + ".bin");
       for ( Record rec : out){
           std::cout << rec.name << "," << rec.age << std::endl;
       }
       std::cout << std::endl;

       file.records.clear();
    }

    return 0;
}
