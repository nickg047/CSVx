/****************************
 * File: csvjson.cpp        *
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

    if(argc <= 1){
        print_usage();
        return EXIT_CODE;
    } else {
        for(int i = 1; i < argc; i++){
            string arg = string(argv[i]);
            if(areEqual(arg, "--help") || areEqual(arg, "-h")){
                print_usage();
            } // else if
        }
    }

    // run here

    return 0;
}

void print_usage(){
    cout << "USAGE" << endl;
}
