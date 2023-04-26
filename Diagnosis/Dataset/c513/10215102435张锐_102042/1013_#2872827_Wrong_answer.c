#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int m,int n)
/* 找最大公约数m<n*/
{
    for(int i=0;i<m;i++)
    {
        int x=m-i;
        if((m%x==0)&&(n%x==0)) return x;
    }
}
int power(int base,int n)
{
    int i;
    int p;
    p=1;
    for(i=1;i<=n;i++)
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
    int x=0;
    for(int j=0;j<i;j++)
    {
        if(s[j]!='2') x+=(s[j]-'0')*power(3,i-j);
        else x+=(-1)*power(3,i-j);
    }
    printf("%d ",x);
    int n=len-i-1;
    int y=power(3,n);
    x=0;
    for(int j=0;j<n;j++)
    {
        x+=power(3,j);
    }
    int gc=GCD(x,y);
    printf("%d %d\n",x/gc,y/gc);
    return 0;
}
