//#include <iostream>
#include <string.h>
//using namespace std;
#include<stdio.h>

int gcd(int a, int b)
{
    return a ? gcd(b % a, a) : b;
}

int main()
{
    int t; 
    //cin >> t;
    scanf("%d",&t);
    getchar();
    for (int i = 0; i < t; i++)
    {
        //string s; 
        char s[1000];
        //getline(cin, s);
        scanf("%s",s);
        int cnt = 0;
        //int len = s.length();
        int len = strlen(s);
        for (int j = 0; j < len; j++)
        {
            unsigned char c = s[j];
            int m;
            for ( m = 0; m < 8; m++)
            {
                cnt += c % 2;
                c >>= 1;
            }
        }
        int g = gcd(cnt, len * 8);
        //cout << cnt / g << "/" << len * 8 / g << endl;
        printf("%d/%d\n",cnt/g,len*8/g);
    }
    return 0;
}