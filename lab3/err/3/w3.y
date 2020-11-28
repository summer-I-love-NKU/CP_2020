%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<map>
#include<iostream>
using namespace std;
#ifndef YYSTYPE
#define YYSTYPE union
#endif
int yylex();
extern int yyparse();//a storage class can only be specified for objects and functions
FILE* yyin;
void yyerror(const char* s);

map<string,float> varlist;
char* idstr[50];
%}

%union
{
    double num;
    char* id;
}

%token ADD SUB MUL DIV UMINUS 
%token <num> NUMBER 
%token <id> ID 

%type <num> expr vardef

%left ADD SUB
%left MUL DIV
%right UMINUS
//%left '+' '−'
// %left '∗' '/'
// %right UMINUS


%% 


lines : lines expr ';' { cout<<$2; }
| lines vardef ';'
| lines ';'
|
;


expr : expr ADD expr { $$ = $1 + $3; }
| expr SUB expr { $$ = $1 - $3; }
| expr MUL expr { $$ = $1 * $3; }
| expr DIV expr { $$ = $1 / $3; }
| '(' expr ')' { $$ = $2; }
| SUB expr %prec UMINUS { $$ = -$2; }
| NUMBER { $$ = $1; }
;



vardef  
    : ID ';'             { varlist[$1]=0; $$=0;}
    | ID '=' expr ';' { varlist[$1]=$3;$$=0;}
    ; 


%%

// programs section

int yylex()
{
    // place your token retrieving code here
    int t;
    while(1)
    {
        t=getchar();
        if(t=='+')
            return ADD;
        else if(t=='-')
            return SUB;
        else if(t=='*')
            return MUL;
        else if(t=='/')
            return DIV;
        else if (t ==' '|| t== '\t' || t == '\n')
            continue;
        else if (isdigit(t)) 
        {
            yylval.num = 0;
            while (isdigit(t)) 
            {
                yylval.num= yylval.num*10+t-'0';
                t = getchar();
            }
            ungetc(t,stdin);
            return NUMBER;
        }
        else if(isalpha(t)>0||t=='_')
        {
            int i=0;
            while(isalpha(t)>0||t=='_'||isdigit(t))
            {
                idstr[i]=t;
                t=getchar();
                i++;
            }
            idstr[i]='\0';
            yylval.id=idstr;
            ungetc(t,stdin);
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
    } 
    while(!feof(yyin));
    return 0;
}
void yyerror(const char* s) 
{
    fprintf(stderr,"Parse error: %s\n",s);
    exit(1);
}