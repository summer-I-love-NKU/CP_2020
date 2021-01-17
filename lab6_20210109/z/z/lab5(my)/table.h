#ifndef SYMTABLE_H
#define SYMTABLE_H

#include"pch.h"

struct SymTable
{ 
public:
    SymTable(int scopeid);
    int scope;//作用域级别
    // string name;
    // string type; //or char type//int char bool string? pointer reference
    // char flag;//var  const  pointer  struct  function
    // int d[5];//数组维数
    map<string,pair<string,int> > tmap;
    SymTable *father;
    //----
};

struct Param
{
public:
    string type; //参数类型
    string name; //参数名
    Param *next;
};
 

struct Function
{

public:
    string name; //函数名
    string type; //返回值类型
    Param para; //参数列表
    // long scope; //标识符作用域信息
    // long memloc; //函数入口的地址
    // Function * next; //异名链表指针

};



#endif
