#include <stdio.h>
#include <string.h>
int gcd(int a, int b)
{
    return a ? gcd(b % a, a) : b;
}

int main()
{
    int t; 
    scanf("%d",&t);
    for (int i = 0; i < t; i++)
    {
        char s;
        int cnt = 0;
        //int len = strlen(s);
        int len = s.length();
        while((s=getchar())!=EOF)
        {
            int j=0;
            unsigned char c = s[j];
            j++;
            for (int m = 0; m < 8; m++)
            {
                cnt += c % 2;
                c >>= 1;
            }
        }
        int g = gcd(cnt, len * 8);
        printf("%d/%d\n",cnt / g,len * 8 / g);
    }
}
