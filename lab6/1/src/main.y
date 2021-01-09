%{
//定义段
//规则段
//辅助函数段
#include "common.h"//包含tree的头文件
#define YYstmt_type TreeNode *  
TreeNode* root;//需要extern吗？？？
extern int lineno;
int yylex();
int yyerror( char const * );
//-----------符号表版本2 使用类！！！
SymTable *cur_table;
int scopeid=-1,n_top=1;
string ValType_name[20] = {"bool", "int", "char", "string","void","const int","const char","9"};//对应enum ValueType
//array:
int ele_num;
//-------------

//类型错误检查（比如字符串、布尔值不能参与某些运算、输入输出函数也有参数类型要求）
//实际上，全局变量的声明如何加入符号表，我是在类型检查（decl）函数中构建的，其他的地方就是stmt的大括号和main的大括号构建符号表
    //if else while
    void check_control_stmt(TreeNode* t)
    {
        /************************TYPE_CHECK*****************************/
            if(t->child->val_type_flag=='i')
            {
                /***************************type trans*********************************/
                cout <<t->lineno<<" : if/while stmt:the expr should be bool type.   type trans!!! int-->bool"<<endl;
                t->child->val_type_flag == 'b';//??????
            }
            else if(t->child->val_type_flag=='b')
            {
                ;
            }
            else
            {
                cout <<t->child->lineno<<" : type error!   if/while stmt:the expr should be bool type!" << endl;
            }
        /************************TYPE_CHECK*****************************/
    }
    void check_for_stmt(TreeNode* t)
    {
            if(t->child->sibling->val_type_flag=='i')//child2(for 的 expr2)
            {
                /***************************type trans*********************************/
                cout <<t->lineno<<" : for stmt:the expr2 should be bool type.\ntype trans!!! int-->bool"<<endl;
                t->child->sibling->val_type_flag == 'b';//??????
            }
            else if(t->child->sibling->val_type_flag=='b')
            {
                ;
            }
            else
            {
                cout <<t->child->lineno<<" : type error!"<<endl<<
                "for stmt:the expr2 should be bool type!" << endl;
            }
    }
    //redecl重声明
    void check_decl(TreeNode* t)
    {
        if(scopeid==-1)
            cur_table=new SymTable(++scopeid);//??????????????
        if(cur_table->tmap.count(t->var_name)==0)
        {
            cur_table->tmap[t->var_name]=make_pair(ValType_name[t->father->type->type],n_top);
            cur_table->nodemap[t->var_name]=t;
            n_top++;
        }
        else
        {
            cout <<t->lineno<<" : "<<t->var_name<<" :redecl error!"<<endl;
        }
    }
    //nodecl未声明    并且对合法的ID 对应到符号表！！
    void check_ID(TreeNode* t)
    {
        //cout<<cur_table->scope<<endl;
        if(cur_table->tmap.count(t->var_name)==0)
        {
            SymTable *p=cur_table;
            while(p!=nullptr)
            {
                if(p->tmap.count(t->var_name)!=0)
                {
                    t->val_type_flag=p->nodemap[t->var_name]->val_type_flag;
                    return;
                }
                    
                p=p->father;
                
            }
            cout <<t->lineno<<" : "<<t->var_name<<" :no decl error!"<<endl;
            //cout<<cur_table->scope<<endl;
        }
        else//对应到符号表！！
        {
            //t=cur_table->nodemap[t->var_name];//似乎不行  怎么深拷贝？？？
            //cout<<"对应到符号表！！"<<t->val_type_flag;
            t->val_type_flag=cur_table->nodemap[t->var_name]->val_type_flag;
        }
    }

    //calculation 运算类型
    void check_CAL_math(TreeNode* t)
    {
        if(t->child->val_type_flag!='i'||t->child->sibling->val_type_flag!='i')
        {
            cout <<t->lineno<<" : calculation type error! expect \"int\"!!!"<<endl;
        }
    }
    void check_CAL_math_negtivenum(TreeNode* t)
    {
        if(t->child->val_type_flag!='i')
        {
            cout <<t->lineno<<" : math calculation type error! expect \"int\"!!!"<<endl;
        }
    }

    void check_CAL_logical(TreeNode* t)
    {
        if(t->child->val_type_flag=='s'||t->child->val_type_flag=='c'||t->child->sibling->val_type_flag=='s'||t->child->sibling->val_type_flag=='c')
        //int bool  可以  string char 不可以 进行逻辑运算
        {
            cout <<t->lineno<<" : logical calculation type error! expect \"int\" or \"bool\"!!!"<<endl;
        }
    }
    void check_CAL_logical_not(TreeNode* t)
    {
        if(t->child->val_type_flag=='s'||t->child->val_type_flag=='c')//int bool  可以  string char 不可以 进行逻辑运算
        {
            cout <<t->lineno<<" : logical calculation type error! expect \"int\" or \"bool\"!!!"<<endl;
        }
    }


    //检查声明和赋值的类型是否正确
    void check_decl_type(TreeNode* t)//int a = 1; t是孩子，这样找父亲方便
    {
        //int a=1;
        if(t->father->father->type==TYPE_INT)
        {
            if(t->val_type_flag!='i')
            {
                cout <<t->lineno<<" : assign type error! expect \"int\"!!!"<<endl;
            }
        }
        else if(t->father->father->type==TYPE_STRING)
        {
            if(t->val_type_flag!='s')
            {
                cout <<t->lineno<<" : assign type error! expect \"string\"!!!"<<endl;
            }
        }
        else if(t->father->father->type==TYPE_CHAR)
        {
            if(t->val_type_flag!='c')
            {
                cout <<t->lineno<<" : assign type error! expect \"char\"!!!"<<endl;
            }
        }
        else if(t->father->father->type==TYPE_BOOL)
        {
            if(t->val_type_flag!='b')
            {
                if(t->val_type_flag!='i')
                {cout <<t->lineno<<" : assign type error! expect \"bool\"!!!"<<endl;}
                else
                {
                    /***************************type trans*********************************/
                    cout <<t->lineno<<" : type trans!!! int-->bool"<<endl;
                    t->val_type_flag='b';
                }
            }
        }
    }
    void check_assign_type(TreeNode* t)//a = 1; a和1是兄弟关系  但这个a是归约得到ID，需要在符号表对应到定义的a
    {
        // cout<<t->val_type_flag<<endl;
        if(t->val_type_flag=='i')
        {
            if(t->sibling->val_type_flag!='i')
            {
                cout <<t->lineno<<" : assign type error! expect \"int\"!!!"<<endl;
            }
        }
        else if(t->val_type_flag=='c')
        {
            if(t->sibling->val_type_flag!='c')
            {
                cout <<t->lineno<<" : assign type error! expect \"char\"!!!"<<endl;
            }
        }
        else if(t->val_type_flag=='s')
        {
            if(t->sibling->val_type_flag!='s')
            {
                cout <<t->lineno<<" : assign type error! expect \"string\"!!!"<<endl;
            }
        }
        else if(t->val_type_flag=='b')
        {
            if(t->sibling->val_type_flag!='b')
            {
                if(t->sibling->val_type_flag!='i')
                {cout <<t->lineno<<" : assign type error! expect \"bool\"!!!"<<endl;}
                else
                {
                    /***************************type trans*********************************/
                    cout <<t->lineno<<" : type trans!!! int-->bool"<<endl;
                    t->sibling->val_type_flag='b';
                }
            }
        }
    }
    //
    void check_IO(TreeNode* t)
    {
        

    }
    /***************************type trans*********************************/
    void type_trans(TreeNode* t)
    {
        //注意可能有的没有val_type_flag属性，导致段错误！！！！

        // //-------类型转换？？？char m=97;-->'a' -----
        // if(ValType_name[t->father->type->type]=="char"&&t->val_type_flag=='i')
        // {
        //     t->ch_val=char(t->int_val);
        //     t->val_type_flag='c';
        //     cout <<t->child->lineno<< "type check：int转换为char" << endl;
        // }
        // if(ValType_name[t->father->type->type]=="bool"&&t->val_type_flag!='b')
        // {
        //     t->b_val=bool(t->int_val)||bool(t->ch_val);
        //     t->val_type_flag='b';
        //     cout <<t->child->lineno<< "type check：转换为bool" << endl;
        // }
    }
//-----------------------------------
%}


