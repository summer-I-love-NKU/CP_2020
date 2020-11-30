#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE
#include "pch.h"
using namespace std;

struct Symtable
{
public:
    int num;
    string name;
    Symtable(int num, string table);
};

#endif