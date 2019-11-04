/****************************
 * File: common.h           *
 * Author: Nick G           *
 * E-Mail: nickg047@sdf.org *
 * Version: 1               *
 * Status: Stable           *
 ****************************/

#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <vector>

#define EXIT_CODE 0
#define EMPTY_STRING ""

bool areEqual(const std::string&, const std::string&);
bool isEmptyStr(const std::string&);
std::vector<std::string>* splitstr(const std::string&, const char&);

#endif
