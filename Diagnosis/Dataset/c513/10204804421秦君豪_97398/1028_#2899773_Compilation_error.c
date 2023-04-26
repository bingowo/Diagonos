#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    char judge;int n;
    vector<int>num;
    cin>>judge;
    vector<int>newnum;
    cin.get();
    while(cin>>n)
    {
        num.push_back(n);
        if(cin.get()=='\n') break;
    }
    newnum.resize(num.size());
    if(judge=='A') 
    {
        sort(num.begin(),num.end());
    } 
    else sort(num.begin(),num.end(),greater<int>());
    vector<int>::iterator it;
//    unique_copy(num.begin(),num.end(),newnum.begin());
    newnum.erase(unique_copy(num.begin(), num.end(), newnum.begin()) ,newnum.end());
    for(it=newnum.begin();it!=newnum.end();it++)
    {
        if(it==newnum.begin()) cout<<*it;
        else cout<<" "<<*it;

    }
    cout<<endl;
    system("pause");
    return 0;
}