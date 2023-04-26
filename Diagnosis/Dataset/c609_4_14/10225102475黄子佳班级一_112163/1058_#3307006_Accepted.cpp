#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct BIGINT{int cnt{};vector<int> v;};
void DIV2(BIGINT &p);
void ADD1(BIGINT &p);

int main()
{
    string s;
    cin>>s;
    int len=s.length();
    int sign=1;
    BIGINT n;
    for(int i=len-1;i>0;i--)
    {
        n.v.push_back(s[i]-'0');
        n.cnt++;
    }
    if(s[0]=='-')sign=-1;
    else
    {
        n.v.push_back(s[0]-'0');
        n.cnt++;
    }

    int temp{};
    vector<int> bin;
    int cnt{};
    while(n.cnt>0)
    {
        temp=n.v[0]%2;
        bin.push_back(temp);
        cnt++;
        DIV2(n);
        if(sign==-1&&temp)
        {
            if(n.cnt==0)
            {
                n.cnt++;
                n.v[0]=1;
            }
            else ADD1(n);
        }
        sign=-sign;
    }
    for(int i=cnt-1;i>=0;i--)
    {
        cout<<bin[i];
    }
    return 0;
}

void DIV2(BIGINT &n)
{
    int carry{};
    if(n.v[n.cnt-1]<2)
    {
        n.cnt--;
        carry=1;
    }
    for(int i=n.cnt-1;i>=0;i--)
    {
        int t=10*carry+n.v[i];
        n.v[i]=t/2;
        carry=t%2;
    }
}

void ADD1(BIGINT &n)
{
    int carry{},i=1;
    n.v[0]++;
    carry=n.v[0]/10;
    n.v[0]%=10;
    while(carry&&i<n.cnt)
    {
        n.v[i]+=carry;
        carry=n.v[i]/10;
        n.v[i]%=10;
        i++;
    }
    if(carry)
    {
        n.v[i]=carry;
        n.cnt++;
    }
}