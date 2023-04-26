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
        vector<string> temp;

        // 将c插入到result中的每个位置形成新的字符串，并将其与result中的字符串进行比较
        for (int j = 0; j <= result.length(); j++)
        {
            string s = result;
            s.insert(j, c);
            if (s < result) {
                result = s;
            }
            temp.push_back(s);
        }

        // 将新的字符串加入result中
        for (string s : temp)
        {
            if (s < result) {
                result = s;
            }
        }
    }

    return result;
}


int main()
{
    string stand;
    cin>>stand;
    string arr;
    arr = minString(stand);
    cout<<arr<<endl;
}