#include<stdio.h>
#include<stdlib.h>
#define N 102
int cmp1(const void *e1,const void* e2)
{
    int p1=*(int*)e1;
    int p2=*(int*)e2;
    return p1-p2;
}
int cmp2(const void *e1,const void* e2)
{
    int p1=*(int*)e1;
    int p2=*(int*)e2;
    return p2-p1;
}
int main()
{
    char C;
    scanf("%c",&C);
    int arr[N];
    int n,i=0;
    while(scanf("%d",&n)==1)
    {
        arr[i]=n;
        i++;
    }
    if(C=='A')
        qsort(arr,i,sizeof(int),cmp1);
    else if(C=='D')
        qsort(arr,i,sizeof(int),cmp2);
    int j;
    for(j=0;j<i;j++)
    {
        if(j<i-1)
            printf("%d ",arr[j]);
        else if(j==i-1)
            printf("%d\n",arr[j]);
    }
    return 0;
}
