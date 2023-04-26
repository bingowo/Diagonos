#include<stdio.h>
#include<string.h>
#define N 120
int gcd(int a, int b)
{
    if(a<=b)a,b=b,a;
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; i++)
    {
        char s[122];
        fgets(s,sizeof s,stdin);
        int j=strlen(s);
        int cnt = 0;//1的个数
        for(int k=0;s[i]!='\n';k++)
        {
            unsigned char c=s[k];
            for (int m = 0; m < 8; m++)
            {
                cnt += c % 2;
                c >>= 1;
            }
        }
        int g = gcd(j * 8,cnt);
        printf("%d/%d\n",cnt / g,j * 8 / g);
    }
    return 0;
}
