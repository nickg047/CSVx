/****************************
 * Row Strip                *
 * File: rowstrpr.cpp       *
 * Author: Nick G           *
 * E-Mail: nickg047@sdf.org *
 * Version: 1               *
 * Status: Stable           *
 ****************************/
#include <iostream>

#include "common.h"

#define VERSION 1

using namespace std;

void printusage();
bool vectorsearch(int, vector<int>*);

int main(int argc, char** argv){
    string currentline;
    string headercsv = EMPTY_STRING;

    // process input args
    for(int i = 1; i < argc; i++){
        string arg = string(argv[i]);
        if(areEqual(arg, "--version") || areEqual(arg, "--help")){
            printusage();
            return EXIT_CODE;
        } else {
            headercsv += arg;
        }
    }

    // makesure row indexes were specified otherwise this is just stupid
    if (areEqual(headercsv, "")){
        printusage();
        return EXIT_CODE;
    }

    // create index vector
    vector<string>* strindxvec = splitstr(headercsv, ',');
    vector<int>* ivec = new vector<int>();
    for(int i = 0; i < strindxvec->size(); i++){
        ivec->push_back(stoi(strindxvec->at(i)));
    }
    delete strindxvec;
    strindxvec = nullptr;
    
    int count = 0;
    while (getline(cin, currentline)){
        if(vectorsearch(count, ivec)){
            count++;
            continue;
        }
        cout << currentline << endl;
        count++;
    }

    delete ivec;

    return EXIT_CODE;
}

void printusage(){
    cout << "Row Stripper" << endl << "Version " << VERSION << endl << "Removes lines from output" << endl << endl;
    cout << "Usage: " << endl;
    cout << "rowstrpr [INDEXES]" << endl << endl;
    cout << "Indexes must be provided as a string of comma separated numbers" << endl;
}

bool vectorsearch(int element, vector<int>* vec){
    for(auto it = vec->begin(); it != vec->end(); it++){
        if(*it == element){
            return true;
        }
    }
    return false;
}
