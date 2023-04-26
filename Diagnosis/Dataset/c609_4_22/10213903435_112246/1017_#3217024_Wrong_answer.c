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
}       //cmp函数
int main()
{
    char c;
    scanf("%c",&c);
    int arr[100];
    int i=0;
    while(scanf("%d",&arr[i++])!=EOF);
    if(c=='A')
        qsort(arr,i,sizeof(int),cmp1);
    else if(c=='D')
        qsort(arr,i,sizeof(int),cmp2);
    int *p=arr;
    printf("%d ",*p);
    for(int j=1;j<i-1;j++)
    {
        if(*(p+j)!=*(p+j-1))printf("%d ",*(p+j));
    }
    return 0;
}