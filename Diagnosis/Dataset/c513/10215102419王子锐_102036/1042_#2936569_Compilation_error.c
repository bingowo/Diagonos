#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    int T;cin>>T;
    for(int m=0;m<T;m++)
    {
        string s;cin>>s;
        sort(s.begin(),s.end());
        s.resize(unique(s.begin(),s.end())-s.begin());

        int ll=s.size();
        int sum=~((-1)<<ll)+1;

        set<string> ans;
        while(sum-->1)
        {
            string tmp;
            for(int d=1,i=0;i<ll;d=d<<1,i++)
                if(sum&d) tmp+=s[i];
            ans.insert(tmp);
        }
        printf("case #%d:\n",m);
        for(string x:ans)cout<<x<<endl;


    }
    return 0;
}