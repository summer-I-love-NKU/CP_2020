#include "tree.h"
/**
 * 问题思考：
    * this指针，一般是隐含的，用处是指向变量自身，
    * 啊啊啊对于指针不是很懂 用*????
    * 对于多个孩子，让孩子之间（兄弟）连起来：
    *     增加孩子结点，就是让孩子之间（作为兄弟）连起来，一个结点只有一个孩子一个兄弟
    *     是不是就都转成了二叉树？？
    * 结点序号只是为了最后输出美观，所以一开始不需要初始化，最后遍历一次树就行了
    * 

 

     * 要看有哪个类型，先看结点类型，再看具体类型
     * 
enum NodeType//-------结点类型
{
    NODE_CONST, //常量
    NODE_VAR,//变量
    NODE_EXPR,//表达式
    NODE_TYPE,//类型

    NODE_STMT,//语句
    NODE_PROG,//程序
};
enum StmtType {//------------语句类型
    STMT_SKIP,
    STMT_DECL,
}
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

    对应类型起个名字
 * stmt     stmt
 * var      varname
 * const    type
 * */

string NODETYPE_name[10] = {"const","var","expr","type","stmt","prog"};
string StmtType_name[10] = {"skip", "decl"};
string ValueType_name[10] = {"bool", "int", "char", "string"};

int the_nodeID = 0,new0_nodeID=0,new_nodeID=0;//根结点
//-------------------------
//增加孩子结点，就是让孩子之间依次连起来
void TreeNode::addChild(TreeNode *the_child)
{
    if (this->child != nullptr)
    {   
        TreeNode *p=this->child;
        while(p->sibling!=nullptr)
        {
            p = p->sibling;
        }
        p->sibling = the_child;
    }
    else
    {
        this->child = the_child;
    }
}
//增加兄弟结点
void TreeNode::addSibling(TreeNode* the_sibling)
{
    this->sibling = the_sibling;

}
//构造函数，初始化，序号自增
TreeNode::TreeNode(int lineno, NodeType type) 
{
    //第一件事，序号自增,记录行号
    this->nodeID = the_nodeID;
    the_nodeID++;
    this->lineno = lineno;
    this->nodeType = type;
}


void TreeNode::printNodeInfo() 
{
    cout << "line@" << this->lineno << "  "
         << "node@" << this->nodeID << "  " << NODETYPE_name[this->nodeType] << "  ";


    switch (this->nodeType)
    {
        case NODE_STMT:
            cout << "stmt_type: "<<StmtType_name[this->stmt_type];
            break;
        case NODE_CONST:
            cout << "const_type: "<<ValueType_name[this->type->type]<<" ";
            cout << "const_value: ";
            switch (this->type->type)
            {
                case VALUE_BOOL:
                    cout << this->b_val;
                    break;
                case VALUE_INT:
                    cout << this->int_val;
                    break;
                case VALUE_CHAR:
                    cout << this->ch_val;
                    break;
                case VALUE_STRING:
                    cout << this->str_val;
                    break;
                default:
                    cout << "error!!!";
                    break;
            }
            cout << "  ";
            break;
        case NODE_VAR:
            cout << "var_name:"<<this->var_name;
            break;
        case NODE_TYPE:
            cout << "type:"<<ValueType_name[this->decl_type->type];
            break;
        default:
            //cout << "error!!!";//没有，比如root
            break;
    }
    cout << "  ";
    //这里别忘了判断条件！！！有无孩子呀！！！
    if(this->child!=nullptr)
        this->printChildrenId();

    cout << endl;
}

void TreeNode::printChildrenId() 
{
    cout << "children: [ @"<<this->child->nodeID << " ";
    TreeNode *p = this->child;
    while (p->sibling != nullptr)
    {
        cout << "@" << p->sibling->nodeID << " ";
        p = p->sibling;
    }
    cout << "]"<<"  ";

}


//这两个函数是给root用的
//递归！！！先序遍历？是不是

//生成结点的同时也就打印信息了！！！不行，生成不完全，打印的就有错误！
//必须先生成一次
void TreeNode::genNodeId()
{////////cout << this->nodeID<<"结点开始打印！！！" << endl;------用于debug

    this->nodeID = new0_nodeID++;
    
    if (this->child != nullptr)
    {////////cout << this->nodeID<<"子结点不为空！！！" << endl;----用于debug
        

        this->child->genNodeId();
        //this->child->sibling->genNodeId();

        TreeNode *p = this->child->sibling;
        while (p!=nullptr)
        {
            p->genNodeId();
            p = p->sibling;
        }
    }
    else
    {////////cout << this->nodeID<<"子结点为空！！！" << endl;----用于debug
        
        TreeNode *p = this->sibling;
        while (p!=nullptr)
        {
            p->nodeID = new0_nodeID++;
            // p->printNodeInfo();//----------
            p = p->sibling;
        }
    }
    
}

void TreeNode::printAST() 
{
    this->nodeID = new_nodeID++;
    this->printNodeInfo();//---------------

    if (this->child != nullptr)
    {
        this->child->printAST();

        TreeNode *p = this->child->sibling;
        while (p!=nullptr)
        {
            p->printAST();
            p = p->sibling;
        }
    }
    else
    {
        TreeNode *p = this->sibling;
        while (p!=nullptr)
        {
            p->nodeID = new_nodeID++;
            p->printNodeInfo();//----------
            p = p->sibling;
        }
    }
    
}



// // You can output more info...
// void TreeNode::printSpecialInfo() {
//     // switch(this->nodeType){
//     //     case NODE_CONST:
//     //         cout << NODETYPE_name[NODE_CONST];
//     //         break;
//     //     case NODE_VAR:
//     //         break;
//     //     case NODE_EXPR:
//     //         break;
//     //     case NODE_TYPE:
//     //         break;
//     //     case NODE_STMT:
//     //         break;
//     //     case NODE_PROG:
//     //         break;
//     //     default:
//     //         break;
//     // }
// }

// string TreeNode::sType2String(StmtType type) {
//     return "?";
// }


// string TreeNode::nodeType2String (NodeType type){
//     return "<>";
// }
