#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

long long s,s1;
int k=0;

int huiwen(long s)
{
    char str[11];int i,j,flag=0;
    sprintf(str,"%lld",s);s1=0;
    for(i=strlen(str)-1;i>=0;i--)
    {
        s1=s1*10+str[i];
        if(str[i]!=str[strlen(str)-i-1])flag=-1;
    }
    if(flag==0)return 0;
    else return 1;
}

void zhuan(long long m,long long n)
{
    s=m+n;
    if(huiwen(s))
    {
        k++;
        return zhuan(s,s1);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    huiwen(n);zhuan(n,s1);
    printf("%d %lld",k,s);
}