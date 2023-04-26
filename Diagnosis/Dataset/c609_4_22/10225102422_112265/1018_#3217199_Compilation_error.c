#include<stdio.h>
#include<stdlib.h>
#define N 10e5
int cmp(const void *e1,const void* e2)
{
    int p1=*(int*)e1;
    int p2=*(int*)e2;
    return p1-p2;
}
int main()
{
    int arr[N]={0};
    int n;
    int num;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        arr[i]=num;
    }
    qsort(arr,n,sizeof(int),cmp);
    int sum=0;
    for(i=0;i<n-2;i+=2)
    {
        sum=sum+arr[i+1]-arr[i];
    }
    printf("%d\n",sum);
    return 0;
}