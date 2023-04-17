//
// Created by jasonl on 4/17/23.
//

#ifndef TEXTADVENTURE_SOURCE_S_FUNCTIONS_H_
#define TEXTADVENTURE_SOURCE_S_FUNCTIONS_H_
#include <string.h>
#include <ctype.h>
#define strcpy_s(src, len, dest) strcpy(src, dest)
#define strnlen_s(src, len) strnlen(src, len)
#define strtok_s(str,delim,ptr) strtok(str, delim)
void _strlwr_s(char* str, int len);
#endif //TEXTADVENTURE_SOURCE_S_FUNCTIONS_H_
