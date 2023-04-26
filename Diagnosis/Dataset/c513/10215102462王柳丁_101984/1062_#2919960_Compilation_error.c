#include <stdio.h>
#include <stdlib.h>
long long int NUM[51];
int k;

long long int count(long long int a)
{
    if(NUM[a]==-1){NUM[a]=count(a-1)+count(a-2)+count(a-3)+count(a-4);return NUM[a];}
    else if(NUM[a]!=-1)return NUM[a];
    return res;
}

int main()
{
    for(k=0;k<51;k++)
    {
        NUM[k]=-1;
    }
    NUM[1]=1;NUM[2]=2;NUM[3]=4;NUM[4]=8;
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        long long int n;
        scanf("%lld",&n);
        long long int res=count(n);
        printf("case #%d:\n",i);
        printf("%lld\n",res);
    }
    return 0;
}
