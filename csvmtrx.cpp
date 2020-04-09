/******************************
 * CSV Metrics                *
 * File: csvmtrx.cpp          *
 * Author: Nick G             *
 * E-Mail: nickg047@gmail.com *
 * Version: 1                 *
 * Status: Stable             * 
 ******************************/
#include <iostream>

#include "common.h"

#define VERSION 1

using namespace std;

pair<string, int>* findvecpair(const string&, vector<pair<string, int>*>*);
void printUsage();

int main(int argc, char** argv){
    if(argc > 1){
        printUsage();
        return EXIT_CODE;
    }
    
    vector<string> headers;
    vector<pair<string, int>*>** metrics = nullptr;
    string cline = EMPTY_STRING;
    int longest = 0; // track the deepest vector for padding output
    bool first = true;
    while(getline(cin, cline)){
        vector<string>* linetoks = splitstr(cline, ',');
        if(first){
            first = false;
            headers = vector<string>(*linetoks);
            metrics = new vector<pair<string, int>*>* [headers.size()];
            for(int i = 0; i < headers.size(); i++){
                metrics[i] = new vector<pair<string, int>*> ();
            }
        } else {
            // pull metrics line by line
            for(int i = 0; i < linetoks->size(); i++){
                pair<string, int>* current = findvecpair(linetoks->at(i), metrics[i]);
                if(current == nullptr){
                    current = new pair<string, int>();
                    current->second = 0;
                    metrics[i]->push_back(current);
                    if(metrics[i]->size() > longest){
                        longest = metrics[i]->size();
                    }
                }
                
                current->first = linetoks->at(i);
                current->second++;
            }
        }

        if(linetoks != nullptr){
            delete linetoks;
        }
    }

    // print metrics
    for(int i = 0; i < headers.size(); i++){
        cout << headers.at(i) << (i+1 < headers.size() ? ",COUNT," : ",COUNT");
    }
    cout << endl;

    for(int i = 0; i < longest; i++){
        for (int j = 0; j < headers.size(); j++){
            if(metrics[j] != nullptr){
                if(i < metrics[j]->size() && metrics[j]->at(i) != nullptr){
                    cout << metrics[j]->at(i)->first << ",";
                    cout << metrics[j]->at(i)->second << (j+1 < headers.size() ? "," : EMPTY_STRING);
                } else {
                    cout << (j+1 < headers.size() ? ",," : ",");
                }
            } else {
                cout << (j+1 < headers.size() ? ",," : ",");
            }
        }
        cout << endl;
    }


    // memory management
    if(metrics != nullptr){
        for(int i = 0; i < headers.size(); i++){
            vector<pair<string, int>*>* cvec = metrics[i];
            if(cvec != nullptr){
                for(auto it = cvec->begin(); it != cvec->end(); it++){
                    if(*it != nullptr){
                        delete *it;
                    }
                }

                delete cvec;
            }
        }

        delete [] metrics;
    }
    
    return EXIT_CODE;
}

pair<string, int>* findvecpair(const string& key, vector<pair<string, int>*>* vec){
    pair<string, int>* result = nullptr;
    if(vec != nullptr){
        for(int i = 0; i < vec->size(); i++){
            if(vec->at(i) != nullptr){
                if(areEqual(vec->at(i)->first, key)){
                    result = vec->at(i);
                    break;
                }
            }
        }
    }

    return result;
}

void printUsage(){
    cout << "CSV Metrics" << endl << "Version " << VERSION << endl << endl;
    cout << "Usage:" << endl;
    cout << "> csvmtrx" << endl;
    cout << endl << "Program will wait for input from stdin" << endl;
}
