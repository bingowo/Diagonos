#include <stdio.h>
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
        char s[121];
        int cnt = 0;
        int j=0;
        //int len = strlen(s);
        while((scanf("%c",s[j])==1)
        {
            j++;
        }
        for(int k=0;k<j;k++)
        {
            unsigned char c=s[k];
            for (int m = 0; m < 8; m++)
            {
                cnt += c % 2;
                c >>= 1;
            }
        }
        int g = gcd(cnt, j * 8);
        printf("%d/%d\n",cnt / g,j * 8 / g);
    }
    return 0;
}
