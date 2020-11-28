%{
    //中缀表达式转后缀表达式，负号问题？ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#ifndef YYSTYPE
#define YYSTYPE char*
#endif

char idstr[50];
char numstr[50];

int yylex();
extern int yyparse();
FILE* yyin;
void yyerror(const char* s);
%}


%token NUMBER ID ADD SUB MUL DIV UMINUS
%left ADD SUB
%left MUL DIV
%right UMINUS



%% 


lines : lines expr ';' { printf("%s\n",$2); }
| lines ';'
|
;


expr  
    : expr ADD expr { $$ = (char*)malloc(50*sizeof(char));strcpy($$,$1);strcat($$,$3);strcat($$,"+ "); }
    | expr SUB expr { $$ = (char*)malloc(50*sizeof(char));strcpy($$,$1);strcat($$,$3);strcat($$,"- "); }
    | expr MUL expr { $$ = (char*)malloc(50*sizeof(char));strcpy($$,$1);strcat($$,$3);strcat($$,"* "); }
    | expr DIV expr { $$ = (char*)malloc(50*sizeof(char));strcpy($$,$1);strcat($$,$3);strcat($$,"/ "); }
    | '(' expr ')'  { $$ = (char*)malloc(50*sizeof(char));strcpy($$,$2);strcat($$," "); }
    | SUB expr %prec UMINUS { $$ = (char*)malloc(50*sizeof(char));strcpy($$,"-");strcat($$,$2);strcat($$," ");}
    | NUMBER        {  $$ = (char*)malloc(50*sizeof(char));strcpy($$,$1); strcat($$," ");}
    | ID            {  $$ = (char*)malloc(50*sizeof(char));strcpy($$,$1); strcat($$," ");}
    ;



%%

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
            int i=0;
            while(isdigit(t))
            {
                numstr[i]=t;
                t=getchar();
                i++;
            }
            numstr[i]='\0';
            yylval=numstr;
            ungetc(t,stdin);
            return NUMBER;
        }
        else if(isalpha(t)||t=='_')
        {
            int i=0;
            while(isalpha(t)||t=='_'||isdigit(t))
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