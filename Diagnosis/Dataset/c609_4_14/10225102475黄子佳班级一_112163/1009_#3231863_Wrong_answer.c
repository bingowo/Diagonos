#include <stdio.h>
#include <string.h>

int gcd(int a,int b)
{
    if(a<b)
    {
        int t=a;
        a=b;
        b=t;
    }
    if(a%b==0)return b;
    else return gcd(b,a%b);
}

int main()
{
    int n,cnt=0;
    int num=0;
    scanf("%d",&n);
    getchar();
    char s[121];
    for(int i=0;i<n;i++)
    {
        gets(s);
        int len=strlen(s);
        num=len*8;
        for(int j=0;j<len;j++)
        {
            for(int k=0;k<8;k++)
            {
                if((s[j]>>k)&1)cnt++;
            }
        }
        int t=gcd(cnt,num);
        num/=t;
        cnt/=t;
        printf("%d/%d\n",cnt,num);
    }
    return 0;
}

