#include<stdio.h>
#include<stdlib.h>
#define N 120
int one1(unsigned char d)
{
    int r;
    for(r=0;d>0;d>>=1)if(d&1) r++;
    return r;
}
int one0(unsigned char d)
{
    int r;
    for(r=0;d>0;d>>=1)if(!(d&1)) r++;
    return r;
}
int countof1(char s[N])
{
    int i,count1=0;
    for(i=0;s[i]!='\n';i++)
    {
        count1=count1+one1(s[i]);
    }
    return count1;
}
int countof0(char s[N])
{
    int i,count0=0;
    for(i=0;s[i]!='\n';i++)
    {
        count0+=one0(s[i]);
    }
    return count0;
}
int GCD(int num1,int num2)
{
    if(num1<num2)
    {
        int num=num1;
        num1=num2;
        num2=num;
    }
    return num1%num2?GCD(num2,num1%num2):num2;
}
int main()
{
    int T;
    scanf("%d",&T);
    int i;
    char s[N+2];
    for(i=0;i<T;i++)
    {
        fgets(s,N+2,stdin);
        int a=countof1(s);
        int b=strlen(s)*8;
        int c=GCD(a,b);
        int x=a/c;
        int y=b/c;
        printf("%d/%d",x,y);
    }
}