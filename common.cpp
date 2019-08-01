#include "common.h"

std::vector<std::string>* splitstr(const std::string& line, const char& delim){
    std::vector<std::string>* tokens = new std::vector<std::string>();

    std::string buffer = "";

    for(int i = 0; i < line.length(); i++){
        if(line.at(i) == delim){
            tokens->push_back(buffer);
            buffer = "";
        } else {
            buffer += line.at(i);
        }
    }

    if(buffer.compare("") != 0){
        tokens->push_back(buffer);
    }


    return tokens;
}

bool areEqual(const std::string& one, const std::string& two){
    return one.compare(two) == 0;
}

bool isEmptyStr(const std::string& str){
    return areEqual(str, EMPTY_STRING);
}
