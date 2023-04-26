#include<stdio.h>

int main()
{
    int n,r,a,b,t=0;scanf("%d%d",&n,&r);
    char c[37],res[33];
    for(int i=0;i<10;i++) c[i]=i+'0';
    for(int i=10;i<36;i++) c[i]=i-10+'A';
    if(n==0) res[t++]='0';
    while (n!=0)
    {
        a=n/r,b=n%r;
        if(b<0) {a++,b-=r;}
        res[t++]=c[b];
        n=a;
    }
    for(int i=t-1;i>=0;i--) printf("%c",res[i]);

    return 0;
}