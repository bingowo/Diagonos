#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int GCD(int m,int n)
/* 找最大公约数m<n*/
{
    for(int i=0;i<m;i++)
    {
        long long int x=m-i;
        if((m%x==0)&&(n%x==0)) return x;
    }
}
int power(int base,int n)
{
    int i;
    int p;
    p=1;
    for(i=0;i<n;i++)
        p=p*base;
    return p;
}
int main()
{
    char s[100];
    scanf("%s",s);
    int i=0;
    int len=strlen(s);
    for(;s[i]!='.';i++) ;
    long long int x1=0,x2=0;
    for(int j=0;j<i;j++)
    {
        if(s[j]!='2') x1+=(s[j]-'0')*power(3,i-j-1);
        else x1+=(-1)*power(3,i-j-1);
    }
    int n=len-i-1;
    int y=power(3,n);
    for(int j=0;j<n;j++)
    {
        x2+=(s[len-j-1]-'0')*power(3,j);
    }
    if(x2>0&&y>0)
    {
        long long int gc=GCD(x2,y);
        printf("%lld %lld %lld\n",x1,x2/gc,y/gc);
    }
    else if(x2<0&&y<0)
    {
        x2=-x2;y=-y;
        long long int gc=GCD(x2,y);
        printf("%lld %lld %lld\n",x1,x2/gc,y/gc);
    }
    else
    {
        x1=-x1;
        if(x2<0) x2=-x2;
        if(y<0) y=-y;
        long long int gc=GCD(x2,y);
        printf("%lld %lld %lld\n",x1,x2/gc,y/gc);
    }
    return 0;
}
