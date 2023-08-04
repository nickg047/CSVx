/******************************
 * CSV Tokenizer              *
 * File: csvtoken.cpp         *
 * Author: Nick G             *
 * E-Mail: nickg047@gmail.com *
 * Version: 1                 *
 * Status: Stable             *
 ******************************/

#include <iostream>

#include "common.h"

#define VERSION 1

using namespace std;

void print_usage();

int main(int argc, char** argv){
    if(argc > 1){
        print_usage();
        return EXIT_CODE;
    }
    string currentline;
        
    while (getline(cin, currentline)){     
        vector<string>* tokens = splitstr(currentline, ',');

        // TODO

        delete tokens;
    }
    
    return EXIT_CODE;

    }

void print_usage(){
    cout << "CSV Tokenizer" << endl << "Version " << VERSION << endl << endl;
    cout << "Usage: " << endl;
    cout << "> csvtoken" << endl;
    cout << endl << "CSV Tokenizer will wait for input from stdin" << endl;
}