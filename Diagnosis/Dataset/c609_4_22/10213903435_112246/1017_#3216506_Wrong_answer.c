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
    arr[i]=0;
    if(c=='A')
        qsort(arr,i+1,sizeof(int),cmp1);
    else if(c=='D')
        qsort(arr,i+1,sizeof(int),cmp2);
    int *p=arr;
    if(*p==0)p++;
    printf("%d ",*p);
    while(*++p)
    {
        if(*p!=*(p-1))printf("%d ",*p);
        else continue;
    }
    return 0;
}