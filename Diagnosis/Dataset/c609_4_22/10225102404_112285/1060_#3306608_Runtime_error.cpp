#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string s,s1;
    cin>>s;
    int l,d=1;/*d为1则为非升序*/
    l=s.length();
    for(int i = 1;i<l;i++)
    {
        if(s[i-1]<s[i])
        {
            d=0;
            break;
        }
    }
    if(d==1||l==1)
    {
        cout<<s;
        return 0;
    }
    else
    {
        int a;
        for(int i = 0;i<l-1;i++)
        {
            if(s[i]<s[i+1]||s[i]==s[i+1])
            {
                s1[a++]=s[i];
                s1[a++]=s[i];
            }
            else
            {
                s1[a++]=s[i];
            }
        }
        s1[a]=s[l-1];
        for(int k = 0;k<a+1;k++)
        {
            cout<<s1[k];
        }
    }
    return 0;
}

