#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cl(int a)
{
    int cnt=0;
    for(int i=0;i<8;i++)
    {
        if(a&1)cnt++;
        a=a>>1;
    }
    return cnt;
}
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++)
    {
        char a[150];
        gets(a);
        int len=strlen(a);
        int cnt=0;
        for(int i=0;i<len;i++)
        {
            int b=(int)a[i];
            cnt=cnt+cl(b);
        }
        int temp=gcd(len*8,cnt);
        printf("%d/%d\n",cnt/temp,8*len/temp);
    }
    return 0;
}
