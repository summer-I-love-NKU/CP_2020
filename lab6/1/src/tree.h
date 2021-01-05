#ifndef TREE_H
#define TREE_H

#include "pch.h"
#include "type.h"
#define MAX_CHILD_NUM 20

#if 1
    enum NodeType//-------结点类型
    {
        NODE_CONST, //常量
        NODE_VAR,//变量
        NODE_ARR,
        NODE_EXPR,//表达式
        NODE_TYPE,//类型

        NODE_STMT,//语句------------STMT_TYPE
        NODE_PROG,//程序
        NODE_FUNC,//
        NODE_BLOCK,//
    };

    enum OperatorType//---------运算类型
    {
    // 未初始化的就是0,这样可以区分
        OP_ADD=1,
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
        OP_EQ, 
        OP_NOT_EQ,

    };

    enum StmtType {//------------语句类型
        STMT_BLOCK,//已经废弃，准备删除
        STMT_SKIP,
        STMT_RETURN,//return
        STMT_DECL_V,//var
        STMT_DECL_P,//*p
        STMT_DECL_R,//&
        STMT_DECL_A,//a[1][2]
        STMT_ASSIGN,//  =
        STMT_ADD_ASSIGN,//a+=1----注意这里的顺序影响tree.cpp:else if(t_type>=STMT_ADD_ASSIGN&&t_type<=STMT_DIV_ASSIGN)
        STMT_SUB_ASSIGN,//
        STMT_MUL_ASSIGN,
        STMT_DIV_ASSIGN,
        STMT_SELF_ADD_ASSIGN,
        STMT_SELF_SUB_ASSIGN,//a--
        STMT_PRINTF,
        STMT_SCANF,
        STMT_IF,
        STMT_IF_ELSE,//------
        STMT_IF_ELSE_IF,
        STMT_WHILE,//if else for while
        STMT_FOR,//-----
    }
    ;

    struct TreeNode
    {
    public:
        //固有属性
        int nodeID;  // 用于作业的序号输出
        int lineno;
        NodeType nodeType;
        // Label label;
        // union value val;//--先不用了

        //可选属性（看是什么类型的结点）
        //EXPR
            OperatorType op_type;  // 如果是表达式,初始化-1,代表空
        //TYPE
            //注意定义的是一个类对象，需要用this.type.type！！！
            Type* type;  // 对于常量+变量、类型（用于声明或定义）、表达式结点，有类型。 定义在type.h
        //STMT
            StmtType stmt_type;//语句类型
        //CONST
            int int_val;//1
            char ch_val;//2
            bool b_val;//3
            string str_val;//4
            int address;//5 pointer指针

            char val_type_flag;//'i' 'c' 'b' 's' 'p'  
            //VAR
            string var_name;//变量名 or 数组名共用

            TreeNode *child = nullptr;
            // vector<TreeNode*> children;//-------赋值不成功！！！
            // TreeNode childarr[20];//不允许使用不完整的类型,只能写指针数组
            // TreeNode* childarr[MAX_CHILD_NUM];
            // int childnum=0; //--------
            TreeNode *sibling = nullptr;
            TreeNode *father = nullptr;

            void addChild(TreeNode *);
            void addSibling(TreeNode *);

            //显示信息
            void printNodeInfo();
            void printChildrenId();

            //生成结点序号，为了显示美观，所以一开始不需要结点序号？？
            //注意这两个函数，只给root用！
            void genNodeId();
            void printAST(); // 先输出自己 + 孩子们的id；再依次让每个孩子输出AST。
            void type_check(TreeNode *t);


            /****************lab7 final*********************/
            void gen_code(); //, TreeNode *root);
            void recursive_gen_code( TreeNode *t,bool only_once=0);
            void expr_gen_code( TreeNode *t);
            void stmt_gen_code( TreeNode *t);

            void gen_decl( TreeNode *t);
            void gen_header();
            void gen_tail();
            void get_label();
            void recursive_get_label(TreeNode *t);
            void expr_get_label(TreeNode *t);
            void stmt_get_label( TreeNode *t);
            string new_label();

            //TreeNode *NewRoot(int kind, int kind_kind, NodeAttr attr, int type,
            //TreeNode *child1, TreeNode *child2, TreeNode *child3, TreeNode *child4);

            void get_temp_var(TreeNode *t);

        public:
            TreeNode();
            TreeNode(int lineno, NodeType type);
            //deep copy func
            // TreeNode operator=(TreeNode &t);//暂不实现！

            static int node_num;
            int total_node_num();

            /********************final**************/
            static int label_seq;
    };

    /*********************我的符号表****************************/
    struct SymTable
    { 
    public:
        SymTable(int scopeid);
        int scope=-1;//作用域级别
        // string name;
        // string type; //or char type//int char bool string? pointer reference
        // char flag;//var  const  pointer  struct  function
        // int d[5];//数组维数
        map<string,pair<string,int> > tmap;
        map<string,TreeNode* > nodemap;
        SymTable *father;

        //----
    };


                    #if 0/*********************助教的符号表****************************/

                        #define MAX_ID 1024

                        typedef struct TAG_SYMBOL_ENTRY
                        {
                            string name;
                            int token;//
                            string type;//none 
                        } symbol_entry;

                        class symbol_table
                        {
                        private:
                            symbol_entry table[MAX_ID];
                            int size;

                        public:
                            int lookup(string name);
                            int insert(string name, int token);
                            int gettoken(string name);
                            string &getname(int pos);
                            int set_type(int pos, string type);
                            string get_type(int pos);
                        };
                    #endif

    #endif
    /****************************************************************************/
#endif