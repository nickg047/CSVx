#include <iostream>
#include <vector>
#include <string>

#define EXIT_CODE 0

using namespace std;

void printusage();
vector<string>* splitstr(const string&, const char&);
vector<int>* getheaderindx(const string&, const string&);

int main(int argc, char** argv){
    bool indexflag = false;
    bool includelogic = false;
    string headercsv = "";
    
    // Process args
    for(int i = 1; i < argc; i++){
        string arg = string(argv[i]);
        if(arg.compare("--index") == 0){
            indexflag = true;
        } else if (arg.compare("--include") == 0){
            includelogic = true;
        } else {
            headercsv += arg;
        }
    }

    // make sure headers were specified otherwise this is just stupid
    if(headercsv.compare("") == 0){
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
                //cout << ctokens->at(ivec->at(i)) << (i+1 < ivec->size() ? "," : "\n" );
                toprint.push_back(ctokens->at(ivec->at(i)));
            }
        } else {
            // omit logic
            bool match = false;
            for(int i = 0; i < ctokens->size(); i++){
                for(int j = 0; j < ivec->size(); j++){
                    if(i == ivec->at(j)){
                        match = true;
                        //continue;
                        break;
                    }
                   // toprint.push_back(ctokens->at(i));
                }
                //toprint.push_back(ctokens->at(i));
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
    //cout << "--omit    : *DEFAULT* - Omit specified headers from output" << endl;
    cout << "--include : Include only the specified headers in output" << endl;
    cout << endl;
    cout << "Headers must be provided as a string of comma separated values" << endl;
}

vector<string>* splitstr(const string& line, const char& delim){
    vector<string>* tokens = new vector<string>();
    string buffer = "";
    for(int i = 0; i < line.size(); i++){
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

vector<int>* getheaderindx(const string& userline, const string& headersline){
    // userline is the line input by the user with the indexes to either omit or include
    // headersline is the header line from the file being transformed..

    vector<int>* hindx = new vector<int>();
    vector<string>* headers = splitstr(headersline, ',');
    vector<string>* columns = splitstr(userline, ',');

    for(int i = 0; i < columns->size(); i++){
        // cerr << "working on " << columns->at(i) << endl;
        for(int j = 0; j < headers->size(); j++){
            if(columns->at(i).compare(headers->at(j)) == 0){
                hindx->push_back(j);
                break;
            }
        }
    }

    delete headers;
    delete columns;
   
    return hindx;
    
    //cerr << "not implemented.. dis gonna fail foo.." << endl;
    //return nullptr;
}
