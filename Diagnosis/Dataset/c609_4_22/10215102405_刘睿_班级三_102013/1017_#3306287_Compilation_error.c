#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool pos_cmp(int a,int b)
{
    return (a < b);
}
bool neg_cmp(int a,int b)
{
    return (b < a);
}




int main()
{
    char c;
    cin >> c;
    vector<int>a;
    int b;
    while(cin >> b)
    {
        a.push_back(b);
    }
    if(c == 'A')
    {
        sort(a.begin(),a.end(),pos_cmp);
    }
    else
    {
        sort(a.begin(),a.end(),neg_cmp);
    }
    vector<int>v;
    unique_copy(a.begin(), a.end(),back_inserter(v));
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}

