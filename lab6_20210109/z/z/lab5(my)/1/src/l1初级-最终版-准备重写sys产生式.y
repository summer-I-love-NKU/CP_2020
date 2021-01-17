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
SymTable *cur_tb;
int scopeid=0,n_top=1;
// //-------符号表 版本1 直接使用stack和map-----
// stack<map<string,pair<string,int> > > ST_stack;
// stack<int> NUM_stack;

string ValType_name[10] = {"bool", "int", "char", "string","void","const int","const char","8"};


// //-------------
%}


// %start program//???开始符号？是不是可以默认？之前实验似乎没定义

    //声明or定义or变量等等的类型：int char bool void
    %token T_INT T_CHAR T_BOOL T_VOID CONST
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
    %token IDENTIFIER INTEGER_H INTEGER_DP INTEGER_DN INTEGER_O INTEGER_B CHAR BOOL STRING
    // 关键字 main return for  printf  scanf  while  if else "else if"
    %token MAIN RETURN FOR WHILE IF ELSE ELSE_IF PRINTF SCANF

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

program: 
    Type MAIN LPAREN RPAREN LBRACE fake_1 statements RBRACE {
        root = new TreeNode($1->lineno, NODE_PROG); root->addChild($7);
        //-------------------
                    // // cout<<"------主函数符号表！！！------\n";
                    cout<<"-------level: "<<cur_tb->scope<<"-------"<<endl;
                    for(map<string,pair<string,int> >::iterator iter = cur_tb->tmap.begin(); iter != cur_tb->tmap.end(); iter++)
                    {
                        cout<<iter->first<<":"<<iter->second.first<<"  "<<iter->second.second<<endl;
                    }cout<<endl;
                    //cout<<"------------\n";
                    // //cout<<"}"<<endl;
        //------------------
        }
    ;
    fake_1:{
            //-----------符号表 版本2----
                    // //cout<<"{"<<endl;
                    // map<string,pair<string,int> > tmp;int numtmp=1;
                    // ST_stack.push(tmp);NUM_stack.push(numtmp);
                    // cur_tb->tmap=ST_stack.top();n_top=NUM_stack.top();
            cur_tb=new SymTable(++scopeid);
            //-------------------
        };

statements:
    statement {
        $$ = new TreeNode(lineno, NODE_STMT);
        $$=$1;
    }
    | statements statement 
    {   
        $$=$1;
        $$->addSibling($2);
    }
    ;

statement:
    SEMICOLON  {$$ = new TreeNode(lineno, NODE_STMT); $$->stmt_type = STMT_SKIP;}
    | decl_stmt   SEMICOLON {$$ = $1;}
    | assign_stmt SEMICOLON {$$=$1;}
    | IO_stmt SEMICOLON {$$=$1;}
    | if_else_while_for_stmt {$$=$1;}
    | LBRACE fake_2 statements RBRACE {
        //语句加一个总的根结点，解决问题
        $$ = new TreeNode($3->lineno, NODE_STMT);
        $$->stmt_type=STMT_BLOCK;
        $$->addChild($3);
        //-----------------符号表 版本2--------------------
                        // // cout<<"------------\n";
                    cout<<"-------level: "<<cur_tb->scope<<"-------"<<endl;
                    for(SymTable* t=cur_tb;t!=nullptr;t=t->father)
                    {
                        cout<<"level"<<t->scope<<":"<<endl;
                        for(map<string,pair<string,int> >::iterator iter = t->tmap.begin(); iter != t->tmap.end(); iter++)
                        {
                            cout<<iter->first<<":"<<iter->second.first<<"  "<<iter->second.second<<endl;
                        }
                    }
                       
                    cout<<endl;
                        //cout<<"------------\n";
                        
                        // if(ST_stack.size()>1)
                        // {
                        //     ST_stack.pop();cur_tb->tmap=ST_stack.top();
                        //     // cout<<"弹栈后！！！"<<endl;cout<<"stack size"<<ST_stack.size()<<endl<<"stack empty:"<<ST_stack.empty()
                        //     // <<endl<<"map empty:"<<cur_tb->tmap.empty()<<endl;
                        //         // for(map<string,pair<string,int> >::iterator iter = cur_tb->tmap.begin(); iter != cur_tb->tmap.end(); iter++)
                        //         // {
                        //         //     cout<<iter->first<<":"<<iter->second.first<<"  "<<iter->second.second<<endl;
                        //         // }
                        // }
                        // if(NUM_stack.size()>1)
                        // {
                        //     NUM_stack.pop();
                        //     n_top=NUM_stack.top();
                        // }
        cur_tb=cur_tb->father;
        //-------------------------
        }
    ;
    fake_2:{
            //-------------符号表 版本2------------
                    // //===================更新!!!
                    // ST_stack.pop();ST_stack.push(cur_tb->tmap);

                    // //===============再压栈下一级作用域符号表
                    // map<string,pair<string,int> > tmp;int numtmp=1;
                    // ST_stack.push(tmp);NUM_stack.push(numtmp);
                    // cur_tb->tmap=ST_stack.top();n_top=NUM_stack.top();
            SymTable* t=new SymTable(++scopeid);
            t->father=cur_tb;
            cur_tb=t;
            n_top=1;
            //----------------------------
        };




