#include <stdio.h>
#include <stdlib.h>
void itob(long long int n,char s[100],int r)
{
    int flag=1,i=0,d;
    char t;
    if (n<0){flag=-1;n=-n;}
    for(int x=0;x<100;x++)
        s[x]='\0';
    while (n>0)
    {
        d=n%r;
        n=n/r;
        if(d>=0&&d<=9)
        {
            s[i++]=d+48;
        }
        if(d>9)
            s[i++]=d+55;
    }
    if(flag!=1)s[i++]='-';
    i-=1;
    for(int j=0;i>j;i--,j++)
    {
        t=s[i];
        s[i]=s[j];
        s[j]=t;
    }
}
int main()
{
    int t,r;
    char s[100];
    long long int n;
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%lld %d",&n,&r);
        itob(n,s,r);
        printf("%s\n",s);
        t--;
    }
    return 0;
}
