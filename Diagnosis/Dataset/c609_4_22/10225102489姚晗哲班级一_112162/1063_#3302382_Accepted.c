#include <stdio.h>
#include <stdlib.h>
long long cal(int n)
{
    long long arr[100];
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    arr[4]=8;
    for(int i=5;i<n+1;i++)
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4];
    return arr[n];
}
int main()
{
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {

        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,cal(n));
    }
    return 0;
}

