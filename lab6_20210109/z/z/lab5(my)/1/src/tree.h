#ifndef TREE_H
#define TREE_H

#include "pch.h"
#include "type.h"
/**
 * 问题：多个孩子怎么表示
 * 第二个孩子之后就用孩子的兄弟表示？？？先这样吧！
 * 
 * 
 * 
 * */
enum NodeType//-------结点类型
{
    NODE_CONST, //常量
    NODE_VAR,//变量
    NODE_ARR,
    NODE_EXPR,//表达式
    NODE_TYPE,//类型

    NODE_STMT,//语句
    NODE_PROG,//程序
};

enum OperatorType//---------运算类型
{
    OP_EQ,  // ==
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    OP_NEG,
    OP_AND,
    OP_OR,
    OP_NOT,
    OP_LESS_EQ,
    OP_LESS_THAN,
    OP_MORE_EQ,
    OP_MORE_THAN,
    OP_NOT_EQ,

};

enum StmtType {//------------语句类型
    STMT_BLOCK,
    STMT_SKIP,
    STMT_DECL_V,//var
    STMT_DECL_P,//*p
    STMT_DECL_R,//&
    STMT_DECL_A,//a[1][2]
    STMT_ASSIGN,
    STMT_ADD_ASSIGN,
    STMT_SUB_ASSIGN,
    STMT_MUL_ASSIGN,
    STMT_DIV_ASSIGN,
    STMT_SELF_ADD_ASSIGN,
    STMT_SELF_SUB_ASSIGN,
    STMT_PRINTF,
    STMT_SCANF,
    STMT_IF,
    STMT_IF_ELSE,
    STMT_WHILE,
    STMT_FOR,
}
;


struct TreeNode
{ //-------------结点类（结构体）
public:
    //-----------属性
    //固有属性
    int nodeID;  // 用于作业的序号输出
    int lineno;
    NodeType nodeType;

    //可选属性（看是什么类型的结点）
    //EXPR
        OperatorType op_type;  // 如果是表达式
    //TYPE
        //注意定义的是一个类对象，需要用this.type.type！！！
        Type* type;  // 对于常量+变量、类型（用于声明或定义）、表达式结点，有类型。 定义在type.h
    //STMT
        StmtType stmt_type;//语句类型
        // Type* decl_type;//声明类型
    //CONST
        int int_val;//1
        char ch_val;//2
        bool b_val;//3
        string str_val;//4
        int address;//5 pointer指针
        //----------决定变量类型！！！！！！
        char val_type_flag;//'i' 'c' 'b' 's' 'p'  
        //VAR
        string var_name;//变量名 or 数组名共用
        // int arr_d[4];// 数组维度？

        //------------方法
        //儿子和兄弟结点的操作
        //
        TreeNode *child = nullptr;
        TreeNode *sibling = nullptr;

        void addChild(TreeNode *);
        void addSibling(TreeNode *);

        //显示信息
        void printNodeInfo();
        void printChildrenId();
        // void printSpecialInfo();

        //生成结点序号，为了显示美观，所以一开始不需要结点序号？？
        //--------注意这两个函数，只给root用！！！不然你也不知道怎么写
        void genNodeId();
        void printAST(); // 先输出自己 + 孩子们的id；再依次让每个孩子输出AST。

        //这个我自己用数组实现了！！！
        // //public:
        //     static string nodeType2String (NodeType type);
        //     static string opType2String (OperatorType type);
        //     static string sType2String (StmtType type);

    public:
        //这个构造函数？？？！！！new是什么意思
        //TreeNode* node = new TreeNode(lineno, NODE_CONST);
        TreeNode(int lineno, NodeType type);

        static int node_num;
        int total_node_num();
};


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

// struct Param
// {
// public:
//     string type; //参数类型
//     string name; //参数名
//     Param *next;
// };
 

// struct Function
// {

// public:
//     string name; //函数名
//     string type; //返回值类型
//     Param para; //参数列表
//     // long scope; //标识符作用域信息
//     // long memloc; //函数入口的地址
//     // Function * next; //异名链表指针

// };


#endif