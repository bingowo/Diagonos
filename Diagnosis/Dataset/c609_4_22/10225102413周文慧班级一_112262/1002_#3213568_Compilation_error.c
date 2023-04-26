#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b)
{
    return a ? gcd(b % a, a) : b;
}

int main()
{
    int t; cin >> t;
    getchar();
    for (int i = 0; i < t; i++)
    {
        string s; getline(cin, s);
        //char s[130]; 
        //cout <<"**"<< s<<"**" << endl;
        //counts 1
        int cnt = 0;
        //int len = strlen(s);
        int len = s.length();
        for (int j = 0; j < len; j++)
        {
            unsigned char c = s[j];
            for (int m = 0; m < 8; m++)
            {
                cnt += c % 2;
                c >>= 1;
            }
        }
        int g = gcd(cnt, len * 8);
        cout << cnt / g << "/" << len * 8 / g << endl;
    }
}
