#include<stdio.h>
#include<stdlib.h>
#define N 10001
int cmp(const void* e1,const void* e2)
{
    return (*(int*)e1)-(*(int*)e2);
}
int main()
{
    int T,sum,i;
    int s[N];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    scanf("%d",&s[i]);
    qsort(s,T,sizeof(int),cmp);
    for(i=0;i<T;i=i+2)
    sum=sum+s[i+1]-s[i];
}