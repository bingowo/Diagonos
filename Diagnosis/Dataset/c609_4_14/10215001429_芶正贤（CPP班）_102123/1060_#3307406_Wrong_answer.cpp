#include<iostream>
#include<string>
#include<vector>
using namespace std;

string minString(string str) 
{
    string min=str;
    int size=str.length();
    int i=0;
    char c;
    string temp;
    while(i<size)
    {
        
        c = str[i];
       
        temp = min.substr(0, i+1) + c + min.substr(i+1);
        if(temp<=min)
        {
            min=temp;
            size++;
            i++;
        }
        i++;
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