%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#ifndef YYSTYPE
#define YYSTYPE double
#endif
int yylex();
extern int yyparse();
FILE* yyin;
void yyerror(const char* s);
%}


%token ADD SUB MUL DIV UMINUS NUMBER

%left ADD SUB
%left MUL DIV
%right UMINUS

//%left '+' '−'
// %left '∗' '/'
// %right UMINUS

%% 


lines : lines expr ';' { printf("%f\n",$2); }
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
            yylval = t-'0';
            return NUMBER;
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