// %start program//???开始符号？是不是可以默认？之前实验似乎没定义

    //声明or定义or变量等等的类型：int char bool void
    %token T_INT T_CHAR T_BOOL T_STRING T_VOID CONST
    //赋值 = += -= *= /= 
    %token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
    // 比较 == != >= > <= <
    %token EQ NOT_EQ LESS_THAN LESS_EQ MORE_THAN MORE_EQ
    //------------注意匹配顺序！！！ == =，!= !, <= <,----------------

    //逻辑操作 && || !
    %token AND OR NOT 
    //运算 + - * / %    ++ --(算在了赋值语句的产生式)
    %token ADD SUB MUL DIV MOD SELF_ADD SELF_SUB
    // ; ,  .  (){}[]
    %token SEMICOLON COMMA DOT LPAREN RPAREN LBRACE RBRACE LMPAREN RMPAREN
    //ID  integer(16 10 8 2) char bool string 字符 数字 标识符 字符串 等等
    %token IDENTIFIER INTEGER_H INTEGER_D INTEGER_O INTEGER_B CHAR BOOL STRING
    // 关键字 main return for  printf  scanf  while  if else "else if"
    %token MAIN RETURN FOR WHILE IF ELSE ELSE_IF PRINTF SCANF BREAK CONTINUE

    //!!!后定义的优先级高！！！ 
    // = += -= *= /=
    %right ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN 
    //||
    %left OR
    //&&
    %left AND
    //|
    %left b_OR
    //^
    %left b_NOR
    //&
    %left b_AND
    // == !=
    %left EQ NOT_EQ
    //> >= < <=
    %left MORE_THAN MORE_EQ LESS_THAN LESS_EQ
    //+ -
    %left ADD SUB
    //* / %
    %left MUL DIV MOD 
    //负号 - ! 按位取反~  前自增 前自减++ --  取地址运算&  指针*
    %right UMINUS NOT b_NOT pre_SELF_ADD pre_SELF_SUB GET_ADDRESS  POINTER
    //后自增 后自减++ --
    %right SELF_ADD SELF_SUB 
    // %nonassoc LOWER_THEN_ELSE
    // %nonassoc ELSE 
    /*
    %nonassoc的含义是没有结合性。它一般与%prec结合使用表示该操作有同样的优先级。

    expr: '-' expr %prec UMINUS { $$ = node(UMINUS, 1, $2); }
    表示该操作的优先级与UMINUS相同，
    在上面的定义中，UMINUS的优先级高于其他操作符，
    所以该操作的优先级也高于其他操作符计算。
    |SUB %prec UMINUS expr  {
        // $2就是expr

         only one %prec allowed per rule!!!!!!!


    If-Else的冲突
    当有两个IF一个ELSE时，该ELSE和哪个IF匹配是一个问题。有两种匹配方法：与第一个匹配和与第二匹配。现代程序语言都让ELSE与最近的IF匹配，这也是yacc的缺省行为。
    虽然yacc行为正确，但为避免警告，可以给IF-ELSE语句比IF语句更高的优先级：
    %nonassoc IFX
    %nonassoc ELSE
    stmt: IF expr stmt %prec IFX
        | IF expr stmt ELSE stmt

    这里的第二阶段，声明语句，改为增加更深的子结点:一共四层
    decl
    int  
    a b c
    1 2 
    */
