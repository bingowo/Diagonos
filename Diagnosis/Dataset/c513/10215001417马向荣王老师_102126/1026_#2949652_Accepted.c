#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return (*(int *)a-*(int *)b);
}
int main()
{
    int n=0,i=0;
    scanf("%d\n",&n);
    int arr[100001];
    for(i=0;i<n;i++)
    {
        scanf("%d ",&arr[i]);
    }
    qsort(arr,n,sizeof(arr[0]),cmp);
    int sum=0;
    for(int i=0;i<n;i+=2)
    {
        sum+=arr[i+1]-arr[i];
    }
    printf("%d\n",sum);
    return 0;
}
