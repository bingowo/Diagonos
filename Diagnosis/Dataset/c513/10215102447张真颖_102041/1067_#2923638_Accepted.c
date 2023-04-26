#include <stdio.h>
#include <stdlib.h>

long long arr[74]={0};
long long t(int n)
{
    if(n==0) {arr[n]=0;return 0;}
    else if(n==1||n==2) {arr[n]=1;return 1;}
    else
    {
        if(arr[n]==0) arr[n]=t(n-1)+t(n-2)+t(n-3);
        return arr[n];
    }
}

int main()
{
    int T=0;
    scanf("%d",&T);

    for(int i=0;i<T;i++)
    {
        int n=0;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,t(n));
    }
    return 0;
}