%%
CompUnit:
    | CompUnit Func_Def{
        $$=$1;
        $$->addChild($2);
        // root->addChild($2);
    }
    | CompUnit Decl{
        $$=$1;
        $$->addChild($2);
        // root->addChild($2);
    }
    | Func_Def{
        root = new TreeNode(0, NODE_PROG);
        root->addChild($1);
        $$=root;
    }
    | Decl{
        root = new TreeNode(0, NODE_PROG);
        root->addChild($1);
        $$=root;
    }
    ;

    Decl:decl_stmt SEMICOLON {$$ = $1;};


Func_Def:
    Type MAIN LPAREN RPAREN LBRACE fake_1 statements RBRACE {
        //cout<<"FUNC!!!\n";
        $$ = new TreeNode(0, NODE_FUNC); 
        $$->addChild($7);
        
        //symboltable
        // cout<<"-------level: "<<cur_table->scope<<"-------"<<endl;
        // for(map<string,pair<string,int> >::iterator iter = cur_table->tmap.begin(); iter != cur_table->tmap.end(); iter++)
        // {
        //     cout<<iter->first<<":"<<iter->second.first<<"  "<<iter->second.second<<endl;
        // }cout<<endl;

    }
    ;
    fake_1:{
            
            SymTable* t=new SymTable(++scopeid);
            if(scopeid!=0)//不是第一级作用域
            {
                t->father=cur_table;
                cur_table=t;
                n_top=1;
            }
        };

