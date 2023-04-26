#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int cas=0;cas<T;cas++)
    {
        string str;
        map<char,int> a;
        int R=0;
        cin>>str;
        int len=str.length();
        a.clear();//删除所有元素
        a[str[0]]=1;
        for(int j=0;j<len;j++)
        {
            if(a.find(str[j])==a.end())
            {
                a[str[j]]=R;
                R=R?R+1:2;//******
            }
        }
        if(R<2) R=2;

        long long N=0;
        for(int j=0;j<len;j++)
        {
            N*=R;
            N+=a[str[j]];
        }
        cout<<"case #"<<cas<<":"<<endl<<N<<endl;
    }
    return 0;
}

