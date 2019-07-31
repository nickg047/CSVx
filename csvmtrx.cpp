#include <iostream>
//#include <algorithm>
#include <string>
#include <vector>

#define EXIT_CODE 0

using namespace std;

vector<string>* splitstr(const string&, const char&);
pair<string, int>* findvecpair(const string&, vector<pair<string, int>*>*);

int main(int argc, char** argv){
    vector<string> headers;
    vector<pair<string, int>*>** metrics = nullptr;
    //metrics = new vector<pair<string, int>*>* [headers.size()];
    string cline = "";
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
                
                //string insert = linetoks->at(i);
                //insert.erase(std::remove(insert.begin(), insert.end(), '\n'), insert.end());
                //insert.erase(std::remove(insert.begin(), insert.end(), '\r'), insert.end());
                //current->first = insert;
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
                    cout << metrics[j]->at(i)->second << (j+1 < headers.size() ? "," : "");
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
    
    return 0;
}

// split a string by a user specified delimiter
vector<string>* splitstr(const string& line, const char& delim){
    vector<string>* tokens = nullptr;
    if(line.length() > 0){
        tokens = new vector<string>();
    }
    
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

pair<string, int>* findvecpair(const string& key, vector<pair<string, int>*>* vec){
    pair<string, int>* result = nullptr;
    if(vec != nullptr){
        for(int i = 0; i < vec->size(); i++){
            if(vec->at(i) != nullptr){
                if(vec->at(i)->first.compare(key) == 0){
                    result = vec->at(i);
                    break;
                }
            }
        }
    }

    return result;
}
