#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string>* splitstr(const string&, const char&);
void printUsage();

int main(int argc, char** argv){
    vector<string>* searchHeaders = nullptr;
    vector<string>* searchValues = nullptr;
    vector<string>* csvHeaders = nullptr;
    vector<pair<int, string>*>* lookupVec = nullptr; 

    // process launch args
    for(int i = 1; i < argc; i++){

        string current = string(argv[i]);
        if(current.compare("-h") == 0){
            if(i+1 < argc){
                searchHeaders = splitstr(string(argv[++i]), ',');
            } else {
                printUsage();
                return 0;
            }
        } else if (current.compare("-v") == 0){
            if(i+1 < argc){
                searchValues = splitstr(string(argv[++i]), ',');
            } else {
                searchValues = new vector<string>();
                searchValues->push_back("");
            }
        } else if (current.compare("-help") == 0){
            printUsage();
            return 0;
        }
    }

    if(searchHeaders == nullptr || searchValues == nullptr){
        printUsage();
        return 0;
    }

    // get input from stdin and run filter
    bool first = true;
    string currentline = "";
    while(getline(cin, currentline)){
        if(first){
            first = false;
            csvHeaders = splitstr(currentline, ',');
            cout << currentline << endl;
            // determine header indexes
            lookupVec = new vector<pair<int, string>*>();

            for(int i = 0; i < searchHeaders->size(); i++){
                for(int j = 0; j < csvHeaders->size(); j++){
                    if((*searchHeaders)[i].compare((*csvHeaders)[j]) == 0){
                        pair<int, string>* newPair = new pair<int, string>();
                        newPair->first = j;
                        newPair->second = (*searchValues)[i];
                        lookupVec->push_back(newPair);
                        break;
                    }
                }
            }
            delete searchHeaders;
            searchHeaders = nullptr;
            delete searchValues;
            searchValues = nullptr;
            delete csvHeaders;
            csvHeaders = nullptr;
            continue;
        }
        
        // process current line
        bool completeMatch = true;
        for(auto it = lookupVec->begin(); it != lookupVec->end(); it++){
            vector<string>* cvec = splitstr(currentline, ',');
            string cmpval = (*cvec)[(*it)->first];
            // check for command values
            // then check for complete match
            if((*it)->second.at(0) == '/'){
                string cmd = (*it)->second;
                if(cmd.compare("/<0") == 0){
                    // check if neg value
                    completeMatch &= (cmpval.at(0) == '-');
                } else if (cmd.compare("/0") == 0){
                    // check for empty string
                    completeMatch &= (cmpval.compare("") == 0);
                } else if (cmd.compare("/>0") == 0){
                    // check for pos value
                    completeMatch &= (cmpval.at(0) != '-');
                } else if (cmd.at(1) == 'c'){
                    if(cmd.size() > 2){
                        // search for contained strings
                        completeMatch &= (cmpval.find(cmd.substr(2)) != string::npos);
                    }
                } else if (cmd.at(1) == 'o'){
                    /*cerr << "test 1" << endl;
                    if(cmd.size() > 2){
                        // or string is delimited by '|'s
                        bool areAnyTrue = false;
                        cerr << "made it this far" << endl;
                        vector<string>* strings = splitstr(cmd.substr(2),',');
                        for(int i = 0; i < strings->size(); i++){
                            if((*strings)[i].compare(cmpval) == 0){
                                areAnyTrue = true;
                                break;
                            }
                        }
                        completeMatch &= areAnyTrue;
                        delete strings;
                    }*/
                    // TODO
                }
            } else {
                completeMatch &= (cmpval.compare((*it)->second) == 0);
            }

            delete cvec;
        }
        if(completeMatch){
            cout << currentline << endl;
        }
        
    }

    // end of program cleanup
    if(lookupVec != nullptr){
        for(auto it = lookupVec->begin(); it != lookupVec->end(); it++){
            delete *it;
        }
        delete lookupVec;
    }

    // exit code
    return 0;
}

void printUsage(){
    cout << "Usage: " << endl;
    cout << "csvfltr -h [HEADERS] -v [VALUES]" << endl << endl;
    cout << "Headers and Values must be entered in respective order and are comma separated\n\n";
    cout << "Values can either be string literals or commands such as:";
    cout << "\n\t\'/<0\'\t\t  - Negative Value\n\t\'/>0\'\t\t  - Positive Value\n\t\'/0\'\t\t  - Empty String\n\t\'/c[STRING]\'\t  - Contained String\n";
}

vector<string>* splitstr(const string& line, const char& delim){
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
