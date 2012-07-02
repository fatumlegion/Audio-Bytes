#ifndef MAIN_H
#define MAIN_H
#include <fmodex/fmod.hpp>
#include <string>
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern FMOD::System *g_FSystem;

void updateWindowTitle(std::string str);
#endif