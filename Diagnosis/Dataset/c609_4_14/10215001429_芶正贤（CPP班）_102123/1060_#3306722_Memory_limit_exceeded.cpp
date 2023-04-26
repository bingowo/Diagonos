#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> expandString(string str) 
{
    vector<string> result;
    if (str.empty()) 
    {
        result.push_back("");
        return result;
    }

    char c = str[0];
    string remaining = str.substr(1);
    vector<string> sub = expandString(remaining);

    for (string s : sub) 
    {
        string temp=c+s;
        result.push_back(temp);
        result.push_back(c + temp);
    }

    return result;
}

int main()
{
    string stand;
    cin>>stand;
    vector<string> arr;
    arr = expandString(stand);
    for(auto &a:arr)
    {
        if(stand.compare(a)>0)
            stand = a;
    }
    cout<<stand<<endl;
    
}