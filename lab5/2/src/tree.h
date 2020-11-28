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
    NODE_EXPR,//表达式
    NODE_TYPE,//类型

    NODE_STMT,//语句
    NODE_PROG,//程序
};

enum OperatorType//---------运算类型
{
    OP_EQ,  // ==
};

enum StmtType {//------------语句类型
    STMT_SKIP,
    STMT_DECL,
}
;
// enum DeclType {//------------语句类型
//     TYPE_INT,
//     TYPE_CHAR,
//     TYPE_BOOL,
//     TYPE_STRING,
// }
;
struct TreeNode {//-------------结点类（结构体）
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
        Type* type;  // 对于常量+变量、类型、表达式结点，有类型。 定义在type.h
    //STMT
        StmtType stmt_type;//语句类型
        Type* decl_type;//声明类型
    //CONST
        int int_val;
        char ch_val;
        bool b_val;
        string str_val;
    //VAR
        string var_name;//变量名

    //------------方法
    //儿子和兄弟结点的操作
    //
    TreeNode* child = nullptr;
    TreeNode* sibling = nullptr;

    void addChild(TreeNode*);
    void addSibling(TreeNode*);
    
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
};

#endif