expr: 
    ID {
        $$ = $1;
    }
    | INT_CONST {
        //注意这部分的int char bool类型常量在词法分析的.l文件就已经定义初始化树结点了！！！
        $$ = $1;
    }
    | CHAR {
        $$ = $1;
    }
    | STRING {
        $$ = $1;
    }
    | BOOL{
        $$ = $1;
    }
    | LPAREN expr RPAREN {
        $$ = $2;
        $$->val_type_flag=$2->val_type_flag;//??----------
        }

    | expr ADD expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_ADD;
        // $$->int_val=$1->int_val+$3->int_val;
        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag=$1->val_type_flag;//??----------
        }
    | expr SUB expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_SUB;
        // $$->int_val=$1->int_val-$3->int_val;
        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag=$1->val_type_flag;//??----------
        }
    | expr MUL expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_MUL;
        // $$->int_val=$1->int_val*$3->int_val;
        $$->addChild($1);
        $$->addChild($3);
        }
    | expr DIV expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_DIV;
        // $$->int_val=$1->int_val/$3->int_val;
        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag=$1->val_type_flag;//??----------
        }
    | expr MOD expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_MOD;
        // $$->int_val=$1->int_val%$3->int_val;
        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag=$1->val_type_flag;//??----------
        }
    |SUB %prec UMINUS expr  {
        // $2就是expr
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_NEG;
        // $$->int_val=-$2->int_val;
        $$->addChild($2);
        $$->val_type_flag=$1->val_type_flag;//??----------
    }

    | expr AND expr{
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_AND;
        // $$->int_val=$1->int_val&&$3->int_val;
        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag='b';//??----------
    }
    | expr OR expr{
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_OR;
        // $$->int_val=$1->int_val||$3->int_val;
        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag='b';//??----------
    }
    | NOT expr{
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_NOT;
        // $$->int_val=!$2->int_val;
        $$->addChild($2);
        $$->val_type_flag='b';//??----------
    }
    | expr LESS_EQ expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_LESS_EQ;
        // $$->int_val=($1->int_val<=$3->int_val);
        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag='b';//??----------
    }
    | expr LESS_THAN expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_LESS_THAN;
        // $$->int_val=($1->int_val<$3->int_val);
        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag='b';//??----------
    }
    | expr MORE_EQ expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_MORE_EQ;
        // $$->int_val=($1->int_val>=$3->int_val);
        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag='b';//??----------
    }
    | expr MORE_THAN expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_MORE_THAN;
        // $$->int_val=($1->int_val>$3->int_val);
        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag='b';//??----------
    }
    | expr NOT_EQ expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_NOT_EQ;
        // $$->int_val=($1->int_val!=$3->int_val);
        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag='b';//??----------
    }
    | expr EQ expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_EQ;
        // $$->int_val=($1->int_val==$3->int_val);
        $$->addChild($1);
        $$->addChild($3);
        $$->val_type_flag='b';//??----------
    }
    ;


