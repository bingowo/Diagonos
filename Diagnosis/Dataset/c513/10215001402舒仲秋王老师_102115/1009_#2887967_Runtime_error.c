#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int turn(char n)
{
    int flag,a,b=1;
    for(int i=0;i<8;i++)
    {
        b=1<<i;
        a=n&b;
        if(a!=0) flag+=1;
    }
    return flag;
}

int GCD(int m,int n)
{
    int q,p;
    if(m<=n) {p=m;q=n;}
    else {q=m;p=n;}
    int ret;
    if(p==1) ret=1;
    else if(q%p==0) ret=p;
    else ret=GCD(p,q%p);
    return ret;
}

int main()
{
    int n,i,j,q;char s[150];
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        int sum=0;
        for(j=0;(s[j]=getchar())!='\n';j++);
        s[j]='\0';
        for(q=0;q<j;q++) sum+=turn(s[q]);
        int l=8*strlen(s);
        int SUM1=sum/GCD(sum,l),SUM2=l/GCD(sum,l);
        printf("%d/%d",SUM1,SUM2);
    }
    return 0;
}
