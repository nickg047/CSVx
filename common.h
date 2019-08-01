#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <vector>

#define EMPTY_STRING ""

bool areEqual(const std::string&, const std::string&);
bool isEmptyStr(const std::string&);
std::vector<std::string>* splitstr(const std::string&, const char&);

#endif
