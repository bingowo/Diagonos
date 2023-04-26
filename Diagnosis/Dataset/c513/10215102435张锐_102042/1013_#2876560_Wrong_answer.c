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
long long int power(int base,int n)
{
    int i;
    long long int p;
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
    for(;s[i]!='.'&&i<len;i++) ;
    long long int x1=0;int x2=0;
    for(int j=0;j<i;j++)
    {
        if(s[j]!='2') x1+=(s[j]-'0')*power(3,i-j-1);
        else x1+=(-1)*power(3,i-j-1);
    }
    int n=len-i-1;
    int y=power(3,n);
    for(int j=0;j<n;j++)
    {
        if(s[len-j-1]!='2') x2+=(s[len-j-1]-'0')*power(3,j);
        else x2+=(-1)*power(3,j);
    }
    if(x2>0&&x1!=0)
    {
        if(x2>y)
        {
            int more=x2/y;
            x1+=more;
            x2=x2%y;
        }
        int gc=GCD(x2,y);
        printf("%lld %d %d\n",x1,x2/gc,y/gc);
    }
    else if(x2<0&&x1!=0)
    {
        int less=x2/y+1;
        x1-=less;x2=y+x2%y;
        int gc=GCD(x2,y);
        printf("%lld %d %d\n",x1,x2/gc,y/gc);
    }
    else if((x2==0||y==0)&&x1!=0)
    {
        printf("%lld\n",x1);
    }
    else if(x1!=0)
    {
        x1=-x1;
        if(x2<0) x2=-x2;
        if(y<0) y=-y;
        int gc=GCD(x2,y);
        printf("%lld %d %d\n",x1,x2/gc,y/gc);
    }
    else if(x1==0&&x2!=0&&y!=0)
    {
        if(x2<0) x2=-x2;
        if(y<0) y=-y;
        int gc=GCD(x2,y);
        printf("%d %d\n",x2/gc,y/gc);
    }
    else if(x1==0&&x2==0)
        printf("0\n");
    return 0;
}
