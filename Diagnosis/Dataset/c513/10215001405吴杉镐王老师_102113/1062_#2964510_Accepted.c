#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T,n;
unsigned long long num[10005];
int main()
{
    scanf("%d",&T);
    for(int i=1;i<=50;i++)
        num[i]=0;
    num[0]=1;
    for(int i=0;i<50;i++)
    {
        num[i+1]+=num[i];
        num[i+2]+=num[i];
        num[i+3]+=num[i];
        num[i+4]+=num[i];
    }
    for(int i=0;i<T;i++)
    {
        int x;
        scanf("%d",&x);
        printf("case #%d:\n%llu\n",i,num[x]);
    }
    return 0;
}
