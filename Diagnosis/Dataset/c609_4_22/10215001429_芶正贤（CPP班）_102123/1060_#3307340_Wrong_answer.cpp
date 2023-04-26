#include<iostream>
#include<string>
#include<vector>
using namespace std;

string minString(string str) 
{
    string min=str;
    int size=str.length();
    string temp;
    for (int i = 0; i<size; i++) //取第i个字符
    {
        string c;
        c = str[i];
        
        temp=min;
        
        // 将c插入到result中的每个位置形成新的字符串，并将其与result中的字符串进行比较
        temp.insert(i+1,c);
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