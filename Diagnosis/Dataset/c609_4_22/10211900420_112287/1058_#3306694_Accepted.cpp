#include<iostream>
#include<string>
using namespace std;

struct BIGINT
{
    int cnt;
    int v[501];
    int div();
    void add();
};

int BIGINT::div()
{
    int i,carry;
    if(v[cnt-1]<2)
        {
            cnt--;
            carry=1;
        }
    else carry=0;
    for(i=cnt-1;i>=0;i--)
    {
        int t=10*carry+v[i];
        v[i]=t/2;
        carry=t%2;
    }
    return carry;
}
void BIGINT::add()
{
    int i;
    for(i=0;i<=cnt-1;i++)
    {
        if(v[i]!=9)
        {
            v[i]++;
            break;
        }
        else
        {
            v[i]=0;
        }
    }
    if(i==cnt && v[i-1]==0)
    {
        cnt++;
        v[cnt-1]=1;
    }
}

int main()
{
    string s;
    cin>>s;
    int g=0,carry,sign=1,c[501],len=s.size();
    BIGINT n={0,{0}};
    for(int i=len-1;i>=1;i--)
    {
        n.v[n.cnt++]=s[i]-'0';
    }
    if(s[0]=='-')
    {
        sign=-1;
    }
    else
    {
        n.v[n.cnt++]=s[0]-'0';
    }
    if(n.cnt==1 && n.v[0]==0)
    {
        n.cnt=0;
        c[g++]=0;
    }
    while(n.cnt!=0)
    {
        if(sign==-1 && n.v[0]%2!=0)
            {
                n.add();
                carry=n.div();
                carry=1;
            }
        else carry=n.div();
        if(carry==1)
        {
            c[g]=1;
        }
        else c[g]=0;
        sign=(-1)*sign;
        g++;
    }
    for(int i=g-1;i>=0;i--)
    {
        cout<<c[i];
    }
    return 0;
}
