#include <iostream>
#include <vector>
#include <string>

#include "common.h"

using namespace std;

int main(){
    vector<string> lines;
    string currentline;
        
    while (getline(cin, currentline)){
        lines.push_back(currentline);
    }
    
    // tokenize line by line
    for(auto it = lines.begin(); it != lines.end(); it++){
        vector<string>* tokens = splitstr(*it, ',');

        // insert quote
        for(auto it2 = tokens->begin(); it2 != tokens->end(); it2++){
            // print to stdout
            cout << "\'" << *it2 << (it2+1 == tokens->end()?"":",");
        }
        cout << endl;

        // free memory
        delete tokens;
    }

    return 0;
}

