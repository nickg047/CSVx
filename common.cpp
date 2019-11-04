/****************************
 * File: common.cpp         *
 * Author: Nick G           *
 * E-Mail: nickg047@sdf.org *
 * Version: 1               *
 * Status: Stable           *
 ****************************/
#include "common.h"

std::vector<std::string>* splitstr(const std::string& line, const char& delim){
    std::vector<std::string>* tokens = new std::vector<std::string>();

    std::string buffer = EMPTY_STRING;

    for(int i = 0; i < line.length(); i++){
        if(line.at(i) == delim){
            tokens->push_back(buffer);
            buffer = EMPTY_STRING;
        } else {
            buffer += line.at(i);
        }
    }

    if(!isEmptyStr(buffer)){
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
