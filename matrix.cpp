/*************************************************
 * File: matrix.cpp                              *
 * Description: Basic matrix/grid data structure *
 *     implemented using using a 2d array        *
 * Author: Nick G                                *
 * E-Mail: nickg047@sdf.org                      *
 * Version: 1                                    *
 * Status: Stable                                *
 *************************************************/
#include "matrix.h"

void matrix::init(){
    if(root != nullptr){
        destroy_matrix();
    }

    root = new std::string* [width];
    for(int i = 0; i < width; i++){
        root[i] = new std::string [height];
        for(int j = 0; j < height; j++){
            root[i][j] = EMPTY_STRING;
        }
    }
}

void matrix::destroy_matrix(){
    if(root == nullptr){
        return;
    }

    for(int i = 0; i < width; i++){
        delete [] root[i];
    }
    delete [] root;
    root = nullptr;
}

void matrix::clear_matrix(){
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            root[i][j] = EMPTY_STRING;
        }
    }
}

void matrix::insert_at(const int& x, const int& y, const std::string& data){
    if(x < width && y < height){
        //std::cerr << "Matrix - data insert bounds check *cleared*" << std::endl;
        root[x][y] = data;
        //std::cerr << "Matrix - data insertion *successful*" << std::endl;

    } else {
        std::cerr << "Unable to insert data at location " << x << ", " << y << std::endl;
        std::cerr << "Location out of bounds" << std::endl;
    }
}

void matrix::clear_cell(const int& x, const int& y){
    if(x < width && y < height){
        root[x][y] = EMPTY_STRING;
    } else {
        std::cerr << "Unable to clear data at location " << x << ", " << y << std::endl;
        std::cerr << "Location out of bounds" << std::endl;
    }
}

void matrix::increase_width(const int& additional_width){
   int original_width = width; // store original width
   width += additional_width; // calc new width

   // create new root array
   std::string** new_arr = new std::string* [width]; // new width

   // copy old data
   int i = 0;
   for(; i < original_width; i++){
       new_arr[i] = root[i];
   }

   // init new data
   for(; i < width; i++){
       new_arr[i] = new std::string [height];
       for(int j = 0; j < height; j++){
           new_arr[i][j] = EMPTY_STRING;
       }
   }

   // delete old array
   delete [] root;

   // assign root to new array
   root = new_arr;
}

void matrix::increase_height(const int& additional_height){
    int original_height = height; // store original height
    height += additional_height; // calc new height

    for(int i = 0; i < width; i++){
        // init new column
        std::string* new_col = new std::string[height];

        // copy original col data
        for(int j = 0; j < original_height; j++){
            new_col[j] = root[i][j];
        }

        // initialize new col data
        for(int j = original_height; j < height; j++){
            new_col[j] = EMPTY_STRING;
        }

        // delete old column
        delete [] root[i];

        // assign new column
        root[i] = new_col;
    }
}

std::string matrix::get_cell(const int& x, const int& y) const{
    return root[x][y];
}

int matrix::longest_str_in_col(const int& x) const{
    int longest = 0;
    for(int i = 0; i < height; i++){
        if(root[x][i].length() > longest){
            longest = root[x][i].length();
        }
    }
    return longest;
}

int matrix::get_height() const{
    return height;
}

int matrix::get_width() const{
    return width;
}

