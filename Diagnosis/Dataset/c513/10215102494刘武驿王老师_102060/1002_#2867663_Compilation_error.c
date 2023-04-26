#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int n,i,j,k,temp,t;
    cin >> n;
    for (i = 0;i < n;i++)
    {
        temp = 2;
        string s;
        map<char,int>a;
        long long int sum = 0;
        cin >> s;
        a[s[0]] = 1;
        for (j = 1;j < s.size();j++)
        {
            if (a[s[j]] == 0)
            {
                a[s[j]] = 0;
                break;
            }
        }
        for (k = j+1;k < s.size();k++)
        {
            if (a[s[k]] == 0 && s[k] != s[j])
            {
                a[s[k]] = temp;
                temp++;
            }
        }
        for (t = 0;t < s.size();t++)
        {
            sum = sum * temp;
            sum += a[s[t]];
        }
        cout << "case #" << i << ":" << endl;
        cout << sum << endl;
    }
    return 0;
}
