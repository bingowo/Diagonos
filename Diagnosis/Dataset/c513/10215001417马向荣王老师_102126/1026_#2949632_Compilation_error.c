#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n=0,i=0;
    scanf("%d\n",&n);
    int arr[100001];
    for(i=0;i<n;i++)
    {
        scanf("%d ",&arr[i]);
    }
    sort(arr,arr+n);
    int sum=0;
    for(int i=0;i<n;i+=2)
    {
        sum+=arr[i+1]-arr[i];
    }
    printf("%d\n",sum);
    return 0;
}
