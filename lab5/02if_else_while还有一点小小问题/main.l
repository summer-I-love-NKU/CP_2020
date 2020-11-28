%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header，这里是不是就将flex和yacc联系起来了

int lineno=1;

/*
词法分析的token给语法分析用？？？

这里的块注释更复杂了？
{BLOCKCOMMENT}  do nothing ??我改一下？
记录行号？？
BLOCKCOMMENT \/\*([^\*^\/]*|[\*^\/*]*|[^\**\/]*)*\*\/

node->ch_val = yytext[1];???

注意bool的识别要在ID 之前！！！{BOOL}{。。。}  {ID}{。。。}

一定注意，最长前缀原则————先识别： ==  而不是 = ， ！= 而不是！，++而不是+，。。。

*/

%}


%x BLOCK_COMMENT
%x LINE_COMMENT

EOL	(\r\n|\r|\n)
WHILTESPACE [[:blank:]]
SEMICOLON ;


LINECOMMENT \/\/[^\n]*
COM_BEGIN  \/\*
COM_END  \*\/


BOOL true|false
IDENTIFIER [[:alpha:]_][[:alpha:][:digit:]_]*
INTEGER [0-9]+
CHAR \'.?\'
STRING \".+\"

ADD_ASSIGN \+=
SUB_ASSIGN \-=
MUL_ASSIGN \*=
DIV_ASSIGN \/=
SELF_ADD \+\+
SELF_SUB \-\-
%%

{EOL} lineno++;
{WHILTESPACE} /* do nothing */
{SEMICOLON} return  SEMICOLON;



{LINECOMMENT}  {BEGIN LINE_COMMENT;}
<LINE_COMMENT>{EOL}        {BEGIN INITIAL;lineno++;}

{COM_BEGIN}     {BEGIN BLOCK_COMMENT;}
<BLOCK_COMMENT>{EOL}  {lineno++;}
<BLOCK_COMMENT>{COM_END} {BEGIN INITIAL;}



"int" return T_INT;
"bool" return T_BOOL;
"char" return T_CHAR;


"if" return IF;
"while" return WHILE;
"else" return ELSE;

"printf" return PRINTF;
"scanf" return SCANF;

"!=" return NOT_EQ;
"!" return NOT;
"==" return EQ;
"=" return ASSIGN;

{SELF_ADD} return SELF_ADD;
{SELF_SUB} return SELF_SUB;
{ADD_ASSIGN} return ADD_ASSIGN;
{SUB_ASSIGN} return SUB_ASSIGN;
{MUL_ASSIGN} return MUL_ASSIGN;
{DIV_ASSIGN} return DIV_ASSIGN;

"+" return ADD;
"-" return SUB;
"*" return MUL;
"/" return DIV;
"%" return MOD;

"<=" return LESS_EQ;
"<"  return LESS_THAN;
">=" return MORE_EQ;
">"  return MORE_THAN;

"(" {return LPAREN;}
")" {return RPAREN;}
"{" {return LBRACE;}
"}" {return RBRACE;}

"&&" return AND;
"||" return OR;


{BOOL} {
    //这里是yytex是字符串类型，不能直接赋值给bool是吗？？？
    //老办法！！！转换一下
    TreeNode *node = new TreeNode(lineno,NODE_CONST);
    node->type = TYPE_BOOL;
    if(strcmp(yytext,"false")==0 ||strcmp(yytext,"0")==0)
        node->b_val = false;
    else
        node->b_val = true;
    yylval = node;
    return BOOL;
}

{IDENTIFIER} {
    TreeNode* node = new TreeNode(lineno, NODE_VAR);
    node->var_name = string(yytext);
    yylval = node;
    return IDENTIFIER;
}

{INTEGER} {
    //注意这里的 TYPE_INT 是一个对象！！！
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    node->int_val = atoi(yytext);
    yylval = node;
    return INTEGER;
}

{CHAR} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_CHAR;
    node->ch_val = yytext[1];

    yylval = node;
    return CHAR;
}

{STRING} {
    TreeNode *node = new TreeNode(lineno,NODE_CONST);
    node->type = TYPE_STRING;
    node->str_val = yytext;

    yylval = node;
    return STRING;

}




. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%