#include <stdio.h>
#include <stdlib.h>

#define N 10000000

long long  arr[N+1]={0,1,3,6};

int main()
{
    long long n;
    scanf("%lld",&n);
    for (int i=4;i<=N;i++)
        arr[i]=arr[i-1]+i;
    long long m=n/2,t;
    int cnt;
    for (int i=0;i<=N;i++)
        if (arr[i]<=m && arr[i+1]>m)
            cnt=i;
    t=n-arr[cnt]*2;
    if (t<=cnt+1)   //vertical
    {
        if (cnt%2==0)   //right
            printf("(%d,%d)\n",cnt/2,-(cnt/2)+t);
        else //left
            printf("(%d,%d)\n",-(cnt/2+1),cnt/2+1-t);
    }
    else
    {
        if (cnt%2==0)
            printf("(%d,%d)\n",cnt/2-(t-cnt-1),cnt/2+1);
        else
            printf("(%d,%d)\n",-(cnt+1)/2+(t-cnt-1),-(cnt/2+1));
    }


    return 0;
}
