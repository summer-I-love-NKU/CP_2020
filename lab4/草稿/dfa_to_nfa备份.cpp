#include<iostream>
#include<string.h>
#include<map>
#include<set>
#include<queue>
using namespace std;

//一个状态出去多条相同的边,所以值用vector数组存储
//0是起始状态，最后一个数是接受状态
//用set
/*
1.求闭包的地方可能不保险
2.标识终态------NFA的状态数就是map节点数+1！！？？  
               终态序号就等于map节点数  那么。。。
3.打算写个类！！！！这样方便互相使用属性

*/
//-----------------------------
//便捷初始化
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

    // return DFA;
    pair<map<pair<char, string>, char>, set<char> > ret(DFA, final_set);
    return ret;
}

//判断是否在集合里
bool in_set(char x,set<char> S)
{
    if(S.count(x)==0)
        return 0;
    return 1;
}
//找到状态所在的集合  x是状态，S是状态集合的集合
set<char> find_set(char x,set<set<char> > S)
{
    for (set<set<char> >::iterator iter = S.begin(); iter != S.end(); iter++)   
    {
        if(in_set(x,*iter))
        {
            return *iter;
        }
    }
}


set<set<char> > depart_state(set<char> S,set<string> character_table,map<pair<char, string>,char> the_dfa)
{
    set<set<char> > res;
    map<char, set<char> > the_map;
    int num0 = S.size();

    //开始进行转换函数，看结果是否在自己的集合里
    for (set<string>::iterator it = character_table.begin(); it != character_table.end(); it++)
    {
        /**
         *    这个检查emmm可以吗
         * 
         * */
        // for (map<char, set<char> >::iterator it2 = the_map.begin(); it2 != the_map.end(); it2++)
        // {
        //     if(it2->second.size()==num0)
        //     {
        //         the_map.erase(it2);
        //     }
        // }

        for (set<char>::iterator iter = S.begin(); iter != S.end(); iter++)   
        {
            if(the_dfa.count(make_pair(*iter,*it))!=0)
            {
                if(!in_set(the_dfa[make_pair(*iter, *it)],S))
                {
                    the_map[the_dfa[make_pair(*iter, *it)]].insert(*iter);
                    S.erase(*iter);
                }
            }
        }
    }
    if(the_map.size()==1)
    {
        for (map<char, set<char> >::iterator it = the_map.begin(); it != the_map.end(); it++)
        {
            res.insert(S);
            res.insert(it->second);
            set<char> NULL_set=set<char>();
            res.erase(NULL_set);//防止空集也加进去
        }
    }
    if(the_map.size()>=2)
    {
        //就要看看这两个状态是否在同一个状态集合里，要是一样就合并里，不一样就写两个结果
        //好难，不写了
        cout << "ERROR!能力不足！！！" << endl;
        // for (map<char, set<char> >::iterator it = the_map.begin(); it != the_map.end(); it++)
        // {
        //     if(it->second.size()==num0)
        //     {
        //         continue;
        //     }
        //     res.insert(it->second);
        //     // for (set<char>::iterator iter = tmp.begin(); iter != tmp.end(); iter++)
        //     // {

        //     // }
        // }
    }

    return res;
}


pair<map<pair<char, string>,char>,set<char> > min_DFA(pair<map<pair<char, string>,char>,set<char> > x)
{
    //得到非终态集合，终态集合就是x.second
    map<pair<char, string>, char> dfa = x.first;
    set<char> not_final_state,final_state= x.second;
    for (map<pair<char, string>, char>::iterator it = dfa.begin(); it != dfa.end(); it++)
    {
        not_final_state.insert(it->first.first);
        not_final_state.insert(it->second);
    }
    for (set<char>::iterator it = x.second.begin(); it != x.second.end(); it++)
    {
        not_final_state.erase(*it);
    }
    //----not_final_state   final_state 得到了


    //得到此正则表达式中的字母表,此时没有epsilon !!!
    set<string> character_table;
    for (map<pair<char, string>, char>::iterator iter = dfa.begin(); iter != dfa.end(); iter++)
    {
        character_table.insert(iter->first.second);
    }

    set<set<char> > r1,r2;
    r1=depart_state(not_final_state,character_table,dfa);
    
    for (set<set<char> >::iterator iter = r1.begin(); iter != r1.end(); iter++)
    {
        set<char> tmp = *iter;
        for (set<char>::iterator it = tmp.begin(); it != tmp.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    //---------------------开始分裂！！！-----------------

}





int main()
{
    map<pair<int, string>, set<int> > a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, res;
    //-----------------1--------------
    // f(a1, 0, "a",1);
    // f(a2, 0, "b", 1);
    // a3 = new_or_nfa(a1, a2);
    // a4 = new_closure_nfa(a3);//a4已经做完闭包 (a|b)*
    // f(a5, 0, "b",1);f(a5, 1, "b",2);f(a5, 2, "a",3);
    // a6 = new_concat_nfa(a4, a5);//a6是(a|b)*bba
    // a7 = new_concat_nfa(a6, a4);//a7是(a|b)*bba(a|b)*

    //-----------------2-------------
    // f(a1, 0, "a",1);
    // f(a2, 0, "b", 1);
    // a3 = new_or_nfa(a1, a2);
    // a4 = new_closure_nfa(a3);//a4已经做完闭包 (a|b)*
    // f(a5, 0, "a",1);f(a5, 1, "b",2);f(a5, 2, "b",3);
    // a7 = new_concat_nfa(a4, a5);//a7是(a|b)*abb

    f(a1, 0, "a",1);
    f(a2, 0, "b", 1);
    a3 = new_or_nfa(a1, a2);
    a4 = new_closure_nfa(a3);//a4已经做完闭包 (a|b)*
    f(a5, 0, "a",1);
    a7 = new_concat_nfa(a4, a5);//a7是(a|b)*a


    res = a7;
    output_nfa(res);
    cout << endl;
    //--------------------------------
    output_dfa(NFA_to_DFA(res));

    min_DFA(NFA_to_DFA(res));
    //---------


    //-----------一个测试-------------------------
    // set<int> a;set<int> aa;
    // a.insert(1);a.insert(2);a.insert(3);aa.insert(4);
    // aa.erase(4);
    // set<set<int> > b;
    // b.insert(a);b.insert(aa);
    // // set<int> tmp=set<int>();
    // // b.erase(tmp);

    // // a.erase(2);
    // // b.erase(a);//a已经不是1 2 3 4了，a是1 3 4
    // for (set<set<int> >::iterator iter = b.begin(); iter != b.end(); iter++)
    // {
    //     set<int> c= *iter;
    //     for (set<int>::iterator it = c.begin(); it != c.end(); it++)
    //     {
    //         cout << *it << " ";
    //     }
    //     cout << "---"<<endl;
    // }//结果是 1 2 3 4,！！！！

    int aaa;
    cin >> aaa;
}




    

    

