#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmpD(const int elem1,const int elem2)
{
    return elem1>elem2;
}

bool cmpA(const int elem1,const int elem2)
{
    return elem1<elem2;
}

int main()
{
    char ch;
    cin>>ch;
    vector<int> v;
    int n;
    while (cin>>n) v.push_back(n);
    int len=v.size();
    vector<int> v1;
    if (len==1)
    {
        cout<<v[0];
        return 0;
    }
    if (ch=='A')
    {
        sort(v.begin(),v.end(),cmpA);
        unique_copy(v.begin(),v.end(),back_inserter(v1));
    }
    else
    {
        sort(v.begin(),v.end(),cmpD);
        unique_copy(v.begin(),v.end(),back_inserter(v1));
    }
    for (auto e: v1)
        cout<<e<<' ';
    return 0;
}