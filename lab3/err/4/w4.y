%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;
#ifndef YYSTYPE
#define YYSTYPE union
#endif
int yylex();
extern int yyparse();//a storage class can only be specified for objects and functions
FILE* yyin;
void yyerror(const char* s);
static int num=0;
%}

%union
{
    string name;
    double value;
}

%token NUMBER ID ADD SUB MUL DIV UMINUS
%type <float> expr NUMBER vardef

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
    : ID ';'             { a[num]=$1;b[num]=0; num++;}
    | ID '=' expr ';' { a[num]=$1;b[num]=$3;num++;}
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
            yylval = 0;
            while (isdigit(t)) 
            {
                yylval = yylval*10+t-'0';
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
            yylval=idstr;
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