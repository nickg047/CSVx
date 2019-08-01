#include <iostream>
#include <vector>
#include <string>

#include "common.h"

using namespace std;

int main(){
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

