//
// Created by jasonl on 4/17/23.
//
#include "s_functions.h"
void _strlwr_s(char* str, int len)
{
    for (int i = 0; i < len; ++i)
    {
        str[i] = tolower(str[i]);
    }
}