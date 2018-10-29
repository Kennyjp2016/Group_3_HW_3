/*	=============================================================================
 *	This header file is for prototyping functions that don't fit anywhere else
 *	===========================================================================*/
#include <vector>

#ifndef util_h
#define util_h
int goodIn (int min, int max);
float goodIn (float min, float max);
void cls();
bool exitPrompt();
std::vector<int> genNums(int size, bool random);
#endif
