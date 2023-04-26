#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

bool cmp(string a,string b)
{
    string::iterator it1=a.begin(),it2=b.begin();
    int sign1=1,sign2=1;
    if(*it1=='-') sign1 = -1,it1++;
    else if(*it1=='+') it1++;
    if(*it2=='-') sign2 = -1,it2++;
    else if(*it2=='+') it2++;

    if(sign1 != sign2) return sign1<sign2;

    string::iterator p1=it1,p2=it2;
    for(;*p1 && *p1!='.';p1++);
    for(;*p2 && *p2!='.';p2++);

    int len1 = p1-it1;
    int len2 = p2-it2;

    if(len1 != len2){
        if(sign1>0) return len1<len2;
        else return len1>len2;
    }
    else{
        if(a[0]!='+'&&b[0]!='+'){
            if(sign1>0) return a<b;
            else return a>b;
        }else{
            if(sign1>0) return a>b;
            else return a<b;
        }
    }
}

int main()
{
    int n,i;
    cin >> n;
    vector<string> s(n);
    for(i=0;i<n;i++)
        cin >> s[i];
    sort(s.begin(),s.end(),cmp);
    for(auto e:s)
        cout << e << endl;
    return 0;
}

