#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1,s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        s1=s;
        s.insert(i,1,s[i]);
        if(s>s1)
        {
            s=s1;
        }
        else i++;
    }
    cout<<s;
    return 0;
}
