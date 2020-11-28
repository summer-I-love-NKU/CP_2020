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
%}


// %start program//???开始符号？是不是可以默认？之前实验似乎没定义

//声明or定义or变量等等的类型：int char string bool
%token T_INT T_CHAR T_STRING T_BOOL 
//赋值 = += -= *= /=
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
// 比较 == != >= > <= <
%token EQ NOT_EQ LESS_THAN LESS_EQ MORE_THAN MORE_EQ
//------------注意匹配顺序！！！ == =，!= !, <= <,----------------

//逻辑操作 && || !
%token AND OR NOT 
//运算 + - * / % ++ --
%token ADD SUB MUL DIV MOD SELF_ADD SELF_SUB
//; (){}
%token SEMICOLON LPAREN RPAREN LBRACE RBRACE
//ID  integer char bool string 字符 数字 标识符 字符串 等等
%token IDENTIFIER INTEGER CHAR BOOL STRING
// 关键字 printf  scanf  while  if else
%token WHILE IF ELSE PRINTF SCANF

//!!!后定义的优先级高！！！ 
%right ASSIGN
%left EQ NOT_EQ
%left ADD SUB
%left MUL DIV MOD 
%right UMINUS
%right NOT
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

    
| if_else_stmt SEMICOLON {$$=$1;}
| while_stmt SEMICOLON {$$=$1;}   

bool_statment: 
    LPAREN bool_expr RPAREN {$$=$2;};
if_else_stmt: 
    IF bool_statment LBRACE statements RBRACE {//%prec LOWER_THEN_ELSE
    cout<<"!!!"<<endl;
    $2->printNodeInfo();$4->printNodeInfo();$5->printNodeInfo();
    //不要使用$1->lineno!!!!
            $$ = new TreeNode(lineno, NODE_STMT);
            $$->stmt_type=STMT_IF;
            $$->addChild($2);
            $$->addChild($4);
        }
        | IF bool_statment statement ELSE statement {
            
            $$ = new TreeNode(lineno, NODE_STMT);
            $$->stmt_type=STMT_IF_ELSE;
            $$->addChild($2);
            $$->addChild($3);
            $$->addChild($5);
        }
        ;
while_stmt:
    WHILE LPAREN bool_expr RPAREN LBRACE statement RBRACE {
            $$ = new TreeNode($1->lineno, NODE_STMT);
            $$->stmt_type=STMT_WHILE;
            $$->addChild($3);
            $$->addChild($6);
        }
        ;
*/
%%

program: 
statements {root = new TreeNode(0, NODE_PROG); root->addChild($1);};


statements:
    statement {
        //第一条语句一定从这里开始！！！在这里初始化p_add_stmt
        $$ = new TreeNode(lineno, NODE_STMT);
        $$=$1;
        p_add_stmt=$$;
    }
    |  statements statement 
    {   
        $$=$1;
        p_add_stmt->addSibling($2);
        p_add_stmt=$2;//等同于p_add_stmt=p_add_stmt->sibling;
    }
    ;

statement:
    | SEMICOLON  {$$ = new TreeNode(lineno, NODE_STMT); $$->stmt_type = STMT_SKIP;}
    | decl_stmt   SEMICOLON {$$ = $1;}
    | assign_stmt SEMICOLON {$$=$1;}
    | self_op_stmt SEMICOLON {$$=$1;}
    | IO_stmt SEMICOLON {$$=$1;}
    | if_else_while_stmt {$$=$1;}
    | LBRACE statements RBRACE {
        //语句加一个总的根结点，解决问题
        $$ = new TreeNode(lineno, NODE_STMT);
        $$->addChild($2);
        }
    ;


