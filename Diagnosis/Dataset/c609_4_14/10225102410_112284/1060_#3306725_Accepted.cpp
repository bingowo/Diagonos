#include <iostream>
#include <string>

using namespace std;

string insert(string s,int pos)
{
    string t = s;
    int i;
    for(i = t.length();i > pos;i--) t[i] = t[i - 1];
    return t + t[t.length()];

}



int main()
{
    string s,t;
    int i,len;

    for( cin >> s,len = s.length(),i = 0;i < len;i++)
    {
        t = s;
        if(insert(t,i).compare(s) < 0)  {s = insert(t,i);len++;i++;}
    }

    cout << s;
    return 0;
}
