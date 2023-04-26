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
        char s;
        int cnt = 0;
        //int len = strlen(s);
        while((s=getchar())!=EOF)
        {
            int j=0;
            unsigned char c = s
            j++;
            for (int m = 0; m < 8; m++)
            {
                cnt += c % 2;
                c >>= 1;
            }
        }
        int g = gcd(cnt, j * 8);
        printf("%d/%d\n",cnt / g,j * 8 / g);
    }
}
