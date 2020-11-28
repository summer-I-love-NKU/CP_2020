%{
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<map>
#include<set>
#include<queue>
using namespace std;

#ifndef YYSTYPE
#define YYSTYPE pairtype
#endif

struct pairtype
{
    map<pair<int, string>, set<int> > NFA;
    string VAR;
};

int yylex ();
extern int yyparse();
FILE* yyin;
void yyerror(const char* s);

/*
// 可以用set表示状态集合 map表示转换表
//一个状态出去多条相同的边,所以值用vector数组存储
//0是起始状态，最后一个数是接受状态
--------------------------------------------------------------
';'  ";"  不一样！！！！！注意细节
还是不得不用pairtype，有没有解决办法呢
成功了，但是最后还会报个错！？
./reg_to_nfa.out <input >output
Parse error : syntax error
Makefile:3: recipe for target 'reg_to_nfa' failed
make: *** [reg_to_nfa] Error 1
------------------------------------------------------
//一个状态出去多条相同的边,所以值用vector数组存储
//0是起始状态，最后一个数是接受状态
//用set
1.求闭包的地方可能不保险
2.标识终态
*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void f(map<pair<int, string>, set<int> >& x,int a,string ch,int b)
{
    x[make_pair(a, ch)].insert(b);
}
//打印
void output_set(set<int> a)
{
    for (set<int>::iterator it = a.begin(); it != a.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

void output_set_char(set<char> a)
{
    for (set<char>::iterator it = a.begin(); it != a.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

void output_set2(set<string> a)
{
    for (set<string>::iterator it = a.begin(); it != a.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

void output_nfa(map<pair<int, string>, set<int> > nfa)
{
    //pair：iter->first 有first second属性 
    //set：iter->second
    cout << "NFA:\n";
    for (map<pair<int, string>, set<int> >::iterator iter = nfa.begin(); iter != nfa.end(); iter++)
    {
        cout << "("<<iter->first.first<<","<<iter->first.second<< ")-->";
        for (set<int>::iterator it = iter->second.begin(); it != iter->second.end();it++)
            cout<<*it<<" ";
        cout << endl;
    }
}

void output_dfa(pair<map<pair<char, string>,char>,set<char> > x)
{
    //pair：iter->first 有first second属性 
    //set：iter->second
    map<pair<char, string>, char> dfa = x.first;
    cout << "DFA:\n";
    for (map<pair<char, string>, char>::iterator iter = dfa.begin(); iter != dfa.end(); iter++)
    {
        cout << "(" << iter->first.first << "," << iter->first.second << ")-->" << iter->second << endl;
    }
    cout << "\n终态：\n";
    output_set_char(x.second);
}

//改变状态序号————这里传入的是地址！！！！这部分传参数不懂，！！！
void add_num_nfa(map<pair<int, string>,set<int> > x,int num,map<pair<int, string>, set<int> >& y)
{
    for (map<pair<int, string>, set<int> >::iterator iter = x.begin(); iter != x.end(); iter++)
    {
        //把x的状态序号累加到num之后
        for (set<int>::iterator it = iter->second.begin(); it != iter->second.end();it++)
        {
            y[make_pair(iter->first.first + num, iter->first.second)].insert(num+*it);
        }
        // x.erase(iter->first);
    }
}
//----------------------------
//reg_to_nfa

map<pair<int, string>,set<int> > new_basic_nfa(string ch)
{
    map<pair<int, string>, set<int> > nfa;
    nfa[make_pair(0, ch)].insert(1);
    return nfa;
}

map<pair<int, string>,set<int> > new_or_nfa(map<pair<int, string>,set<int> > a,map<pair<int, string>,set<int> > b)
{
    int len_a = a.size() + 1;int len_b = b.size() + 1;
    int end = len_a+len_b + 1;
    map<pair<int, string>, set<int> > res;
    add_num_nfa(a, 1, res);
    add_num_nfa(b,len_a+1,res);
    res[make_pair(0, "!")].insert(1);
    res[make_pair(0, "!")].insert(len_a+1);
    res[make_pair(len_a, "!")].insert(end);
    res[make_pair(end-1, "!")].insert(end);

    return res;
}

map<pair<int, string>,set<int> > new_concat_nfa(map<pair<int, string>,set<int> > a,map<pair<int, string>,set<int> > b)
{
    //0 1 2 3 concat 0 1 2--> 0 1 2 3(公共) 4 5 
    int len_a = a.size() + 1;
    map<pair<int, string>, set<int> > res;
    add_num_nfa(a,0,res);//copy过来
    add_num_nfa(b,len_a-1,res);

    return res;
}

map<pair<int, string>,set<int> > new_closure_nfa(map<pair<int, string>,set<int> > a)
{
    int len_a = a.size() + 1;
    map<pair<int, string>, set<int> > res;
    add_num_nfa(a,1,res);

    res[make_pair(0, "!")].insert(1);
    res[make_pair(0, "!")].insert(len_a+1);

    res[make_pair(len_a, "!")].insert(1);
    res[make_pair(len_a, "!")].insert(len_a+1);

    return res;
}


//-------------------------------------
//nfa_to_dfa 注意dfa的类型和nfa不一样！！！

set<int> epsilon_closure(map<pair<int, string>, set<int> > nfa,set<int> S,string ch)
{
    set<int> res;
    //先转换 f(s,ch) ,其中 s in S
    for (set<int>::iterator it = S.begin(); it != S.end(); it++)
    {
        for (set<int>::iterator p = nfa[make_pair(*it, ch)].begin(); p != nfa[make_pair(*it, ch)].end(); p++)
        {
            res.insert(*p);
        }
    }
    //再遍历epsilon的路径 f(r,"!") 其中 r in res
    //这里会出问题 6 7 8 ，循环过程中res会增加，但是不会遇到1了，因为1在前面
    for (set<int>::iterator it = res.begin(); it != res.end(); it++)
    {
        for (set<int>::iterator r = nfa[make_pair(*it, "!")].begin(); r != nfa[make_pair(*it, "!")].end(); r++)
        {
            res.insert(*r);
        }
    }
    //解决办法：再循环一次应该就可以了吧？？？！！！-----可能不保险！！！
    for (set<int>::iterator it = res.begin(); it != res.end(); it++)
    {
        for (set<int>::iterator r = nfa[make_pair(*it, "!")].begin(); r != nfa[make_pair(*it, "!")].end(); r++)
        {
            res.insert(*r);
        }
    }

    return res;

}



pair<map<pair<char, string>,char>,set<char> > NFA_to_DFA(map<pair<int, string>, set<int> > nfa)
{
    int final_index = nfa.size();//这就是终态序号，包含此序号的集合都是终态
    set<char> final_set;//终态集合

    map<pair<char, string>, char> DFA;

    //得到此正则表达式中的字母表,注意要去掉EPSILON !!!
    set<string> character_table;
    for (map<pair<int, string>, set<int> >::iterator iter = nfa.begin(); iter != nfa.end(); iter++)
    {
        character_table.insert(iter->first.second);
    }
    character_table.erase("!");
    // output_set2(character_table);
    // cout << "+++++++++++\n";//---------测试

    //开始状态，，，注意这个算法不会算入0,要自己加上0
    set<int> S0;
    S0.insert(0);
    set<int> cur_state, start_state = epsilon_closure(nfa, S0, "!");
    start_state.insert(0);
    // output_set(start_state);
    // cout << "0000000000000" << endl;//---------测试

    //res-state保存结果所有状态
    set<set<int> > res_state;
    res_state.insert(start_state);
    
    //定义队列，不断插入新状态
    queue<set<int> > new_state;
    new_state.push(start_state);

    //把set集合转换为字母
    map<set<int>, char> res_map;
    char i='A';

    //开始使用deta函数计算下一状态
    while(!new_state.empty())
    {
        cur_state = new_state.front();
        new_state.pop();

        //每次while循环：针对当前的新状态，
        //遍历字母表中每一个字母，计算deta函数的转移状态，如果是新的就插入new_state，写入dfa结果
        //用过的新状态都出队列
        for (set<string>::iterator it = character_table.begin(); it != character_table.end(); it++)
        {
            // cout << *it << "++++++++***********+++++++++++\n";//---------测试
            //怎么判断是不是新状态？根据insert()返回值判断  应该可以
            //-----注意死状态，结果是{} 判断一下set非空？？？？？？？？？？？？？？？？？？
            //-----注意对于DFA 不是新状态也要写入转换关系！！！
            set<int> tmp = epsilon_closure(nfa, cur_state, *it);
            if (epsilon_closure(nfa, cur_state, *it).empty() == 0)
            {
                if(res_state.insert(tmp).second==1)
                {
                    //是新状态，入队列，写入转换关系
                    new_state.push(tmp); 
                }
                //无论是不是新状态 都要写入转换关系 

                //状态转为字母，方便看，这样转换就是书写的连贯顺序!!!
                if(res_map.count(cur_state)==0)
                {
                    res_map[cur_state] = i;
                    i++;
                }
                if(res_map.count(tmp)==0)
                {
                    res_map[tmp] = i;
                    i++;
                }
                //判断是否是终态
                if(tmp.count(final_index)!=0)
                {
                    final_set.insert(res_map[tmp]);
                }
                DFA[make_pair(res_map[cur_state], *it)] = res_map[tmp];
                // cout << "***************************\n";
                // output_set(tmp);
                // cout << "***************************\n";

            }
        }
    }

    pair<map<pair<char, string>, char>, set<char> > ret(DFA, final_set);
    return ret;
}




/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
%}

%token CHAR


%%


lines   :   lines R ';' { 
    cout<<"-----------NFA--------------\n";
    output_nfa($2.NFA);
    cout<<"-----------DFA--------------\n";
    output_dfa(NFA_to_DFA($2.NFA));}
        |   R ';'       { 
    cout<<"-----------NFA--------------\n";
    output_nfa($1.NFA);
    cout<<"-----------DFA--------------\n";
    output_dfa(NFA_to_DFA($1.NFA));}
        |
        ;

R   :    R '|' R        {$$.NFA=new_or_nfa($1.NFA,$3.NFA);}
    |    R '.' R        {$$.NFA=new_concat_nfa($1.NFA,$3.NFA);}
    |    R '*'          {$$.NFA=new_closure_nfa($1.NFA);}
    |    '(' R ')'      {$$.NFA=$2.NFA;}
    |    CHAR           {$$.NFA=new_basic_nfa($1.VAR);}


%%


int yylex()
{
    int t;
    while(1)
    {
        t = getchar();
        if(t == ' ' || t == '\n' || t == '\t')
            {}
        // else if(t == '!')
        //     return EPSILON;
        else if(t==';')
            return ';';
        else if(t=='|')
            return '|';
        else if(t=='*')
            return '*';
        else if(t=='.')
            return '.';
        else if(t=='(')
            return '(';
        else if(t==')')
            return ')';
        else
        {
            yylval.VAR=t;
            return CHAR;
        }
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