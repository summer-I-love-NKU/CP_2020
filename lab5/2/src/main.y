%{
    #include "common.h"//包含tree的头文件
    #define YYstmt_type TreeNode *  
    TreeNode* root;TreeNode* p_add_stmt;
    extern int lineno;
    int yylex();
    int yyerror( char const * );
%}
%token T_CHAR T_INT T_STRING T_BOOL 

%token LOP_ASSIGN 

%token SEMICOLON

%token IDENTIFIER INTEGER CHAR BOOL STRING

%left LOP_EQ

%%

program
: statements {root = new TreeNode(0, NODE_PROG); root->addChild($1);};


statements
:  statement 
{
    //第一条语句一定从这里开始！！！在这里初始化p_add_stmt
    $$=$1;
    p_add_stmt=$$;
}
|  statements statement 
{   
    $$=$1;
    p_add_stmt->addSibling($2);
    p_add_stmt=$2;//p_add_stmt=p_add_stmt->sibling;//
}
;

statement
: SEMICOLON  {$$ = new TreeNode(lineno, NODE_STMT); $$->stmt_type = STMT_SKIP;}
| declaration SEMICOLON {$$ = $1;}
;

declaration
: T IDENTIFIER LOP_ASSIGN expr{  
    // declare and init
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stmt_type = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    node->addChild($4);
    $$ = node;   
} 
| T IDENTIFIER {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stmt_type = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    $$ = node;  
}
;

expr
: IDENTIFIER {
    $$ = $1;
}
| INTEGER {
    $$ = $1;
}
| CHAR {
    $$ = $1;
}
| STRING {
    $$ = $1;
}
;

T: T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->decl_type = TYPE_INT;} 
| T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->decl_type = TYPE_CHAR;}
| T_BOOL {$$ = new TreeNode(lineno, NODE_TYPE); $$->decl_type = TYPE_BOOL;}
;

%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}