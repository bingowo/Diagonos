#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *a,const void *b)
{
    int m=*(int*)a,n=*(int *)b;
    return a-b;
}
int cmp2(const void *a,const void *b)
{
    int m=*(int*)a,n=*(int *)b;
    return b-a;
}
int main()
{
    char c;
    scanf("%c",&c);
    int arr[1000];
    int i=0;
    while(scanf("%d",&arr[i++])!=EOF);
    if(c=='A')
        qsort(arr,i-1,sizeof(int),cmp1);
    else if(c=='D')
        qsort(arr,i-1,sizeof(int),cmp2);
    int *p=arr;
    printf("%d ",*p);
    while(*p++)
    {
        if(*p!=*(p-1))printf("%d ",*p);
        else continue;
    }
    return 0;
}