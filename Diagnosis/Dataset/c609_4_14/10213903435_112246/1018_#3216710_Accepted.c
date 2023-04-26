#include<stdio.h>
#include<stdlib.h>
#define N 1000000
int cmp(const void *a,const void *b)
{
    int m=*(int *)a,n=*(int *)b;
    return m-n;
}
int main()
{
    int n,i=0,sum=0;
    int arr[N];
    scanf("%d",&n);
    while(i<n)
    {
        scanf("%d",&arr[i]);
        i++;
    }
    qsort(arr,n,sizeof(int),cmp);
    for(int j=0;j<n;j+=2)
        sum+=(arr[j+1]-arr[j]);
    printf("%d",sum);
    return 0;
}