statements:
    statement {/*****增加头节点，一个block************/
        $$ = new TreeNode(lineno, NODE_BLOCK);
        $$->addChild($1);
    }
    | statements statement 
    {   
        $$=$1;
        $$->addChild($2);
    }
    ;

statement:
    SEMICOLON  {$$ = new TreeNode(lineno, NODE_STMT); $$->stmt_type = STMT_SKIP;}
    | decl_stmt SEMICOLON {$$ = $1;};
    | assign_stmt SEMICOLON {$$=$1;}
    | IO_stmt SEMICOLON {$$=$1;}
    | if_else_while_for_stmt {$$=$1;}
    | RETURN INT_CONST SEMICOLON{
        $$ = new TreeNode(lineno, NODE_STMT); 
        $$->stmt_type = STMT_RETURN;
        $$->addChild($2);
    } 
    | LBRACE fake_2 statements RBRACE {
        // //语句加一个总的根结点，解决问题???????
        // $$ = new TreeNode($3->lineno, NODE_BLOCK);//NODE_STMT);
        // $$->stmt_type=STMT_BLOCK;
        // $$->addChild($3);
        $$ = $3;

        
        cur_table=cur_table->father;

        //-----------------符号表 版本2--------------------
        /* cout<<-------level:<<cur_table->scope<<-------<<endl;*/
        // for(SymTable* t=cur_table;t!=nullptr;t=t->father)
        // {
        //     cout<<"level"<<t->scope<<":"<<endl;
        //     for(map<string,pair<string,int> >::iterator iter = t->tmap.begin(); iter != t->tmap.end(); iter++)
        //     {
        //         cout<<iter->first<<":"<<iter->second.first<<"  "<<iter->second.second<<endl;
        //     }
        // }   
        // cout<<endl;
        //-------------------------
    }
    ;
    fake_2:{
            //-------------符号表 版本2------------
            SymTable* t=new SymTable(++scopeid);
            t->father=cur_table;
            cur_table=t;
            n_top=1;
            //----------------------------
        };




