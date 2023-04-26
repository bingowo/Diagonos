#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return (*(int *)a-*(int *)b);
}
int main()
{
    int n,s=0;
    scanf("%d\n",&n);
    int arr[100001];
    for(int i=0;i<n;i++)
    {
        scanf("%d ",&arr[i]);
    }
    qsort(arr,n,sizeof(arr[0]),cmp);
    for(int j=0;j<n;n+=2)
    {
        s+=arr[j+1]-arr[j];
    }
    printf("%d",s);
    return 0;
}
