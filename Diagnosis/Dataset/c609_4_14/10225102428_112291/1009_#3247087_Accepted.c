#include<stdio.h>
#include<string.h>
int gcd(int a, int b)
{
    return a%b?gcd(b,a%b):b;
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();//读取换行符
    for (int i = 0; i < t; i++)
    {
        char s[122];
        fgets(s,sizeof(s),stdin);
        int cnt = 0;//1的个数
        int cnt2=0;
        for(int k=0;s[k]!='\n';k++)
        {
            unsigned char c=s[k];
            for (int m = 0; m < 8; m++)
            {
                cnt += c % 2;
                c >>= 1;
            }
            cnt2+=8;
        }
        int g = gcd(cnt,cnt2);
        printf("%d/%d\n",cnt / g,cnt2 / g);
    }
    return 0;
}