expr: 
    ID {
        $$ = $1;
        //$$->nodeType=NODE_EXPR;

        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID($1);
    }
    | INT_CONST {
        //注意这部分的int char bool类型常量在词法分析的.l文件就已经定义初始化树结点了！！！
        $$ = $1;
        $$->val_type_flag='i';
    }
    | CHAR {
        $$ = $1;
        $$->val_type_flag='c';
    }
    | STRING {
        $$ = $1;
        $$->val_type_flag='s';
    }
    | BOOL{
        $$ = $1;
        $$->val_type_flag='b';
    }
    | LPAREN expr RPAREN {
        $$ = $2;
        $$->val_type_flag=$2->val_type_flag;//??----------
        }

    | expr ADD expr {

        //运算的类型就先规定为整形，只是支持int
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_ADD;
        $$->addChild($1);
        $$->addChild($3);

        $$->val_type_flag=$1->val_type_flag;
    /*********************check_CAL_math*********************************************/
        check_CAL_math($$);
        }
    | expr SUB expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_SUB;
        
        $$->addChild($1);
        $$->addChild($3);
        
        $$->val_type_flag=$1->val_type_flag;

        check_CAL_math($$);
        }
    | expr MUL expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_MUL;
        
        $$->addChild($1);
        $$->addChild($3);
        
        $$->val_type_flag=$1->val_type_flag;

        check_CAL_math($$);
        }
    | expr DIV expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_DIV;
        
        $$->addChild($1);
        $$->addChild($3);
        
        $$->val_type_flag=$1->val_type_flag;

        check_CAL_math($$);
        }
    | expr MOD expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_MOD;
        
        $$->addChild($1);
        $$->addChild($3);
        
        $$->val_type_flag=$1->val_type_flag;

        check_CAL_math($$);
    }
    |SUB %prec UMINUS expr  {
        //$2就是expr
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_NEG;
       
        $$->addChild($2);
        
        $$->val_type_flag=$1->val_type_flag;

        check_CAL_math_negtivenum($$);
    }

    | expr AND expr{
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_AND;
        
        $$->addChild($1);
        $$->addChild($3);

        $$->val_type_flag='b';//??----------

        check_CAL_logical($$);
    }
    | expr OR expr{
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_OR;

        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag='b';//??----------

        check_CAL_logical($$);
    }
    | NOT expr{
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_NOT;

        $$->addChild($2);
        $$->val_type_flag='b';//??----------

        check_CAL_logical_not($$);
    }
    | expr LESS_EQ expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_LESS_EQ;

        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag='b';//??----------

        check_CAL_logical($$);
    }
    | expr LESS_THAN expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_LESS_THAN;

        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag='b';//??----------

        check_CAL_logical($$);
    }
    | expr MORE_EQ expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_MORE_EQ;

        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag='b';//??----------

        check_CAL_logical($$);
    }
    | expr MORE_THAN expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_MORE_THAN;

        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag='b';//??----------

        check_CAL_logical($$);
    }
    | expr NOT_EQ expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_NOT_EQ;

        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag='b';//??----------

        check_CAL_logical($$);
    }
    | expr EQ expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_EQ;

        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag='b';//??----------

        check_CAL_logical($$);
    }
    ;


