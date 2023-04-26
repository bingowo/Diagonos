#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int NUM[31];
long long int count(int n)
{
    if(NUM[n]!=0)return NUM[n];
    else
    {
        NUM[n]=2*count(n-1);
        return NUM[n];
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    int i,n;
    for(i=0;i<31;i++)
    {
        NUM[i]=0;
    }
    NUM[0]=1;NUM[1]=2;NUM[2]=4;NUM[3]=8;
    long long int res;
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        res=count(n);
        printf("case #%d:\n",i);
        printf("%lld\n",res);
    }
    return 0;
}
