#include<iostream>
#include<string>
#include<vector>
using namespace std;


string minString(string str) 
{
    string result;

    for (int i = 0; i < str.length(); i++) 
    {
        string c;
        c = str[i];

        // 对于每个字符，将其与result中的每个字符串拼接，并将结果加入result中
        for (char s : result) 
        {
            string temp = c+s;
            if(result>temp)
            {
                result = temp;
            }
            if(result>s+temp)
            {
                result = s+temp;
            }
        }

        
    }

    return result;
}

/*
string minString(string str) 
{
    string min;
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
}*/

int main()
{
    string stand;
    cin>>stand;
    string arr;
    arr = minString(stand);
    cout<<arr<<endl;
    
}