decl_stmt:
    Type ID ASSIGN expr{ 
        // declare and init    int a = 1;
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL_V;

        $$->addChild($1);
        $1->addChild($2);

        $2->val_type_flag=ValType_name[$1->type->type][0];// i b c s 
        // cout<<$2->val_type_flag<<endl;

        /*************************TYPE__CHECK————TYPE__TRANS************************************/
        //类型转换！！！！！！！！？？？？？？？
        type_trans($4);
        $2->addChild($4); 

        check_decl($2);
        check_decl_type($4);
    }
    | Type ID {
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL_V;

        $$->addChild($1);
        $1->addChild($2);

        $2->val_type_flag=ValType_name[$1->type->type][0];

        /*************************TYPE__CHECK************************************/
        check_decl($2);
    }
    | decl_stmt COMMA ID ASSIGN expr{
        $$ = $1;
        $$->child->addChild($3);
        
        $3->val_type_flag=ValType_name[$3->father->type->type][0];
        /*************************TYPE__CHECK————TYPE__TRANS************************************/
        type_trans($5);
        $3->addChild($5);

        check_decl($3);
        check_decl_type($5);
    }
    | decl_stmt COMMA ID{
        $$ = $1;
        $$->child->addChild($3);

        $3->val_type_flag=ValType_name[$3->father->type->type][0];
        /*************************TYPE__CHECK************************************/
        check_decl($3);
    }
    

    | Type MUL ID ASSIGN b_AND %prec POINTER expr {  
        // declare and init
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL_P;
        $$->addChild($1);
        $1->addChild($3);
        $3->addChild($6); 

        //$3->val_type_flag=ValType_name[$3->father->type->type][0];

        /*************************TYPE__CHECK************************************/
        check_decl($3);
    } 
    | Type MUL %prec POINTER ID {
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL_P;
        $$->addChild($1);
        $1->addChild($3);

        //$3->val_type_flag=ValType_name[$3->father->type->type][0];

        /*************************TYPE__CHECK************************************/
        check_decl($3);
    }
    | Type b_AND ID ASSIGN ID %prec GET_ADDRESS{
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL_R;
        $$->addChild($1);
        $1->addChild($3);
        $1->addChild($5);

        //$3->val_type_flag=ValType_name[$3->father->type->type][0];

        /*************************TYPE__CHECK************************************/
        check_decl($3);

        if(cur_table->tmap.count($5->var_name)==0)
        {
            cout <<$$->lineno<<" : 引用的变量未定义！！！"<<endl;
        }
    }
    | array_decl {$$=$1;}
    ;

    

assign_stmt:
    base_assign_stmt{$$=$1;}
    
    |ID ADD_ASSIGN expr{
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_ADD_ASSIGN;
        $$->addChild($1);
        $$->addChild($3);
        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID($1);
    }
    |ID SUB_ASSIGN expr{
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_SUB_ASSIGN;
        $$->addChild($1);
        $$->addChild($3);
        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID($1);
        check_assign_type($1);
    }
    |ID MUL_ASSIGN expr{
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_MUL_ASSIGN;
        $$->addChild($1);
        $$->addChild($3);
        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID($1);
        check_assign_type($1);
    }
    |ID DIV_ASSIGN expr{
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DIV_ASSIGN;
        $$->addChild($1);
        $$->addChild($3);
        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID($1);
        check_assign_type($1);
    }
    | expr SELF_ADD {
        $$ = new TreeNode(lineno, NODE_STMT); $$->stmt_type = STMT_SELF_ADD_ASSIGN;

        $$->addChild($1);
        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID($1);
        }
    | expr SELF_SUB {
        $$ = new TreeNode(lineno, NODE_STMT); $$->stmt_type = STMT_SELF_SUB_ASSIGN;

        $$->addChild($1);
        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID($1);
        }
    ;



base_assign_stmt:
    ID ASSIGN expr {
        $$ = new TreeNode(lineno, NODE_STMT);
        $$->stmt_type = STMT_ASSIGN;
        $$->addChild($1);
        $$->addChild($3);

        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID($1);
        check_assign_type($1);
        // cout<<$1->val_type_flag<<endl;
        // cout<<$3->val_type_flag<<endl;
        
    }
    |ID ASSIGN base_assign_stmt {//a=b=3;!!!!
        $$ = new TreeNode(lineno, NODE_STMT);
        $$->stmt_type = STMT_ASSIGN;
        $$->addChild($1);
        $$->addChild($3);

        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID($1);
        check_assign_type($1);
        // cout<<$1->val_type_flag<<endl;
        // cout<<$3->val_type_flag<<endl;
        
    }
    ;

