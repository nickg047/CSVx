/****************************
 * CSV Stringify            *
 * File: csvstr.cpp         *
 * Author: Nick G           *
 * E-Mail: nickg047@sdf.org *
 * Version: 1               *
 * Status: Stable           *
 ****************************/
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
        
        // insert quote
        for(auto it2 = tokens->begin(); it2 != tokens->end(); it2++){
            // print to stdout
            cout << "\'" << *it2 << (it2+1 == tokens->end()?"":",");
        }
        cout << endl;

        delete tokens;
    }
    
    return EXIT_CODE;
}

void print_usage(){
    cout << "CSV Stringify" << endl << "Version " << VERSION << endl << endl;
    cout << "Usage: " << endl;
    cout << "> csvstr" << endl;
    cout << endl << "CSV Stringify will wait for input from stdin" << endl;
}
