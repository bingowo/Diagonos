#include <stdio.h>
#include <string.h>

int gcd(int a,int b)
{
    if(a==b)return a;
    if(a<b)
    {
        int t=a;
        a=b;
        b=t;
    }
    if(b==0)return a;
    else return gcd(b,a%b);
}

int main()
{
    int n,cnt=0;
    int num;
    scanf("%d",&n);
    char s[121];
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        int len=strlen(s);
        num=8*len;
        for(int j=0;j<len;j++)
        {
            for(int k=0;k<8;k++)
            {
                if((s[j]>>k)&1)cnt++;
            }
        }
        num/=gcd(num,cnt);
        cnt/=gcd(num,cnt);
        printf("%d/%d\n",cnt,num);
    }
    return 0;
}
