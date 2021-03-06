%{
//定义段
//规则段
//辅助函数段
#include "common.h"//包含tree的头文件
#define YYstmt_type TreeNode *  
TreeNode* root;//需要extern吗？？？
TreeNode* p_add_stmt;
extern int lineno;
int yylex();
int yyerror( char const * );
// //------------
stack<map<string,pair<string,int> > > ST_stack;
stack<int> NUM_stack;
map<string,pair<string,int> > t_top;
int n_top;
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
    // ; ,  .  (){}
    %token SEMICOLON COMMA DOT LPAREN RPAREN LBRACE RBRACE
    //ID  integer(16 10 8 2) char bool string 字符 数字 标识符 字符串 等等
    %token IDENTIFIER INTEGER_H INTEGER_D INTEGER_O INTEGER_B CHAR BOOL STRING
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
    //负号 - ! ~  前自增 前自减++ --  取地址运算&
    %right UMINUS NOT b_NOT pre_SELF_ADD pre_SELF_SUB GET_ADDRESS
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
        cout<<"------主函数符号表！！！------\n";
        for(map<string,pair<string,int> >::iterator iter = t_top.begin(); iter != t_top.end(); iter++)
        {
            cout<<iter->first<<":"<<iter->second.first<<"  "<<iter->second.second<<endl;
        }cout<<"------------\n";
        cout<<"}"<<endl;
        //------------------
        }
    ;
fake_1:{
        //---------------
        cout<<"{"<<endl;
        map<string,pair<string,int> > tmp;int numtmp=1;
        ST_stack.push(tmp);NUM_stack.push(numtmp);
        t_top=ST_stack.top();n_top=NUM_stack.top();
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
        //-------------------------------------
            cout<<"------------\n";
            cout<<"显示啊！！！"<<endl;
            for(map<string,pair<string,int> >::iterator iter = t_top.begin(); iter != t_top.end(); iter++)
            {
                cout<<iter->first<<":"<<iter->second.first<<"  "<<iter->second.second<<endl;
            }cout<<"------------\n";
            
            if(ST_stack.size()>1)
            {
                ST_stack.pop();t_top=ST_stack.top();
                // cout<<"弹栈后！！！"<<endl;cout<<"stack size"<<ST_stack.size()<<endl<<"stack empty:"<<ST_stack.empty()
                // <<endl<<"map empty:"<<t_top.empty()<<endl;
                    // for(map<string,pair<string,int> >::iterator iter = t_top.begin(); iter != t_top.end(); iter++)
                    // {
                    //     cout<<iter->first<<":"<<iter->second.first<<"  "<<iter->second.second<<endl;
                    // }
            }
            if(NUM_stack.size()>1)
            {
                NUM_stack.pop();
                n_top=NUM_stack.top();
            }
        //-------------------------
        }
    ;
fake_2:{
        //-------------------------
        //===================更新!!!
        ST_stack.pop();ST_stack.push(t_top);

        //===============再压栈下一级作用域符号表
        map<string,pair<string,int> > tmp;int numtmp=1;
        ST_stack.push(tmp);NUM_stack.push(numtmp);
        t_top=ST_stack.top();n_top=NUM_stack.top();
        //----------------------------
    };


expr: 
    IDENTIFIER {
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
    |SUB expr %prec UMINUS {
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
    Type IDENTIFIER ASSIGN expr{  
        // declare and init
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL;
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
        if(t_top.count($2->var_name)==0)
        {
            t_top[$2->var_name]=make_pair(ValType_name[$1->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redefine error!!!"<<endl;
        }
        //-------------
    } 
    | Type IDENTIFIER {
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL;
        $$->addChild($1);
        $1->addChild($2);
        //--------------------------
        if(t_top.count($2->var_name)==0)
        {
            t_top[$2->var_name]=make_pair(ValType_name[$1->type->type],n_top);
            // cout<<"!!!!"<<$2->var_name<<"  "<< ValType_name[$1->type->type]<<" "<<n_top<<endl;
            // cout<<"当前map中元素个数："<<t_top.size()<<endl;
            n_top++;
        }
        else
        {
            cout<<"redeclare error!!!"<<endl;

        }
        //-----------------------
    }
    | decl_stmt COMMA IDENTIFIER{
        $$ = $1;
        $$->child->addChild($3);
        //--------------------------
        if(t_top.count($3->var_name)==0)
        {
            t_top[$3->var_name]=make_pair(ValType_name[$1->child->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redeclare error!!!"<<endl;
        }
        //-----------------------
    }
    | decl_stmt COMMA IDENTIFIER ASSIGN expr{
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
        if(t_top.count($3->var_name)==0)
        {
            t_top[$3->var_name]=make_pair(ValType_name[$1->child->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redefine error!!!"<<endl;
        }
        //-----------------------
    }
    ;


assign_stmt:
    IDENTIFIER ASSIGN expr {
        $$ = new TreeNode(lineno, NODE_STMT);
        $$->stmt_type = STMT_ASSIGN;
        $$->addChild($1);
        $$->addChild($3);

        // //赋值操作，无论是什么类型，都赋过来就好了
        // $1->int_val=$3->int_val;
        // $1->ch_val=$3->ch_val;
        // $1->str_val=$3->str_val;
    }
    |IDENTIFIER ADD_ASSIGN expr{
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_ADD_ASSIGN;
        $$->addChild($1);
        $$->addChild($3);
        
        // TreeNode* p=$$->child;
        // p->int_val+=p->sibling->int_val;
    }
    |IDENTIFIER SUB_ASSIGN expr{
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_SUB_ASSIGN;
        $$->addChild($1);
        $$->addChild($3);
        
        // TreeNode* p=$$->child;
        // p->int_val-=p->sibling->sibling->int_val;
    }
    |IDENTIFIER MUL_ASSIGN expr{
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_MUL_ASSIGN;
        $$->addChild($1);
        $$->addChild($3);
        
        // TreeNode* p=$$->child;
        // p->int_val*=p->sibling->sibling->int_val;
    }
    |IDENTIFIER DIV_ASSIGN expr{
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

IO_stmt:
    PRINTF LPAREN STRING COMMA expr RPAREN {
            $$ = new TreeNode(lineno, NODE_STMT);
            $$->stmt_type=STMT_PRINTF;
            $$->addChild($3);
            $$->addChild($5);
        }
    |SCANF LPAREN STRING COMMA b_AND %prec GET_ADDRESS expr RPAREN {
            $$ = new TreeNode(lineno, NODE_STMT);
            $$->stmt_type=STMT_SCANF;
            $$->addChild($3);
            $$->addChild($6);
        }
        ;

for_expr_1: 
    decl_stmt|assign_stmt|;
for_expr_2:
    expr|;
for_expr_3:
    assign_stmt|;

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


    
    

%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
