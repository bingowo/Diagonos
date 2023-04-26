#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int cmp(string a,string b)
{
    string::iterator s1 = a.begin();
    string::iterator s2 = b.begin();
    int sign1=1,sign2=1;

    if(*s1=='-')sign1=-1,s1++;
    else if (*s1=='+')s1++;
    if(*s2=='-')sign2=-1,s2++;
    else if (*s2=='+')s2++;

    if(sign1!=sign2)return sign1<sign2;

    string::iterator p1 = s1;
    string::iterator p2 = s2;
    for(;*p1 && *p1!='.';p1++);
    for(;*p2 && *p2!='.';p2++);

    int len1=p1-s1,len2=p2-s2;

    if (len1 != len2){
        if (sign1>0)return len1<len2;
        else return len1>len2;
    }

    if (sign1>0)return s1<s2;
    else return s1>s2;

    return 0;
}

int main()
{
    int n;cin>>n;
    string s[n];
    for (int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    sort(s,s+n,cmp);
    for (int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}
