#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
/* 将16进制转换成2进制，循环读取二进制，即读取余数，逆运算的a+bi;按要求输出 */
typedef long long lli;
void HEXTOBIT(char s[],char bi[])
{
    int len =strlen(s);
    int index=3,num=0;
    for(int i=0; i<len; i++)
    {
        num=isdigit(s[i])?(s[i]-'0'):(s[i]-'A'+10);
        for (int j=0; j<4; j++)
        {
           if(num!=0)
           {
               bi[index--]=num%2+'0';
               num/=2;
           }
           else bi[index--]='0';
        }
        index+=8;
    }
    bi[index-3]=0;
}

void PRINT(lli a, lli b)
{
    if(a==0)
    {
        if(b==0) printf("%d",0);
        else if (b==1) printf ('i');
        else if(b==-1) printf("-i");
        else printf("%lldi",b);
    }
    else
    {
        if(b==0)  printf("%lld",a);
        else if (b==1||b==-1) printf ("%lld%ci",a,b>0?'+':'-');
        else printf("%lld%c%lldi",a,b>0?'+':'-',b>0?b:-b);
    }
}

int main()
{
    char s[50],bi[200];
    scanf("%s",s);
    int len =strlen(s);
    memmove(s,s+2,len-1);//把结束符也copy过去
    HEXTOBIT(s,bi);
    lli qr=0,qi=0,a=0,b=0;
    int r=0;
    for(int i=0; bi[i]; i++)
    {
       r=bi[i]-'0';
       a=-qr-qi+r;
       b=qr-qi;
       qr=a;qi=b;
    }
    PRINT(a,b);
    return 0; 
}