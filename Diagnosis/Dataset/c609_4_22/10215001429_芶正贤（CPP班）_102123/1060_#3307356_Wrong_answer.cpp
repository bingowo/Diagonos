#include<iostream>
#include<string>
#include<vector>
using namespace std;

string minString(string str) 
{
    string min=str;
    int size=str.length();
    int i=0;
    do
    {
        char c;
        c = str[i];
       
        string temp = min.substr(0, i+1) + c + min.substr(i+1,min.length()-i-1);
        if(temp<=min)
        {
            min=temp;
            size++;
            i++;
        }
        i++;
    }while(i<size);

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