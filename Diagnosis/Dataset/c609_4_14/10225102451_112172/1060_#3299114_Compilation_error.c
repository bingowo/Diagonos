#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string A;
    cin>>A;
    int l=A.size();
    int difpos{};
    vector<char> ans;
    for(int i=0;i<l;i++)
    {
        //difpos=i;
        while(difpos<l && A[i]==A[difpos])
            difpos++;
        if(difpos<l && A[difpos]>A[i])
            ans.push_back(A[i]);
        ans.push_back(A[i]);
    }
    for(auto e:ans)
        cout<<e;
    return 0;
}