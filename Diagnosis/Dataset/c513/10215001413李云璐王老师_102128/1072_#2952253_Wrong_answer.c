#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

long long int min(long long int a,long long int b)
{
    if(a>=b) return b;
    else return a;
}

long long int q(long long int x,long long int y)
{
    long long int a;
    a=fabs(x)+fabs(y);
    return a;
}

void chuli(long long x,long long y,int bu,char*a)
{
    long long int yi=pow(2,bu-1);
    long long int e=x-yi,w=x+yi,s=y+yi,n=y-yi;
    long long int e1=q(e,y),w1=q(w,y),s1=q(x,s),n1=q(x,n);
    long long int zmin=min(min(min(e1,w1),s1),n1);
    if(zmin==e1) {a[bu-1]='E';x-=yi;}
    if(zmin==w1) {a[bu-1]='W';x+=yi;}
    if(zmin==s1) {a[bu-1]='S';y+=yi;}
    if(zmin==n1) {a[bu-1]='N';y-=yi;}
}


int main()
{
    long long int x,y,bu;
    scanf("%lld%lld",&x,&y);
    if(q(x,y)==0) printf("0");
    else if(q(x,y)%2==0) printf("-1");
    else 
    {
        for(int i=0;i<64;i++)
        if(q(x,y)>=pow(2,i)&&q(x,y)<=pow(2,i+1)) {bu=i+1;break;}
        char a[bu+1];
        a[bu]='\0';
        while(bu!=0)
        {
            chuli(x,y,bu,a);
            printf("%s",a);
            bu--;
        }
    }
    return 0;
}