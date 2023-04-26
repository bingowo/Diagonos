#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> expandString(string str) 
{
    vector<string> result;

    for (int i = 0; i < str.length(); i++) 
    {
        char c = str[i];

        // 对于每个字符，将其与result中的每个字符串拼接，并将结果加入result中
        vector<string> new_results;
        for (string s : result) 
        {
            string temp = c + s;
            new_results.push_back(temp);
            new_results.push_back(c + temp);
        }

        // 将新的结果替换旧的结果
        result = new_results;
        if (result.empty()) 
        {
            result.push_back("");
        }
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