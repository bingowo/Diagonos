#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int cl(char a)
{
    int num=0;
    for(int i=0;i<8;i++)
    {
        if(a&1)
            num++;
        a=a>>1;
    }
    return num;
}
int main()
{
    int t;
    scanf("%d\n",&t);////////////////////////////////////////////****
    for(int i=0;i<t;i++)
    {
        char s[150];
        gets(s);
        int len=strlen(s),num=0;
        for(int i=0;i<len;i++)
        {
            num=num+cl(s[i]);
        }
        int tmp=gcd(num,len*8);
        printf("%d/%d\n",num/tmp,8*len/tmp);
    }
    return 0;
}