decl_stmt:
    Type ID ASSIGN expr{  
        // declare and init
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL_V;
        $$->addChild($1);
        $1->addChild($2);
        //-------类型转换？？？char m=97;-->'a' -----
            if(ValType_name[$1->type->type]=="char"&&$4->val_type_flag=='i')
            {
                $4->ch_val=char($4->int_val);
                $4->val_type_flag='c';
            }
            if(ValType_name[$1->type->type]=="bool"&&$4->val_type_flag!='b')
            {
                $4->b_val=bool($4->int_val)||bool($4->ch_val);
                $4->val_type_flag='b';
            }
        //-----------
        $2->addChild($4); 
        //----------------
        if(cur_tb->tmap.count($2->var_name)==0)
        {
            cur_tb->tmap[$2->var_name]=make_pair(ValType_name[$1->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redefine error!!!"<<endl;
        }
        //-------------
    }
    | Type ID {
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL_V;
        $$->addChild($1);
        $1->addChild($2);
        //--------------------------
        if(cur_tb->tmap.count($2->var_name)==0)
        {
            cur_tb->tmap[$2->var_name]=make_pair(ValType_name[$1->type->type],n_top);
            // cout<<"!!!!"<<$2->var_name<<"  "<< ValType_name[$1->type->type]<<" "<<n_top<<endl;
            // cout<<"当前map中元素个数："<<cur_tb->tmap.size()<<endl;
            n_top++;
        }
        else
        {
            cout<<"redeclare error!!!"<<endl;

        }
        //-----------------------
    }
    | decl_stmt COMMA ID ASSIGN expr{
        $$ = $1;
        $$->child->addChild($3);
        $3->addChild($5);
        //-------类型转换？？？char m=97;-->'a' -----
            if(ValType_name[$$->child->type->type]=="char"&&$5->val_type_flag=='i')
            {
                $5->ch_val=char($5->int_val);
                $5->val_type_flag='c';
            }
            if(ValType_name[$$->child->type->type]=="bool"&&$5->val_type_flag!='b')
            {
                $5->b_val=bool($5->int_val)||bool($5->ch_val);//无法转换字符串，看看规则？？？？
                $5->val_type_flag='b';
            }
        //-------------------------
        //--------------------------
        if(cur_tb->tmap.count($3->var_name)==0)
        {
            cur_tb->tmap[$3->var_name]=make_pair(ValType_name[$1->child->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redefine error!!!"<<endl;
        }
        //-----------------------
    }
    | decl_stmt COMMA ID{
        $$ = $1;
        $$->child->addChild($3);
        //--------------------------
        if(cur_tb->tmap.count($3->var_name)==0)
        {
            cur_tb->tmap[$3->var_name]=make_pair(ValType_name[$1->child->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redeclare error!!!"<<endl;
        }
        //-----------------------
    }
    

    | Type MUL ID ASSIGN b_AND %prec POINTER expr {  
        // declare and init
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL_P;
        $$->addChild($1);
        $1->addChild($3);
        $3->addChild($6); 
        //----------------
        if(cur_tb->tmap.count($3->var_name)==0)
        {
            cur_tb->tmap[$3->var_name]=make_pair(ValType_name[$1->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redefine error!!!"<<endl;
        }
        //-------------
    } 
    | Type MUL %prec POINTER ID {
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL_P;
        $$->addChild($1);
        $1->addChild($3);
        //--------------------------
        if(cur_tb->tmap.count($3->var_name)==0)
        {
            cur_tb->tmap[$3->var_name]=make_pair(ValType_name[$1->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redeclare error!!!"<<endl;

        }
        //-----------------------
    }
    | Type b_AND ID ASSIGN ID %prec GET_ADDRESS{
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL_R;
        $$->addChild($1);
        $1->addChild($3);
        $1->addChild($5);
        //--------------------------
        if(cur_tb->tmap.count($3->var_name)==0)
        {
            cur_tb->tmap[$3->var_name]=make_pair(ValType_name[$1->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redeclare error!!!"<<endl;

        }
        if(cur_tb->tmap.count($5->var_name)==0)
        {
            cout<<"引用的变量未定义！！！"<<endl;
        }
        //-----------------------
    }


    | Type ARRAY ASSIGN arr_assign_expr  {
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL_A;
        $$->addChild($1);
        $1->addChild($2);
        $1->addChild($4);
        //--------------------------
        if(cur_tb->tmap.count($2->var_name)==0)
        {
            cur_tb->tmap[$2->var_name]=make_pair(ValType_name[$1->type->type],n_top);
            // cout<<"!!!!"<<$2->var_name<<"  "<< ValType_name[$1->type->type]<<" "<<n_top<<endl;
            // cout<<"当前map中元素个数："<<cur_tb->tmap.size()<<endl;
            n_top++;
        }
        else
        {
            cout<<"redeclare error!!!"<<endl;

        }
        //-----------------------

    } 
    | Type ARRAY {
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL_A;
        $$->addChild($1);
        $1->addChild($2);
        //--------------------------
        if(cur_tb->tmap.count($2->var_name)==0)
        {
            cur_tb->tmap[$2->var_name]=make_pair(ValType_name[$1->type->type],n_top);
            // cout<<"!!!!"<<$2->var_name<<"  "<< ValType_name[$1->type->type]<<" "<<n_top<<endl;
            // cout<<"当前map中元素个数："<<cur_tb->tmap.size()<<endl;
            n_top++;
        }
        else
        {
            cout<<"redeclare error!!!"<<endl;

        }
        //-----------------------

    } 
    ;

assign_stmt:
    base_assign_stmt{$$=$1;}
    
    |ID ADD_ASSIGN expr{
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_ADD_ASSIGN;
        $$->addChild($1);
        $$->addChild($3);
        
        // TreeNode* p=$$->child;
        // p->int_val+=p->sibling->int_val;
    }
    |ID SUB_ASSIGN expr{
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_SUB_ASSIGN;
        $$->addChild($1);
        $$->addChild($3);
        
        // TreeNode* p=$$->child;
        // p->int_val-=p->sibling->sibling->int_val;
    }
    |ID MUL_ASSIGN expr{
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_MUL_ASSIGN;
        $$->addChild($1);
        $$->addChild($3);
        
        // TreeNode* p=$$->child;
        // p->int_val*=p->sibling->sibling->int_val;
    }
    |ID DIV_ASSIGN expr{
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DIV_ASSIGN;
        $$->addChild($1);
        $$->addChild($3);
        
        // TreeNode* p=$$->child;
        // p->int_val/=p->sibling->sibling->int_val;
    }
    | expr SELF_ADD {
        $$ = new TreeNode(lineno, NODE_STMT); $$->stmt_type = STMT_SELF_ADD_ASSIGN;
        // $$->int_val=$1->int_val+1;
        $$->addChild($1);
        }
    | expr SELF_SUB {
        $$ = new TreeNode(lineno, NODE_STMT); $$->stmt_type = STMT_SELF_SUB_ASSIGN;
        // $$->int_val=$1->int_val-1;
        $$->addChild($1);
        }
    ;



base_assign_stmt:
    ID ASSIGN expr {
        $$ = new TreeNode(lineno, NODE_STMT);
        $$->stmt_type = STMT_ASSIGN;
        $$->addChild($1);
        $$->addChild($3);

        // //赋值操作，无论是什么类型，都赋过来就好了
        // $1->int_val=$3->int_val;
        // $1->ch_val=$3->ch_val;
        // $1->str_val=$3->str_val;
    }
    ;

IO_stmt:
    PRINTF LPAREN STRING COMMA O_expr RPAREN {
            $$ = new TreeNode(lineno, NODE_STMT);
            $$->stmt_type=STMT_PRINTF;
            $$->addChild($3);
            $$->addChild($5);
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
        $$ = new TreeNode(lineno, NODE_STMT);
        $$->addChild($1);
    }
    | O_expr COMMA expr {
        $$->addChild($3);

    }
    ;
I_expr:
    b_AND expr {
        $$ = new TreeNode(lineno, NODE_STMT);
        $$->addChild($2);
    }
    | I_expr COMMA b_AND expr {
        $$->addChild($4);

    }
    ;
if_else_while_for_stmt:
    IF LPAREN expr RPAREN statement {
        // cout<<"if !!"<<endl;
        //这里不能用$1,要么直接lineno 要么$3->lineno
        $$ = new TreeNode($3->lineno, NODE_STMT);
        $$->stmt_type=STMT_IF;
        $$->addChild($3);
        $$->addChild($5);
    }
    |IF LPAREN expr RPAREN  statement  ELSE  statement  {
        //这里不能用$1,要么直接lineno 要么$3->lineno
        $$ = new TreeNode($3->lineno, NODE_STMT);
        $$->stmt_type=STMT_IF_ELSE;
        $$->addChild($3);
        $$->addChild($5);
        $$->addChild($7);
    }
    | WHILE LPAREN expr RPAREN statement {
        $$ = new TreeNode($3->lineno, NODE_STMT);
        $$->stmt_type=STMT_WHILE;
        $$->addChild($3);
        $$->addChild($5);
    }
    | FOR LPAREN for_expr_1 SEMICOLON for_expr_2 SEMICOLON for_expr_3 RPAREN
      statement{
        $$ = new TreeNode($3->lineno, NODE_STMT);
        $$->stmt_type=STMT_FOR;
        $$->addChild($3);
        $$->addChild($5);
        $$->addChild($7);
        $$->addChild($9);
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
INTEGER_D:
    INTEGER_DP{$$=$1;}|INTEGER_DN{$$=$1;};
ARRAY:
    IDENTIFIER LMPAREN INTEGER_DP RMPAREN{
        $$=$1;
        $$->nodeType=NODE_ARR;
        $$->addChild($3);
    }
    |ARRAY LMPAREN INTEGER_DP RMPAREN{
        $$=$1;
        $$->addChild($3);
    }
    ;
arr_assign_expr:
    LBRACE arr_element RBRACE{$$ = $2;}
    ;
arr_element:
    arr_ele{
        $$ = new TreeNode($1->lineno, NODE_STMT);//???
        $$->addChild($1);

    }
    | arr_element COMMA arr_ele {
        $$->addChild($3);
    }
    ;

arr_ele:
    INT_CONST{$$=$1;}
    | CHAR{$$=$1;}
    | STRING{$$=$1;}
    ;


ID:
    IDENTIFIER{$$=$1;}
    ;
    
    

%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
