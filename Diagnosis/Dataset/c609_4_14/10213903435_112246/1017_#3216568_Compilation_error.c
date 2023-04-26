#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *a,const void *b)
{
    int m=*(int*)a,n=*(int *)b;
    return m-n;
}
int cmp2(const void *a,const void *b)
{
    int m=*(int*)a,n=*(int *)b;
    return n-m;
}
int main()
{
    char c;
    scanf("%c",&c);
    int arr[100];
    int i=0;
    while(scanf("%d",&arr[i++])!=EOF);
    if(c=='A')
        qsort(arr,i-1,sizeof(int),cmp1);
    else if(c=='D')
        qsort(arr,i-1,sizeof(int),cmp2);
    arr[i]=-1;
    int *p=arr;
    printf("%d ",*p);
    for(int j=0;j<i;j++)
    {
        if(*p!=*(p-1))printf("%d ",*p);
        p++；
    }
    return 0;
}