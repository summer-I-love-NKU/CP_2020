%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef YYSTYPE
#define YYSTYPE union
#endif
#include<iostream>
using namespace std;

#define LEN 20
struct varlist
{
    string name;
    double value;
}varlist[LEN];

static int count=0;

int yylex();
extern int yyparse();
FILE* yyin;
void yyerror(const char* s);
%}


%union
{
    string name[2];//ID
    double value;//other
}


%token ID NUMBER ADD SUB MUL DIV ASSIGN
%token LP RP SEM
%type <name> ID

%right ASSIGN
%left ADD SUB
%left MUL DIV
%right UMINUS

%%


lines   :   lines expr SEM { printf("%f\n", $2.first); }
        |   lines SEM
        |
        ;

expr    :   expr ADD expr   {$$.first = $1.first + $3.first;}
        |   expr SUB expr   {$$.first = $1.first - $3.first;}
        |   expr MUL expr   {$$.first = $1.first * $3.first;}
        |   expr DIV expr   {$$.first = $1.first / $3.first;}
        |   SUB expr %prec UMINUS {$$.first = -$2.first;}
        |   LP expr RP      {$$.first = $2.first;}
        |   NUMBER  {$$.first = $1.first;}
        |   ID ASSIGN expr  {varlist[$1.second] = $3.first; $$.first = varlist[$1.second];}
        |   ID  {  
                 if(!varlist.count($1.second)) 
                    {varlist[$1.second] = 0;}
                 $$.first = varlist[$1.second];
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
            yylval.first = 0;
            while(isdigit(t))
            {
                yylval.first = yylval.first * 10 + t - '0';
                t = getchar();
            }
            ungetc(t, stdin);
            yylval.second = "";
            return NUMBER;
        }
        else if(isalpha(t) || t == '_')
        {
            yylval.second = "";
            while(isalpha(t) || isdigit(t) || t == '_')
            {
                yylval.second += t;
                t = getchar();
            }
            ungetc(t, stdin);
            yylval.first = 0;
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
