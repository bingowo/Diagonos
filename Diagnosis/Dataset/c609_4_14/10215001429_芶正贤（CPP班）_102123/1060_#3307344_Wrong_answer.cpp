#include<iostream>
#include<string>
#include<vector>
using namespace std;

string minString(string str) 
{
    string min=str;
    int size=str.length();
    for (int i = 0; i<size; i++) //取第i个字符
    {
        char c;
        c = str[i];
        
        
        
        // 将c插入到result中的每个位置形成新的字符串，并将其与result中的字符串进行比较
        
        string temp = min.substr(0, i+1) + c + min.substr(i+1);
        if(temp<=min)
        {
            min=temp;
            size=str.length();
            i++;
        }
    }

    return min;
}


int main()
{
    string stand;
    cin>>stand;
    string arr;
    arr = minString(stand);
    cout<<arr<<endl;
}