#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

long long int ten(int n)
{
    long long int temp=1;
    for(int i=0;i<n;i++) temp*=10;
    return temp;
}
long long int yue(long long int a,long long int b)//a>b   不能约return 0
{
    int bo=1;
    for(int i=2;i<=a;i++)
    {
        if(a%i==0&&b%i==0) {return i;}
    }
    return bo;
}
void fen(long long int *x,long long int *y)
{
    long long int t=yue(*x,*y);
    while(t!=1)
    {
        (*x)=(*x)/t;(*y)=(*y)/t;
        t=yue((*x),(*y));
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int f=0;f<t;f++)
    {
        char s[100];
        scanf("%s",s);int len=strlen(s);int bo=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='[') {bo=1;break;}
        }
        if(bo==1)
        {
            int a=0,b=0,n=0,xun=0,xiao=0;
            for(int i=0;i<len;i++)
            {
                while(isdigit(s[i])) a=a*10+(s[i++]-'0');
                i++;
                while(isdigit(s[i])) {xiao=xiao*10+(s[i++]-'0'),b++;}
                if(s[i]=='[') i++;
                while(isdigit(s[i])) {xun=xun*10+(s[i++]-'0');n++;}
            }
            //printf("%d %d %d %d",a,b,n,xun);
            long long int x,y;b=b+n;
            if(b>n)
            {
                x=xun,y=ten(b)-ten(b-n);
            }
            else//n>b
            {
                x=xun*ten(n-b),y=ten(n)-1;
            }

            long long int *x1=&x,*y1=&y;
            fen(x1,y1);
            x=xiao*y+x*ten(b);y=y*ten(b);
            fen(x1,y1);
            printf("case #%d:\n",f);
            if(y!=1) printf("%lld/%lld\n",a*y+x,y);
            if(y==1) printf("%lld\n",a*y+x);
        }
        else
        {
            int a=0,b=0,n=0;
            for(int i=0;i<len;i++)
            {
                while(isdigit(s[i])) a=a*10+(s[i++]-'0');
                i++;
                while(isdigit(s[i])) {b=b*10+(s[i++]-'0');n++;}
            }
            long long int x=b,y=ten(n);
            long long int *x1=&x,*y1=&y;
            fen(x1,y1);
            printf("case #%d:\n",f);
            if(y!=1) printf("%lld/%lld\n",a*y+x,y);
            if(y==1) printf("%lld\n",a*y+x);
        }
    }
    return 0;
}