IO_stmt:
    PRINTF LPAREN STRING COMMA O_expr RPAREN {
            $$ = new TreeNode(lineno, NODE_STMT);
            $$->stmt_type=STMT_PRINTF;
            $$->addChild($3);
            $$->addChild($5);
        }
    | PRINTF LPAREN STRING RPAREN {
            $$ = new TreeNode(lineno, NODE_STMT);
            $$->stmt_type=STMT_PRINTF;
            $$->addChild($3);
        }

    |SCANF LPAREN STRING COMMA I_expr RPAREN {
            $$ = new TreeNode(lineno, NODE_STMT);
            $$->stmt_type=STMT_SCANF;
            $$->addChild($3);
            $$->addChild($5);
        }
        ;
O_expr:
    expr {
        $$ = new TreeNode(lineno, NODE_BLOCK);
        $$->addChild($1);
    }
    | O_expr COMMA expr {
        $$->addChild($3);

    }
    ;
I_expr:
    b_AND expr {
        $$ = new TreeNode(lineno, NODE_BLOCK);
        $$->addChild($2);
    }
    | I_expr COMMA b_AND expr {
        $$->addChild($4);

    }
    ;
if_else_while_for_stmt:
    if_else_stmt{$$=$1;}
    | WHILE LPAREN expr RPAREN statement {
        //while expr stmt
        $$ = new TreeNode($3->lineno, NODE_STMT);
        $$->stmt_type=STMT_WHILE;

        $$->addChild($3);
        $$->addChild($5);

        check_control_stmt($$);
    }
    | FOR LPAREN for_expr_1 SEMICOLON for_expr_2 SEMICOLON for_expr_3 RPAREN
      statement{
        $$ = new TreeNode($3->lineno, NODE_STMT);
        $$->stmt_type=STMT_FOR;
        $$->addChild($3);
        $$->addChild($5);
        $$->addChild($7);
        $$->addChild($9);

        check_for_stmt($$);
        }
    ;

    if_else_stmt:
    IF LPAREN expr RPAREN statement {
        // cout<<"if !!"<<endl;
        //这里不能用$1,要么直接lineno 要么$3->lineno

        //if ( expr ) stmt 
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type=STMT_IF;
        $$->addChild($3);

        if($5->nodeType!=NODE_BLOCK)
        {
            TreeNode* t = new TreeNode($5->lineno, NODE_BLOCK);
            t->addChild($5);
            $$->addChild(t);
        }
        else
            $$->addChild($5);

        /************************TYPE_CHECK*****************************/
        check_control_stmt($$);
    }
    |IF LPAREN expr RPAREN  statement  ELSE  statement  {
        //if  expr  stmt1  stmt2
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type=STMT_IF_ELSE;

        $$->addChild($3);
        if($5->nodeType!=NODE_BLOCK)
        {
            TreeNode* t = new TreeNode($5->lineno, NODE_BLOCK);
            t->addChild($5);
            $$->addChild(t);
        }
        else
            $$->addChild($5);
        if($7->nodeType!=NODE_BLOCK)
        {
            TreeNode* t = new TreeNode($7->lineno, NODE_BLOCK);
            t->addChild($7);
            $$->addChild(t);
        }
        else 
            $$->addChild($7);

        check_control_stmt($$);
    }
    | if_else_if ELSE statement {
        $$=$1;
        //给else也加个头节点
        TreeNode* else_block = new TreeNode($3->lineno, NODE_BLOCK);
        $$->addChild(else_block);
        if($3->nodeType!=NODE_BLOCK)
        {
            TreeNode* t = new TreeNode($3->lineno, NODE_BLOCK);
            t->addChild($3);
            else_block->addChild(t);
        }
        else
            else_block->addChild($3);
    };

        if_else_if:
        IF LPAREN expr RPAREN statement ELSE_IF LPAREN expr RPAREN statement {
            $$ = new TreeNode($3->lineno, NODE_STMT);
            $$->stmt_type=STMT_IF_ELSE_IF;

            $$->addChild($3);
            if($5->nodeType!=NODE_BLOCK)
            {
                TreeNode* t = new TreeNode($5->lineno, NODE_BLOCK);
                t->addChild($5);
                $3->addChild(t);
            }
            else
                $3->addChild($5);

            $$->addChild($8);
            if($10->nodeType!=NODE_BLOCK)
            {
                TreeNode* t = new TreeNode($10->lineno, NODE_BLOCK);
                t->addChild($10);
                $8->addChild(t);
            }
            else
                $8->addChild($10);
        }
        | if_else_if ELSE_IF LPAREN expr RPAREN statement{
            $$=$1;

            $$->addChild($4);

            if($6->nodeType!=NODE_BLOCK)
            {
                TreeNode* t = new TreeNode($6->lineno, NODE_BLOCK);
                t->addChild($6);
                $4->addChild(t);
            }
            else
                $4->addChild($6);

        }
        ;



