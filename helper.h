#ifndef HELPER_H
#define HELPER_H
#include <string>
#include <fmodex/fmod_errors.h>
#include <algorithm>
#include <iterator>
#include <vector>

bool StrToBool(std::string str);
std::vector<std::string> split( const std::string& s, const std::string& f );
std::string trim_spaces(const std::string &str);
std::string trim(std::string str);
std::string getAbsoluteFileName(std::string file);
bool fModError(FMOD_RESULT result);
#endif