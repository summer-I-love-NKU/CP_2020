#include "tree.h"
#include<iomanip>//输出美观
/**
 * 问题思考：
    * this指针，一般是隐含的，用处是指向变量自身，
    * 啊啊啊对于指针不是很懂 用*????
    * 对于多个孩子，让孩子之间（兄弟）连起来：
            *孩子兄弟表示法：http://data.biancheng.net/view/30.html
            *遍历https://www.xuebuyuan.com/1175648.html
            * 增加孩子结点，就是让孩子之间（作为兄弟）连起来，一个结点只有一个孩子一个兄弟
            * 是不是就都转成了二叉树？？
    * 结点序号只是为了最后输出美观，所以一开始不需要初始化，最后遍历一次树就行了
    * 

 
 * */

string NODETYPE_name[10] = {"const","var","expr","type","stmt","program","7"};
string StmtType_name[20] = {"skip", "decl","assign","add_assign","sub_assign","mul_assign",
"div_assign","printf","scanf","if","if else","while","13"};
string ValueType_name[5] = {"bool", "int", "char", "string","5"};
string OperatorType_name[20] = {"==","+","-","*","/","++","--","%","0-","&&","||","!","<=","<",">=",">","!=","18"};
int the_nodeID = 0, new0_nodeID = 0, new_nodeID = 0; //根结点
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
    int setw1 = 15, setw2 = 10;
    cout << std::left << setw(2) << this->lineno << "|  "
         << "node@" << std::left << setw(2) << this->nodeID << "  " << setw(7) << NODETYPE_name[this->nodeType] << "  ";

    switch (this->nodeType)
    {
    // cout.setf(std::ios::right);//输出右对齐
    case NODE_STMT:
        cout << std::right<<setw(setw1)<< "stmt_type: " << std::left<<setw(setw2)<<StmtType_name[this->stmt_type];
        // cout<<setw(setw1+setw2)<<" ";
        break;
    case NODE_CONST:
        cout << std::right<<setw(setw1)<< "const_type: " << std::left<<setw(setw2)<<ValueType_name[this->type->type];
        // cout << std::right<<setw(setw1)<< "const_value: ";
        // switch (this->type->type)
        // {
        // case VALUE_BOOL:
        //     cout << this->b_val;
        //     break;
        // case VALUE_INT:
        //     cout << this->int_val;
        //     break;
        // case VALUE_CHAR:
        //     cout << this->ch_val;
        //     break;
        // case VALUE_STRING:
        //     cout << this->str_val;
        //     break;
        // default:
        //     cout << "error!!!";
        //     break;
        // }
        // cout << "  ";
        break;
    case NODE_VAR:
        cout << std::right<<setw(setw1)<< "var_name: " << std::left<<setw(setw2)<<this->var_name;
        // cout << std::right << setw(setw1) << "var_value: " << std::left<<setw(setw2) << this->int_val;
        break;
    case NODE_TYPE:
        cout << std::right<<setw(setw1)<< "type: " << std::left<<setw(setw2)<<ValueType_name[this->type->type];
        // cout<<setw(setw1+setw2)<<" ";
        break;
    case NODE_EXPR:
        cout << std::right<<setw(setw1)<< "expr_type: " << std::left<<setw(setw2)<<OperatorType_name[this->op_type];
        // cout << std::right<<setw(setw1)<< "expr_value: "<<std::left<<setw(setw2)<< this->int_val;
        break;
    case NODE_PROG:
        cout<<setw(setw1+setw2)<<" ";
        // cout<<setw(setw1+setw2)<<" ";//setw1+setw2 只有root走这里吧
        break;
    default:
        cout<<"error!!!";//
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
    cout << "children: @"<<this->nodeID<<" -> [ @"<<this->child->nodeID << " ";
    TreeNode *p = this->child;
    while (p->sibling != nullptr)
    {
        cout << "@" << p->sibling->nodeID << " ";
        p = p->sibling;
    }
    cout << "]"<<"  ";

}


//这两个函数是给root用的
//生成结点的同时也就打印信息了！！！不行，生成不完全，打印的就有错误！
//必须先生成一次
void TreeNode::genNodeId()
{
    if(this==nullptr)
        return;
    this->nodeID = new0_nodeID++;

    this->child->genNodeId();
    this->sibling->genNodeId();
    
}

void TreeNode::printAST() 
{
    if(this==nullptr)
        return;
    this->nodeID = new_nodeID++;
    this->printNodeInfo();

    this->child->printAST();
    this->sibling->printAST();
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
