#ifndef PLATFORMHELPER_H
#define PLATFORMHELPER_H
#include <vector>
#ifdef __unix__
#include <stdio.h>
#endif
#include <string>
std::string OpenFileDialog();
#endif