for_expr_1: 
    decl_stmt{$$=$1;}|assign_stmt{$$=$1;}|{$$=new TreeNode(lineno,NODE_STMT);$$->stmt_type=STMT_SKIP;};
for_expr_2:
    expr{$$=$1;}|{$$=new TreeNode(lineno,NODE_STMT);$$->stmt_type=STMT_SKIP;};
for_expr_3:
    assign_stmt{$$=$1;}|{$$=new TreeNode(lineno,NODE_STMT);$$->stmt_type=STMT_SKIP;};

Type: 
    T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT;} 
    | T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CHAR;}
    | T_BOOL {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_BOOL;}
    | T_STRING {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_STRING;}
    | T_VOID {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_VOID;}
    | CONST T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CONST_INT;}
    | CONST T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CONST_CHAR;}
    ;


INT_CONST:
    INTEGER_H {$$=$1;}
    | INTEGER_D {$$=$1;}
    | INTEGER_O {$$=$1;}
    | INTEGER_B {$$=$1;}
    ;


array_decl:
     Type ARRAY ASSIGN arr_assign_expr  {
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL_A;
        $$->addChild($1);
        $1->addChild($2);
        $2->arr_len=$2->child->int_val;
        $2->init_len=ele_num;//ele_num:实际初始化的元素数量
        // cout<<$2->init_len<<" "<<$2->arr_len<<endl;

        TreeNode* t=$4->child;
        int i=ele_num-1;
        while(i--)
        {
            t=t->sibling;
        }
        //这样很浪费空间，先这样吧,先只支持int
        while(ele_num<$2->child->int_val)
        {
            TreeNode* tmp=new TreeNode($4->lineno,NODE_CONST);
            t->child=tmp;
            t=tmp;
            ele_num++;
            t->int_val=0;
        }
        $2->addChild($4);

        //$2->val_type_flag=ValType_name[$2->father->type->type][0];
        /*************************TYPE__CHECK************************************/
        check_decl($2);

    } 
    | Type ARRAY {
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL_A;

        $$->addChild($1);
        $1->addChild($2);

        /*************************TYPE__CHECK************************************/
        check_decl($2);

    } 
    ;
ARRAY:
    IDENTIFIER LMPAREN INTEGER_D RMPAREN{
        $$=$1;
        $$->nodeType=NODE_ARR;
        $$->addChild($3);
    }
    |ARRAY LMPAREN INTEGER_D RMPAREN{
        $$=$1;
        $$->addChild($3);
    }
    ;
arr_assign_expr:
    LBRACE arr_element RBRACE{$$ = $2;}
    ;
arr_element:
    arr_ele{
        ele_num=1;
        $$ = new TreeNode($1->lineno, NODE_STMT);//???
        $$->addChild($1);

    }
    | arr_element COMMA arr_ele {
        $$->addChild($3);
        ele_num++;
    }
    ;

arr_ele:
    INT_CONST{$$=$1;}
    | CHAR{$$=$1;}
    | STRING{$$=$1;}
    ;


ID:
    IDENTIFIER{$$=$1;}
    | IDENTIFIER LMPAREN INTEGER_D RMPAREN{
        $$=$1;
        $$->nodeType=NODE_ARR;
        $$->index=$3->int_val;
    }
    ;
    
    

%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
