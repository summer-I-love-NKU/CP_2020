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
//数组的维度
int arr_d_num=0;
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


CompUnit:
    Decl{
        root = new TreeNode($1->lineno, NODE_PROG); 
        root->addChild($1);
        root->printChildrenId();cout<<"Decl"<<endl;
        }
    |Func_Def{
        root = new TreeNode($1->lineno, NODE_PROG); 
        root->addChild($1);
        root->printChildrenId();cout<<"funcdef"<<endl;
        }
    |CompUnit Decl{
        root->addChild($2);}
    |CompUnit Func_Def{
        root->addChild($2);}
    ;

Decl:
    Const_Decl SEMICOLON{$$=$1;}
    |Var_Decl SEMICOLON{
        $$=$1;
        $$->printChildrenId();
        }
    ;   

    Const_Decl:
        CONST BType Const_Def{
            $$ = new TreeNode($1->lineno, NODE_STMT);
            $$->stmt_type = STMT_DECL_C;
            $$->addChild($2);//int
            $2->addChild($3);//a=5
        }
        | Const_Decl COMMA Const_Def{
            $$ = $1;//int
            $$->child->addChild($3);//a=5,b=6
        }
        ;

        
            Const_Def:
                ID ASSIGN NUMBER{
                    $$ = $1;
                    $$->addChild($3);
                }
                |ID ASSIGN STRING{
                    $$ = $1;
                    $$->addChild($3);
                }
                ;
            


                


    Var_Decl:
        BType Var_Def{
            $$ = new TreeNode($1->lineno, NODE_STMT);
            $$->stmt_type = STMT_DECL_V;
            $$->addChild($1);//int
            $$->child->addChild($2);//a=5

            $$->printChildrenId();
        }
        | Var_Decl COMMA Var_Def{
            $$ = $1;//int
            $$->child->addChild($3);//a=5,b=6
        }
        ;

            Var_Def:
                ID ASSIGN Init_Val{
                    $$ = $1;
                    $$->addChild($3);//a=1
                }
                | ID{
                    $$=$1;
                    }
                ;
                
                
                Init_Val:
                    Exp{$$=$1;}
                    |LBRACE arr_element RBRACE{$$=$1;}
                    ;
                        
                    
                    arr_element:
                        arr_ele{
                            $$ = new TreeNode($1->lineno, NODE_CONST);//???
                            $$->addChild($1);}
                        | arr_element COMMA arr_ele {
                            $$=$1;
                            $$->addChild($3);}
                        ;

                    arr_ele:
                        INT_CONST{$$=$1;}
                        | CHAR{$$=$1;}
                        | STRING{$$=$1;}
                        | Init_Val{$$=$1;}
                        ;

                    
                    
                
                
                    
            ID:
                IDENTIFIER{$$=$1;/*已经在.l定义了*/}
                |ID_ARRAY_NAME{$$=$1;}
                ;
                ID_ARRAY_NAME:
                IDENTIFIER LMPAREN INTEGER_DP RMPAREN{
                    $$->nodeType=NODE_ARR;
                    $$->var_name=$1->var_name;
                    arr_d_num=0;//注意重新计数！！！
                    $$->arr_d[arr_d_num++]=$3->int_val;
                    }
                |ID_ARRAY_NAME LMPAREN INTEGER_DP RMPAREN{
                    $$->nodeType=NODE_ARR;
                    $$->var_name=$1->var_name;
                    $$->arr_d[arr_d_num++]=$3->int_val;
                    }
                    ;


                BType: 
                    T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT;} 
                    | T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CHAR;}
                    ;


Func_Def:
    T_INT ID LPAREN Func_Params RPAREN Block{
        $$=new TreeNode($1->lineno,NODE_FUNC);
        $$->func_type=TYPE_INT;
        $$->func_name=$2->var_name;
        $$->addChild($4);
        $$->addChild($6);

        cout<<"hanshu!!!"<<endl;
        $$->printChildrenId();
    }
    |T_VOID ID LPAREN Func_Params RPAREN Block{
        
    }
    |T_INT MAIN LPAREN RPAREN Block{
        $$=new TreeNode($1->lineno,NODE_FUNC);
        $$->func_type=TYPE_INT;
        $$->func_name="main";
        $$->addChild($5);

        cout<<"hanshu!!!"<<endl;
        $$->printChildrenId();
    }
    |T_VOID MAIN LPAREN RPAREN Block{

        }
        ;

        Func_Params:
            Func_Param{
                $$=new TreeNode($1->lineno,NODE_PARA);
                $$->addChild($1);//param-int-a
            }
            | Func_Params COMMA Func_Param{
                $$=$1;
                $$->addChild($3);
            }
            |{
                $$=new TreeNode(lineno,NODE_NULL);cout<<"NULLnode"<<endl;
            }
            ;

            Func_Param:
                BType ID{
                    $$=$1;
                    $$->addChild($2);// int--a
                }
                ;

Block:
    LBRACE Block_Item RBRACE{$$=$2;};
	
	Block_Item:
		base_Block_Item{
            $$=new TreeNode($1->lineno,NODE_BLOCK);
            $$->addChild($1);
		}
		| Block_Item base_Block_Item{
            $$=$1;
            $$->addChild($2);
        }
		;

            base_Block_Item:
                Decl{
                    $$=$1;
                    cout<<"decl!"<<endl;
                }
                |Stmt{
                    $$=$1;
                }
                ;


Stmt:
    LVal ASSIGN Exp {
        $$=new TreeNode($1->lineno,NODE_STMT);
        $$->stmt_type=STMT_ASSIGN;
        $$->addChild($1);
        $$->addChild($3);
    }
    | Block{$$=$1;}
    ;




PrimaryExp:
    LPAREN Exp RPAREN{$$=$2;}
    | LVal{$$=$1;}
    | NUMBER {
        $$=$1;
        cout<<"number!"<<endl;
    }
    ;

    LVal:ID {$$=$1;};
    NUMBER:INT_CONST{$$=$1;};
    Exp:AddExp{$$=$1;
    };


                INT_CONST:
                    INTEGER_H {$$=$1;}
                    | INTEGER_D {$$=$1;}
                    | INTEGER_O {$$=$1;}
                    | INTEGER_B {$$=$1;}
                    ;

                INTEGER_D:
                    INTEGER_DP{$$=$1;}|INTEGER_DN{$$=$1;};


UnaryExp:
    PrimaryExp{$$=$1;}
    | ADD UnaryExp{
        $$=$2;
    }
    | SUB %prec UMINUS UnaryExp{
        $$->op_type=OP_SUB;
        $$->addChild($2);
    }
    | NOT UnaryExp{
        $$->op_type=OP_NOT;
        $$->addChild($2);
    }
    ;


MulExp:
    UnaryExp{$$=$1;}
    | MulExp MUL UnaryExp{
        $$->addChild($1);
        $$->addChild($3);
        $$->op_type=OP_MUL;
    }
    | MulExp DIV UnaryExp{
        $$->addChild($1);
        $$->addChild($3);
        $$->op_type=OP_DIV;
    }
    | MulExp MOD UnaryExp{
        $$->addChild($1);
        $$->addChild($3);
        $$->op_type=OP_MOD;
    }
    ;
AddExp:
    MulExp{$$=$1;}
    | AddExp ADD MulExp{
        $$->addChild($1);
        $$->addChild($3);
        $$->op_type=OP_ADD;
    }
    | AddExp SUB MulExp{
        $$->addChild($1);
        $$->addChild($3);
        $$->op_type=OP_SUB;
    }
    ;



%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
