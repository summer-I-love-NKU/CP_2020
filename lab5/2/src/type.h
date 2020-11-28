#ifndef TYPESYSTEM_H
#define TYPESYSTEM_H
#include "./pch.h"
using namespace std;


enum ValueType
{
    VALUE_BOOL,
    VALUE_INT,
    VALUE_CHAR,
    VALUE_STRING,
    COMPOSE_STRUCT,//struct,似乎困难起来了
    COMPOSE_UNION,//union
    COMPOSE_FUNCTION//function
};

class Type
{
public:
    ValueType type;//属性
    Type(ValueType valueType);//构造函数
public:  
    /**如果你要设计复杂类型系统的话，可以修改这一部分 
     * 
     **/
    ValueType* childType; // for union or struct
    ValueType* paramType, retType; // for function
    void addChild(Type* t);
    void addParam(Type* t);
    void addRet(Type* t);

//兄弟？？？？
public:
    ValueType* sibling; 
public:
    string getTypeInfo();
};

// 设置几个常量Type，可以节省空间开销？？？？？
//注意这都是对象，需要用TYPE_INT.type！！！
static Type* TYPE_INT = new Type(VALUE_INT);
static Type* TYPE_CHAR = new Type(VALUE_CHAR);
static Type* TYPE_BOOL = new Type(VALUE_BOOL);
static Type* TYPE_STRING = new Type(VALUE_STRING);

int getSize(Type* type);

#endif