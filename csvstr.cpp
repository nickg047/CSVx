#include <iostream>
//#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string>* splitstr(string, char);
//void printUsage();

int main(/*int argc, char** argv*/){
    //ifstream infile;
   // if(argc == 2){
        // load file into memory
     //   infile.open(string(argv[1]));
   // }

    vector<string> lines;
    string currentline;
        
   /* if(argc == 2){
        while(getline(infile, currentline)){
            lines.push_back(currentline);
        }
        
        infile.close();
    } else {*/
        while (getline(cin, currentline)){
            lines.push_back(currentline);
        }
    //}

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

/*void printUsage(){
    cout << "Usage:" << endl;
    cout << "csvstr [FILE]" << endl;
}*/

vector<string>* splitstr(string line, char delim){
    vector<string>* tokens = new vector<string>();

    string buffer = "";
    for(int i = 0; i < line.length(); i++){
        if(line.at(i) == delim){
            tokens->push_back(buffer);
            buffer = "";
        } else {
            buffer += line.at(i);
        }
    }
    if(buffer.compare("") != 0){
        tokens->push_back(buffer);
    }


    return tokens;
}
