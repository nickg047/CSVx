#include <iostream>
#include <vector>
#include <string>

#include "common.h"

using namespace std;

void printusage();
vector<int>* getheaderindx(const string&, const string&);

int main(int argc, char** argv){
    bool indexflag = false;
    bool includelogic = false;
    string headercsv = EMPTY_STRING;
    
    // Process args
    for(int i = 1; i < argc; i++){
        string arg = string(argv[i]);
        if(areEqual(arg, "--index")){
            indexflag = true;
        } else if (areEqual(arg, "--include")){
            includelogic = true;
        } else {
            headercsv += arg;
        }
    }

    // make sure headers were specified otherwise this is just stupid
    if(areEqual(headercsv, "")){
        printusage();
        return EXIT_CODE;
    }

    string line;
    bool first = true;
    vector<int>* ivec = nullptr;
    vector<string>* ctokens = nullptr;
    while(getline(cin, line)){
        if(first){
            first = false;
            if(indexflag){
                // in index mode
                ivec = new vector<int>();
                vector<string>* strindxvec = splitstr(headercsv, ',');
                for(int i = 0; i < strindxvec->size(); i++){
                    ivec->push_back(stoi(strindxvec->at(i)));
                }
                delete strindxvec;
            } else {
                // not in index mode
                ivec = getheaderindx(headercsv, line);
            }

        }
        // print the columns that made the cut
        ctokens = splitstr(line, ',');
        vector<string> toprint;
        if(includelogic){
            for(int i = 0; i < ivec->size(); i++){
                toprint.push_back(ctokens->at(ivec->at(i)));
            }
        } else {
            // omit logic
            bool match = false;
            for(int i = 0; i < ctokens->size(); i++){
                for(int j = 0; j < ivec->size(); j++){
                    if(i == ivec->at(j)){
                        match = true;
                        break;
                    }
                }
                if(!match){
                    toprint.push_back(ctokens->at(i));
                } else {
                    match = false;
                }
            }

        }
        delete ctokens;

        for(int i = 0; i < toprint.size(); i++){
            cout << toprint.at(i) << (i+1 < toprint.size() ? "," : "\n");
        }
        
    }

    if(ivec != nullptr){
        delete ivec;
    }

    return EXIT_CODE;
}

void printusage(){
    cout << "CSV Strip" << endl << "Removes columns from csv output" << endl << endl;
    cout << "Usage: " << endl;
    cout << "csvstrpr [FLAGS] [HEADERS]" << endl << endl;
    cout << "Flags:" << endl;
    cout << "--index   : Specified headers are column numbers instead of header strings" << endl;
    cout << "--include : Include only the specified headers in output" << endl;
    cout << endl;
    cout << "Headers must be provided as a string of comma separated values" << endl;
}

vector<int>* getheaderindx(const string& userline, const string& headersline){
    // userline is the line input by the user with the indexes to either omit or include
    // headersline is the header line from the file being transformed..

    vector<int>* hindx = new vector<int>();
    vector<string>* headers = splitstr(headersline, ',');
    vector<string>* columns = splitstr(userline, ',');

    for(int i = 0; i < columns->size(); i++){
        for(int j = 0; j < headers->size(); j++){
            if(areEqual(columns->at(i), headers->at(j))){
                hindx->push_back(j);
                break;
            }
        }
    }

    delete headers;
    delete columns;
   
    return hindx;
}

