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

    BLOCK_COMMENT_ELEMENT_loose  :任意字符，这样不严谨  但是把注释结束符号放前面识别就好了
    ------------------------------
    {LINECOMMENT}  {BEGIN LINE_COMMENT;}
    <LINE_COMMENT>{EOL}        {BEGIN INITIAL;lineno++;}

    {COM_BEGIN}     {BEGIN BLOCK_COMMENT;}
    <BLOCK_COMMENT>{COM_END} {BEGIN INITIAL;}
    <BLOCK_COMMENT>{EOL}  {lineno++;}
    <BLOCK_COMMENT>{BLOCK_COMMENT_ELEMENT_loose} {}
    -----------------------------------------

node->ch_val = yytext[1];???

注意bool的识别要在ID 之前！！！{BOOL}{。。。}  {ID}{。。。}

一定注意，最长前缀原则————先识别： ==  而不是 = ， ！= 而不是！，++而不是+，。。。


符号表的实现！！！！

一个作用域的——开始符号，结束符号：{ }

*/

%}


%x BLOCK_COMMENT
%x LINE_COMMENT

EOL	(\r\n|\r|\n)
WHILTESPACE [[:blank:]]

LINECOMMENT \/\/[^\n]*
COM_BEGIN  \/\*
COM_END  \*\/
BLOCK_COMMENT_ELEMENT_loose .




BOOL true|false
IDENTIFIER [[:alpha:]_][[:alpha:][:digit:]_]*
INTEGER_H (0x|0X)([1-9a-fA-F][0-9a-fA-F]*|0)
INTEGER_DPN ("-"?)([1-9][0-9]*|0)
INTEGER_O 0([1-7][0-7]*|0)
INTEGER_B (0B|0b)(1|0)+

CHAR \'.?\'
STRING \".+\"


%%

{EOL} lineno++;
{WHILTESPACE} /* do nothing */
";" return  SEMICOLON;
"," return COMMA;
"." return DOT;


{LINECOMMENT}  {BEGIN LINE_COMMENT;}
<LINE_COMMENT>{EOL}        {BEGIN INITIAL;lineno++;}

{COM_BEGIN}     {BEGIN BLOCK_COMMENT;}
<BLOCK_COMMENT>{COM_END} {BEGIN INITIAL;}
<BLOCK_COMMENT>{EOL}  {lineno++;}
<BLOCK_COMMENT>{BLOCK_COMMENT_ELEMENT_loose} {/* do nothing */}


"int" return T_INT;
"bool" return T_BOOL;
"char" return T_CHAR;
"void" return T_VOID;
"const" return CONST;

"main" return MAIN;
"return" return RETURN;

"for" return FOR;
"if" return IF;
"while" return WHILE;
"else" return ELSE;
"else if" return ELSE_IF;

"printf" return PRINTF;
"scanf" return SCANF;

"!=" return NOT_EQ;
"!" return NOT;
"==" return EQ;
"=" return ASSIGN;

"++" return SELF_ADD;
"--" return SELF_SUB;
"+=" return ADD_ASSIGN;
"-=" return SUB_ASSIGN;
"*=" return MUL_ASSIGN;
"/=" return DIV_ASSIGN;

{INTEGER_DPN} {
    //注意这里的 TYPE_INT 是一个对象！！！
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    node->type_flag="int";
    if(yytext[0]=='-')
    {
        node->int_val = -stoi(string(yytext).substr(1,string(yytext).length()),0,10);
        yylval = node;
        return INTEGER_DN;
    }
    else
    {
        node->int_val = atoi(yytext);
        yylval = node;
        return INTEGER_DP;
    } 
}


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
"[" return LMPAREN;
"]" return RMPAREN;
"&&" return AND;
"||" return OR;

"&" return b_AND;
"|" return b_OR;
"~" return b_NOT;
"^" return b_NOR;

{BOOL} {
    //这里是yytex是字符串类型，不能直接赋值给bool是吗？？？
    //老办法！！！转换一下
    TreeNode *node = new TreeNode(lineno,NODE_CONST);
    node->type = TYPE_BOOL;
    if(strcmp(yytext,"false")==0 ||strcmp(yytext,"0")==0)
        node->b_val = false;
    else
        node->b_val = true;
    node->type_flag="bool";
    yylval = node;
    return BOOL;
}

{IDENTIFIER} {
    TreeNode* node = new TreeNode(lineno, NODE_VAR);
    node->var_name = string(yytext);
    yylval = node;
    return IDENTIFIER;
}
{INTEGER_H} {
    //stoi（字符串，起始位置，n进制），将 n 进制的字符串转化为十进制
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    node->int_val = stoi(string(yytext).substr(2,string(yytext).length()),0,16);
    node->type_flag="int";
    yylval = node;
    return INTEGER_H;

}

{INTEGER_O} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    node->int_val = stoi(string(yytext).substr(1,string(yytext).length()),0,8);
    node->type_flag="int";
    yylval = node;
    return INTEGER_H;

}
{INTEGER_B} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    node->int_val = stoi(string(yytext).substr(2,string(yytext).length()),0,2);
    node->type_flag="int";
    yylval = node;
    return INTEGER_H;

}

{CHAR} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_CHAR;
    node->ch_val = yytext[1];//?????
    node->type_flag="char";
    yylval = node;
    return CHAR;
}

{STRING} {
    TreeNode *node = new TreeNode(lineno,NODE_CONST);
    node->type = TYPE_STRING;
    node->str_val = yytext;
    node->type_flag="string";
    yylval = node;
    return STRING;

}




. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%