#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gcd(int a, int b)
{
    return a ? gcd(b % a, a) : b;
}

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for (int i = 0; i < t; i++)
    {
        char s[130];
        scanf("%s",s);
        //char s[130];
        //cout <<"**"<< s<<"**" << endl;
        //counts 1
        int cnt = 0;
        //int len = strlen(s);
        int len = strlen(s);
        for (int j = 0; j < len; j++)
        {
            char c = s[j];
            for (int m = 0; m < 8; m++)
            {
                cnt += c % 2;
                c >>= 1;
            }
        }
        int g = gcd(cnt, len * 8);
        printf("%d",cnt / g);printf("/");printf("%d\n",len * 8 / g );

    }
    return 0;
}