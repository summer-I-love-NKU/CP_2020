#include<iostream>
#include<string.h>
#include<map>
#include<set>
#include<vector>
using namespace std;

//一个状态出去多条相同的边,所以值用vector数组存储
//0是起始状态，最后一个数是接受状态
//用的vector，实际上是set好

//-----------------------------
//便捷初始化
void f(map<pair<int, string>, vector<int> >& x,int a,string ch,int b)
{
    x[make_pair(a, ch)].push_back(b);
}
//打印
void output_nfa(map<pair<int, string>, vector<int> > nfa)
{
    //pair：iter->first 有first second属性 
    //vector：iter->second
    for (map<pair<int, string>, vector<int> >::iterator iter = nfa.begin(); iter != nfa.end(); iter++)
    {
        cout << "("<<iter->first.first<<","<<iter->first.second<< ")-->";
        for (int i = 0; i < iter->second.size(); i++) 
            cout<<iter->second[i]<<" ";
        cout << endl;
    }
}
//改变状态序号————这里传入的是地址！！！！这部分传参数不懂，！！！
void add_num_nfa(map<pair<int, string>,vector<int> > x,int num,map<pair<int, string>, vector<int> >& y)
{
    for (map<pair<int, string>, vector<int> >::iterator iter = x.begin(); iter != x.end(); iter++)
    {
        //把x的状态序号累加到num之后
        for (int i = 0; i < iter->second.size(); i++) //size()容器中实际数据个数
            iter->second[i]+=num;
        y[make_pair(iter->first.first + num, iter->first.second)] = iter->second;
        // x.erase(iter->first);
    }
}
//----------------------------

map<pair<int, string>,vector<int> > new_basic_nfa(string ch)
{
    map<pair<int, string>, vector<int> > nfa;
    nfa[make_pair(0, ch)].push_back(1);
    return nfa;
}

map<pair<int, string>,vector<int> > new_or_nfa(map<pair<int, string>,vector<int> > a,map<pair<int, string>,vector<int> > b)
{
    int len_a = a.size() + 1;int len_b = b.size() + 1;
    int end = len_a+len_b + 1;
    map<pair<int, string>, vector<int> > res;
    add_num_nfa(a, 1, res);
    add_num_nfa(b,len_a+1,res);
    res[make_pair(0, "!")].push_back(1);
    res[make_pair(0, "!")].push_back(len_a+1);
    res[make_pair(len_a, "!")].push_back(end);
    res[make_pair(end-1, "!")].push_back(end);

    return res;
}

map<pair<int, string>,vector<int> > new_concat_nfa(map<pair<int, string>,vector<int> > a,map<pair<int, string>,vector<int> > b)
{
    //0 1 2 3 concat 0 1 2--> 0 1 2 3(公共) 4 5 
    int len_a = a.size() + 1;
    map<pair<int, string>, vector<int> > res;
    add_num_nfa(a,0,res);//copy过来
    add_num_nfa(b,len_a-1,res);

    return res;
}

map<pair<int, string>,vector<int> > new_closure_nfa(map<pair<int, string>,vector<int> > a)
{
    int len_a = a.size() + 1;
    map<pair<int, string>, vector<int> > res;
    add_num_nfa(a,1,res);

    res[make_pair(0, "!")].push_back(1);
    res[make_pair(0, "!")].push_back(len_a+1);

    res[make_pair(len_a, "!")].push_back(1);
    res[make_pair(len_a, "!")].push_back(len_a+1);

    return res;
}

int main()
{
    map<pair<int, string>,vector<int> > nfa1,nfa2,nfa3,nfa4,res;
    nfa1[make_pair(0, "a")].push_back(1);
    nfa1[make_pair(1, "b")].push_back(2);
    nfa1[make_pair(2, "c")].push_back(3);
    
    nfa2[make_pair(0, "a")].push_back(1);
    nfa2[make_pair(1, "b")].push_back(2);

    nfa3[make_pair(0, "c")].push_back(1);
    nfa3[make_pair(1, "d")].push_back(2);

    f(nfa4, 0, "a", 1);
    f(nfa4, 1, "b", 2);

    res = new_or_nfa(nfa1, nfa2);
    res = new_concat_nfa(res, nfa3);
    res = new_closure_nfa(nfa4);
    output_nfa(res);

    //---------
    int aaa;
    cin >> aaa;
}
