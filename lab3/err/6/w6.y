%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>
using namespace std;
#ifndef YYSTYPE
#define YYSTYPE pair<double, string>
#endif

// int isdigit(int t);
int yylex ();
extern int yyparse();
FILE* yyin;
map<string, double> varlist;
void yyerror(const char* s);
%}


%token ID NUMBER ADD MINUS MUL DIV LP RP SEM ASSIGN
%right ASSIGN
%left ADD MINUS
%left MUL DIV
%right UMINUS

%%


lines   :   lines expr SEM { printf("%f\n", $2.first); }
        |   lines SEM
        |
        ;

expr    :   expr ADD expr   {$$.first = $1.first + $3.first;}
        |   expr MINUS expr   {$$.first = $1.first - $3.first;}
        |   expr MUL expr   {$$.first = $1.first * $3.first;}
        |   expr DIV expr   {$$.first = $1.first / $3.first;}
        |   MINUS expr %prec UMINUS {$$.first = -$2.first;}
        |   LP expr RP      {$$.first = $2.first;}
        |   NUMBER  {$$.first = $1.first;}
        |   ID ASSIGN expr  {varlist[$1.second] = $3.first; $$.first = varlist[$1.second];}
        |   ID  {   if( varlist.find($1.second) == varlist.end() ) varlist[$1.second] = 0;
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
            return MINUS;
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