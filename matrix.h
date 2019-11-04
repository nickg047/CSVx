/*************************************************
 * File: matrix.h                                *
 * Description: Basic matrix/grid data structure *
 *     implemented using using a 2d array        *
 * Author: Nick G                                *
 * E-Mail: nickg047@sdf.org                      *
 * Version: 1                                    *
 * Status: Stable                                *
 *************************************************/
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

#include "common.h"

class matrix{
    private:
        int width;
        int height;
        std::string** root;

        void init();
        void destroy_matrix();
    public:
        // constructor
        inline matrix(const int& x, const int& y)
            : width(x), height(y), root(nullptr) 
        { init(); }

        // destructor
        inline ~matrix() { destroy_matrix(); }

        void clear_matrix();
        void insert_at(const int&, const int&, const std::string&);
        void clear_cell(const int&, const int&);
        void increase_width(const int&);
        void increase_height(const int&);
        std::string get_cell(const int&, const int&) const;
        int longest_str_in_col(const int&) const;
        int get_height() const;
        int get_width() const;

};

#endif