expr: 
    IDENTIFIER {
        $$ = $1;
    }
    | INTEGER {
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
        }
    | expr SUB expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_SUB;
        // $$->int_val=$1->int_val-$3->int_val;
        $$->addChild($1);
        $$->addChild($3);
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
        }
    | expr MOD expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_MOD;
        // $$->int_val=$1->int_val%$3->int_val;
        $$->addChild($1);
        $$->addChild($3);
        }
    |SUB expr %prec UMINUS {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_NEG;
        // $$->int_val=-$2->int_val;
        $$->addChild($2);
    }

    | expr AND expr{
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_AND;
        // $$->int_val=$1->int_val&&$3->int_val;
        $$->addChild($1);
        $$->addChild($3);
    }
    | expr OR expr{
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_OR;
        // $$->int_val=$1->int_val||$3->int_val;
        $$->addChild($1);
        $$->addChild($3);
    }
    | NOT expr{
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_NOT;
        // $$->int_val=!$2->int_val;
        $$->addChild($2);
    }
    | expr LESS_EQ expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_LESS_EQ;
        // $$->int_val=($1->int_val<=$3->int_val);
        $$->addChild($1);
        $$->addChild($3);
    }
    | expr LESS_THAN expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_LESS_THAN;
        // $$->int_val=($1->int_val<$3->int_val);
        $$->addChild($1);
        $$->addChild($3);
    }
    | expr MORE_EQ expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_MORE_EQ;
        // $$->int_val=($1->int_val>=$3->int_val);
        $$->addChild($1);
        $$->addChild($3);
    }
    | expr MORE_THAN expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_MORE_THAN;
        // $$->int_val=($1->int_val>$3->int_val);
        $$->addChild($1);
        $$->addChild($3);
    }
    | expr NOT_EQ expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_NOT_EQ;
        // $$->int_val=($1->int_val!=$3->int_val);
        $$->addChild($1);
        $$->addChild($3);
    }
    | expr EQ expr {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_EQ;
        // $$->int_val=($1->int_val==$3->int_val);
        $$->addChild($1);
        $$->addChild($3);
    }
    ;
decl_stmt: 
    Type IDENTIFIER ASSIGN expr{  
        // declare and init
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL;
        $$->addChild($1);
        $$->addChild($2);
        $$->addChild($4); 

        // //赋值操作，无论是什么类型，都赋过来就好了
        // $2->int_val=$4->int_val;
        // $2->ch_val=$4->ch_val;
        // $2->str_val=$4->str_val;
    } 
    | Type IDENTIFIER {
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DECL;
        $$->addChild($1);
        $$->addChild($2);
    }
    ;




self_op_stmt:
    
    expr SELF_ADD {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_SELF_ADD;
        // $$->int_val=$1->int_val+1;
        $$->addChild($1);
        }
    | expr SELF_SUB {
        $$ = new TreeNode(lineno, NODE_EXPR); $$->op_type = OP_SELF_SUB;
        // $$->int_val=$1->int_val-1;
        $$->addChild($1);
        }
    ;

assign_stmt:
    IDENTIFIER ASSIGN expr{
        $$ = new TreeNode($1->lineno, NODE_STMT);
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
        $$->addChild($1);
        $$->addChild($3);
        
        // TreeNode* p=$$->child;
        // p->int_val-=p->sibling->sibling->int_val;
    }
    |IDENTIFIER MUL_ASSIGN expr{
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_MUL_ASSIGN;
        $$->addChild($1);
        $$->addChild($1);
        $$->addChild($3);
        
        // TreeNode* p=$$->child;
        // p->int_val*=p->sibling->sibling->int_val;
    }
    |IDENTIFIER DIV_ASSIGN expr{
        $$ = new TreeNode($1->lineno, NODE_STMT);
        $$->stmt_type = STMT_DIV_ASSIGN;
        $$->addChild($1);
        $$->addChild($1);
        $$->addChild($3);
        
        // TreeNode* p=$$->child;
        // p->int_val/=p->sibling->sibling->int_val;
    }
    ;

IO_stmt:
    PRINTF LPAREN expr RPAREN {
            $$ = new TreeNode(lineno, NODE_STMT);
            $$->stmt_type=STMT_PRINTF;
            $$->addChild($3);
        }
    |SCANF LPAREN expr RPAREN {
            $$ = new TreeNode(lineno, NODE_STMT);
            $$->stmt_type=STMT_SCANF;
            $$->addChild($3);
        }
        ;
if_else_while_stmt:
    IF LPAREN expr RPAREN statement {
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
    | WHILE LPAREN expr RPAREN  statement {
        $$ = new TreeNode($3->lineno, NODE_STMT);
        $$->stmt_type=STMT_WHILE;
        $$->addChild($3);
        $$->addChild($5);
    }
    ;



Type: 
    T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT;} 
    | T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CHAR;}
    | T_BOOL {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_BOOL;}
    ;


    
    

%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}