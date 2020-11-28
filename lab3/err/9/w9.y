%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>
using namespace std;
#ifndef YYSTYPE
#define YYSTYPE union
/*
在w9.c文件：extern YYSTYPE yylval;:
a storage class can only be specified for objects and functions

就是"storage class"的修饰符用在了对象或者变量(objects)和函数(functions)外的其他地方。
在C/C++规范中，定义了四种storage class的修饰符。
auto
register
static
extern

extern关键字可以用来声明变量和函数作为外部变量或者函数供其它文件使用
声明对象是一个外部对象（变量或函数），标识其定义在别的文件中。会被多个文件使用

所以结构体不行
*/
#endif

struct pairtype
{
    double value;
    string name;
};

int yylex ();
extern int yyparse();
FILE* yyin;
map<string, double> varlist;
//注意YYSTYPE  类型 pair<double, string>  
//因此$$有两个属性，主要是为了处理ID,既有名字为string类型又有值为double类型，这里我觉得好像只能定义为pair类型
//或者两个元素的数组，能存两个属性的

//如果用结构体的话，也是符号表那里用，
//而union是不同变量类型，把标志（token）绑定到YYSTYPE的某个域也是对于不同变量
//但是ID 这一个变量就有两个不同类型属性！！？？？

//varlist 类型 map<string, double>  用于实现符号表，存储变量值，类似字典结构
void yyerror(const char* s);
%}

%union
{
    pairtype id;
    double others;
}



%token ID NUMBER ADD SUB MUL DIV ASSIGN
%type <id> ID
%type <others> NUMBER 
%type <others> expr
%token LP RP SEM
%right ASSIGN
%left ADD SUB
%left MUL DIV
%right UMINUS

%%


lines   :   lines expr SEM { printf("%f\n", $2); }
        |   lines SEM
        |
        ;

expr    :   expr ADD expr   {$$ = $1 + $3;}
        |   expr SUB expr   {$$ = $1 - $3;}
        |   expr MUL expr   {$$ = $1 * $3;}
        |   expr DIV expr   {$$ = $1 / $3;}
        |   SUB expr %prec UMINUS {$$ = -$2;}
        |   LP expr RP      {$$ = $2;}
        |   NUMBER  {$$ = $1;}
        |   ID ASSIGN expr  {varlist[$1.name] = $3; $$ = varlist[$1.name];}
        |   ID  {  
                 if(!varlist.count($1.name)) 
                    {varlist[$1.name] = 0;}
                 $$ = varlist[$1.name];
                }
        ;
%%


int yylex()
{
    int t;
    while(1)
    {
        t = getchar();
        if(t == ' ' || t == '\n' || t == '\t')
        {}
        else if(t == '=')
            return ASSIGN;
        else if(t == '+')
            return ADD;
        else if(t == '-')
            return SUB;
        else if(t == '*')
            return MUL;
        else if(t == '/')
            return DIV;
        else if(t == '(')
            return LP;
        else if(t == ')')
            return RP;
        else if(t == ';')
            return SEM;
        else if(isdigit(t))
        {
            yylval = 0;
            while(isdigit(t))
            {
                yylval = yylval * 10 + t - '0';
                t = getchar();
            }
            ungetc(t, stdin);
            // yylval.name = "";
            return NUMBER;
        }
        else if(isalpha(t) || t == '_')
        {
            yylval.name = "";
            while(isalpha(t) || isdigit(t) || t == '_')
            {
                yylval.name += t;
                t = getchar();
            }
            ungetc(t, stdin);
            yylval = 0;
            return ID;
        }
        else
            return t;
    }
    
}

int main(void)
{
    yyin = stdin;
    do
    {
        yyparse();
    }while(!feof(yyin));
    return 0;
}

void yyerror(const char* s)
{
    fprintf (stderr, "Parse error : %s\n" , s);
    exit (1);
}