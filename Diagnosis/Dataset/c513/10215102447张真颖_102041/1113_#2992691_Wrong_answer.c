#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k=0,n=0;
    scanf("%d%d",&k,&n);
    int arr[100]={0};
    arr[1]=1;
    for(int i=2;i<n;i++)
    {
        for(int t=1;t<=k;t++)
        {
            if(i-t>=0) arr[i]+=arr[i-t];
        }
    }
    printf("%d",arr[n-1]);
    return 0;
}
