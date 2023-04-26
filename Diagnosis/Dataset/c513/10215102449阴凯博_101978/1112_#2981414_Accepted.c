#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f3(int n)
{
    int i=n/3,cnt=0;
    for (int j=1;j<=i;j++)
        cnt+=((n-3*j)/2+1);
    return cnt;
}

int main()
{
    int T;
    scanf("%d",&T);
    int arr[1001];
    arr[0]=1; arr[1]=1; arr[2]=2; arr[3]=3;arr[4]=5;
    for (int i=4;i<=1000;i++)
    {
        arr[i]=arr[i-4]+f3(i)+i/2+1;

    }
    for (int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",arr[n]);


    }
    return 0;
}
