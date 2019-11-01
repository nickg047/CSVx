#include <iostream>

#include "common.h"
#include "matrix.h"

#define HEIGHT_BUFFER 512
#define PADDING 2
#define BORDER_CHAR '|'
#define HEADER_CHAR '*'

using namespace std;

void char_repeater(const char&, const int&);

int main(){

    matrix* mtrx = nullptr;
    string line = EMPTY_STRING;
    bool first = true;
    int line_count = 0;
    while(getline(cin, line)){
        // split the line into tokens
        vector<string>* tokens = splitstr(line, ',');

        // if this is our first run, we need to use this first line to init the mtrx
        if(first){
            int matrix_width = tokens->size();
            mtrx = new matrix(matrix_width, HEIGHT_BUFFER);
            first = false; // never come back here again
        } else if(line_count == mtrx->get_height()){
            // if we reach the height of the matrix, increase by the buffer size
            mtrx->increase_height(HEIGHT_BUFFER);
        }

        // store the line in the matrix
        for(int i = 0; i < mtrx->get_width(); i++){
            mtrx->insert_at(i, line_count, tokens->at(i));
        }

        // free up the token data
        delete tokens;

        // increment line count to prevent overflow
        line_count++;
    }

    // matrix is now built..
   
    // calculate longest strings for each column
    int* widths = new int[mtrx->get_width()];
    for(int i = 0; i < mtrx->get_width(); i++){
        widths[i] = mtrx->longest_str_in_col(i) + PADDING;
        widths[i] += 1;
    }

    // calculate total longest width for border
    int total_width = 0;
    for(int i = 0; i < mtrx->get_width(); i++){
        total_width += widths[i] ;
    }
    total_width += 1;

    // print the matrix

    // print header
    char_repeater(HEADER_CHAR, total_width);
    cout << endl;

    // print body
    bool kill = false;
    bool first_cell = true;
    for(int y = 0; y < mtrx->get_height(); y++){
        if(kill){
            break;
        } else if (first_cell == false) {
            cout << endl;
        }
        first_cell = true;
        for(int x = 0; x < mtrx->get_width(); x++){
            string current_cell = mtrx->get_cell(x,y);
            if(current_cell == EMPTY_STRING){
                kill = true;
                break;
            } else if (first_cell){
                cout << BORDER_CHAR; 
                first_cell = false;
            }
            int current_width = widths[x];
            int padding = current_width - current_cell.length() - 2; 
            int front_padding = (padding-1) / 2;
            int back_padding = padding % 2 == 0 ? ((padding-1)/2)+1 : (padding-1) / 2;
            char_repeater(' ', front_padding);
            cout << " " << current_cell << " ";
            char_repeater(' ', back_padding);
            cout << BORDER_CHAR;
        }  
    }
    
    // print footer
    char_repeater(HEADER_CHAR, total_width);
    cout << endl;

    // do some cleanup
    delete [] widths;
    delete mtrx;

    return EXIT_CODE;
}

void char_repeater(const char& c, const int& num){
    for(int i = 0; i < num; i++){
        cout << c;
    }
}
