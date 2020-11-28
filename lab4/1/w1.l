%option noyywrap
%top{
#include<map>
#include<iomanip>//输出美观
using namespace std;
}
%{
/*
注意数字里的.要用转义字符！
fflush(stdout);
cout.setf(std::ios::left);//全局的
cout.width(10);
cout<<std::left<<setw(10)<<a<<std::right<<setw(10)<<b<<endl;

读到空格也会输出！！！，需要处理！！！不然混乱死
WP    [\n\t ] 这里直接输入空格就行  不要“ ”  这样会把"也过滤掉
DP    \x22      双引号 用ascii码十六进制转义字符表示


%s BLOCK  ??不同块之间的变量呢？？-----多符号表（区分不同作用域，大括号） 存数值，翻译要用！！！！

strcmp不好用？？
数字转为数值，支持科学计数法，支持记录包括注释内的行数
*/
int chars,words,id_num=0;int lines=1;//注意从1开始！
map<string,int> ID_seq_list;


void show(string a,string b,int c=0)
{
    cout.setf(std::ios::left);//输出左对齐
    if(c==0)
    {
        cout<<setw(14)<<a<<setw(14)<<b<<endl;
    }
    else
    {
        cout<<setw(14)<<a<<setw(14)<<b<<setw(14)<<c<<endl;
    }
}
void show_num(string a,string b,double c)
{
    cout.setf(std::ios::left);//输出左对齐
    cout<<setw(14)<<a<<setw(14)<<b<<setw(14)<<c<<endl;
}
void show_key(string a,string b,string c)
{
    cout.setf(std::ios::left);//输出左对齐
    cout<<setw(14)<<a<<setw(14)<<b<<setw(14)<<c<<endl;
}

//因为使用math.h库出问题！
double my_10_exp(double a,int b)
{
    if(b<0)
        for (int i = 0; i < -b; i++)
            a *= 0.1;
    else
        for (int i = 0; i < b; i++)
            a *= 10;
    return a;
}
double str_to_num(string a)
{
    //负数
    bool neg,exp_neg,exp_flag=0;
    if(a[0]=='-')
    {
        a=a.substr(1);
        neg=1;
    }

    //整数
    double res,fraction,fra_num,exponent=0;
    int i = 0;
    for (i = 0; i < a.length() && a[i] != '.'&&a[i] != 'E' && a[i] != 'e'&&a[i]!='\0'; i++)
    {
        res=res*10+a[i]-'0';
    }

    //小数
    if(i<a.length()-1)//123.45
    {
        if(a[i]=='.')
        {
            int k = 0;
            for(k = i + 1; a[k] != 'E' && a[k] != 'e'&&a[k]!='\0'; k++)
            {
                fraction=fraction*10+a[k]-'0';
                fra_num++;
            }
            fraction = my_10_exp(fraction, -fra_num);

            //指数
            if(k<a.length()-1)//123.4e-5,不能是!=,比如12.3此时k超过里len-1也是不等于，但已经结束了
            {
                exp_flag=1;
                if(a[k+1]=='-')
                {
                    exp_neg = 1;
                    k++;
                }
                for(int m = k + 1; a[m] != '\0'; m++)
                {
                    exponent=exponent*10+a[m]-'0';
                }
            }
        }
        else//123e4
        {
            exp_flag=1;
            if(a[i+1]=='-')
            {
                exp_neg = 1;
                i++;
            }
            for(int k = i + 1; a[k]!='\0'; k++)
            {
                exponent=exponent*10+a[k]-'0';
            }
        }
        
        
    }

    res+=fraction;
    if(exp_flag==1)
        exp_neg == 0 ? (res = my_10_exp(res,exponent)) : (res = my_10_exp(res,-exponent));
    
    //不加这一句似乎不能识别0？？？？？！！！
    if(res<1e-40)
        res=0;

    return neg==0?res:-res;
}


%}

%x COMMENT
%x LINE_COMMENT



LINE  \n
WP    [\n\t ]

