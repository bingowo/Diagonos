#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include<iterator>
using namespace std;
//采用增量构造字符组合，假设-abc,假设第一个为a第二个可能为bc;第一个为b,第二个为c第一个c,第二个为空
void permutation( string s2,int start,string y, set<string>&aset)
{
    if(start>s2.length())
        return ;
    if(y!="")aset.insert(y);
    permutation(s2,start+1,y+s2[start],aset);
    permutation(s2,start+1,y,aset);//使用递归，元素是否包括在内只存在两种情况
}
int main()
{
    int t; cin>>t;
    for (int i=0;i<t;i++)
    {
        set<string>out;
        string s1,s2;
        cin>>s1;
        sort(s1.begin(), s1.end());
        unique_copy(s1.begin(), s1.end(),back_inserter(s2));
        permutation(s2,0,"",out);
        cout<<"case #"<<i<<":\n";
        set<string>::iterator iter;
        for (iter=out.begin();iter!=out.end();++iter)
            cout<<*iter<<'\n';
    }
}