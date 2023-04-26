#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N{100};
struct T
{
    string s{string(N,'0')};
    string sx{string(2*N,'0')};
    int sign{};
};

void preprocess(T& p)
{
    string s=p.s;
    if(s[0]=='-'||s[0]=='+')
    {
        if(s[0]=='-')p.sign=1;
        s.erase(0,1);
    }
    if(s.find('.')==string::npos)s+=".";
    p.sx.replace(N-s.find('.'),s.size(),s);
}

bool cmp_sp(T e1,T e2)//返回1不交换
{
    if(e1.sign!=e2.sign)return e2.sign>e1.sign;
    else if(e1.sign==0)return e1.sx<e2.sx;//两个都为正数
          else return e1.sx>e2.sx;
}

int main()
{
    int n,i{};
    cin>>n;
    T a[N];
    while(i<n&&cin>>a[i].s)
    {
        preprocess(a[i]);
        i++;
    }
    sort(a,a+n,cmp_sp);
    for(int k{};k<n;k++)cout<<a[k].s<<endl;
    return 0;
}