KEY         main|return|int|double|char|void|if|else|"else if"|for|while|do
ID          [a-zA-Z_][0-9a-zA-Z_]*
NUM         (-)?(([1-9][0-9]*)|0)(\.[0-9]*)?((E|e)(-)?[0-9]+)?


DELIM  ;
COMMA  \,
DOT    \.
ASSIGN  =
COM_LINE  \/\/
COM_BEGIN  \/\*
COM_END  \*\/
COM_ELEMENT .|\n
COM_LINE_ELEMENT .


ADD  \+
SUB  \-
MUL  \*
DIV  \/
MOD  %
ADD_ASSIGN \+=
SUB_ASSIGN \-=
MUL_ASSIGN \*=
DIV_ASSIGN \/=

BIT_AND &
BIT_OR  \|
AND &&
OR \|\|
NOT !



LP  \(
RP  \)
LPB  \{
RPB  \}
LPM  \[
RPM  \]
SQ  \'
DQ  \x22
EQ  ==
LT  <
LE  <=
MT  >
ME  >=
NE  !=





%%


{LINE}      {lines++;}
{WP}        {}

{KEY}       {show_key("KEY",yytext,yytext);}
{ID}        {
    if(ID_seq_list.count(yytext)==0)
    {
        id_num++;
        ID_seq_list[yytext]=id_num;
        show("ID",yytext,id_num);
    }
    else
    {
        show("ID",yytext,ID_seq_list[yytext]);
    }
}
{NUM}       {
    show_num("NUM",yytext,str_to_num(yytext));//这是double类型的了！！！
    }



{DELIM}         {show("DELIM",yytext);}
{COMMA}         {show("COMMA",yytext);}
{DOT}           {show("DOT",yytext);}
{ASSIGN}        {show("ASSIGN",yytext);}

{COM_LINE}      {
    show("COM_LINE",yytext);
    BEGIN LINE_COMMENT;
    }
<LINE_COMMENT>{COM_LINE_ELEMENT} {}
<LINE_COMMENT>{LINE}        {BEGIN INITIAL;lines++;}

{COM_BEGIN}     {
    show("COM_BEGIN",yytext);
    BEGIN COMMENT;
    }
<COMMENT>{COM_LINE_ELEMENT}  {}
<COMMENT>{LINE}  {lines++;}
<COMMENT>{COM_END}          {show("COM_END",yytext);BEGIN INITIAL;}




{ADD}       {show("ADD",yytext);}
{SUB}       {show("SUB",yytext);}
{MUL}       {show("MUL",yytext);}
{DIV}       {show("DIV",yytext);}

{ADD_ASSIGN}       {show("ADD_ASSIGN",yytext);}
{SUB_ASSIGN}       {show("SUB_ASSIGN",yytext);}
{MUL_ASSIGN}       {show("MUL_ASSIGN",yytext);}
{DIV_ASSIGN}       {show("DIV_ASSIGN",yytext);}

{BIT_AND}       {show("BIT_AND",yytext);}
{BIT_OR}        {show("BIT_OR",yytext);}
{AND}           {show("AND",yytext);}
{OR}            {show("OR",yytext);}
{NOT}           {show("NOT",yytext);}


{LP}        {show("LP",yytext);}
{RP}        {show("RP",yytext);}
{LPB}       {show("LPB",yytext);}
{RPB}       {show("RPB",yytext);}
{LPM}       {show("LPM",yytext);}
{RPM}       {show("RPM",yytext);}
{SQ}        {show("SQ",yytext);}  
{DQ}        {show("DQ",yytext);}
{EQ}        {show("EQ",yytext);}
{LT}        {show("LT",yytext);}
{LE}        {show("LE",yytext);}
{MT}        {show("MP",yytext);}
{ME}        {show("ME",yytext);}
{NE}        {show("NE",yytext);}





%%
//输入ctrl+D作为结束标志
int main()
{
    //调用对象
    yyFlexLexer lexer;
    lexer.yylex();
    
    cout<<"\n行数: "<<setw(8)<<lines<<endl;
    return 0;

}





