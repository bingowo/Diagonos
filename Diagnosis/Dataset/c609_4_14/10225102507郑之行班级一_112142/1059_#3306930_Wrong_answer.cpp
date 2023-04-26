#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cmp(string a,string b)
{
    string a1=a.substr(0,a.length());
    string b1=b.substr(0,b.length());

    string::iterator s1 = a1.begin();
    string::iterator s2 = b1.begin();
    int sign1=1,sign2=1;

    if(*s1=='-')sign1=-1,s1++;
    else if (*s1=='+')a1=a1.substr(1,a1.length()-1);
    if(*s2=='-')sign2=-1,s2++;
    else if (*s2=='+')b1=b1.substr(1,b1.length()-1);

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

    if (sign1>0)return a1<b1;
    else return a1>b1;

    return 0;
}

int main()
{
    int n;cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++)
        cin >> s[i];
    sort(s.begin(),s.end(),cmp);
    for (int i=0;i<n;i++)
        cout<<s[i]<<endl;
    return 0;
}
