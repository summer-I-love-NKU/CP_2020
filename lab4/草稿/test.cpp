#include<iostream>
#include<string.h>
#include<map>
#include<set>
#include<queue>
// #include<algorithm>
using namespace std;

/*

map<string,int> node[10];不错！！！

BFS 遍历

　set的单元素版返回一个二元组（Pair）。成员 pair::first 
被设置为指向新插入元素的迭代器或指向等值的已经存在的元素的迭代器。成员 pair::second 是一个 bool 值，
如果新的元素被插入，返回 true，如果等值元素已经存在（即无新元素插入），则返回 false。　　
*/
map<string, int> node[10];
//-----------------------------



void output_set(set<int> a)
{
    for (set<int>::iterator it = a.begin(); it != a.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}
void output_nfa(map<pair<int, string>, set<int> > nfa)
{
    //pair：iter->first 有first second属性 
    //vector：iter->second
    for (map<pair<int, string>, set<int> >::iterator iter = nfa.begin(); iter != nfa.end(); iter++)
    {
        cout << "("<<iter->first.first<<","<<iter->first.second<< ")-->";
        for (set<int>::iterator it = iter->second.begin(); it != iter->second.end();it++)
            cout<<*it<<" ";
        cout << endl;
    }
}
int main()
{
    // map<pair<int, string>,set<int> > nfa1,nfa2,nfa3,nfa4,res;
    // nfa1[make_pair(0, "a")].insert(1);nfa1[make_pair(0, "a")].insert(2);nfa1[make_pair(0, "a")].insert(1);
    // nfa1[make_pair(1, "b")].insert(2);
    // nfa1[make_pair(2, "c")].insert(3);
    // output_nfa(nfa1);
    //---------
    set<int> a,b;
    a.insert(1);a.insert(2);a.insert(3);
    a.erase(3);
    output_set(a);

    int aaa;
    cin >> aaa;
}
