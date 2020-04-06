/******************************
 * File: csvjson.cpp          *
 * Author: Nick G             *
 * E-Mail: nickg047@gmail.com *
 * Version: 1                 *
 * Status: In Development     *
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

    // run here

    string currentline = EMPTY_STRING;
    vector<string>* headers = nullptr;
    bool first = true;

    while(getline(cin, currentline)){
	vector<string>* tokens = splitstr(currentline, ',');
	if(first){
            first = false;
	    headers = tokens;
	    continue;
	}


	
	// cleanup (not headers)
	delete tokens;
	tokens = nullptr;
    }

    delete headers;
    headers = nullptr;

    return 0;
}

void print_usage(){
    cout << "CSV to JSON Converter" << endl << "Version " << VERSION << endl << endl;
    cout << "Usage: " << endl;
    cout << "> csvjson" << endl;
    cout << endl << "CSV to JSON Converter will wait for input from stdin" << endl;
}
