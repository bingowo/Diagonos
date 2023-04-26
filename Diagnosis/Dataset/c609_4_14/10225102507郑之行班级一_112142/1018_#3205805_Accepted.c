#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    if(*(int*)a>*(int*)b)return 1;
    else if(*(int*)a<*(int*)b)return -1;
    return 0;
}
int main()
{
    int l=0,n;
    scanf("%d",&n);
    int num[n];
    for (int i=0;i<n;i++)scanf("%d",&num[i]);
    qsort(num,n,sizeof(num[1]),cmp);
    for (int i=0;i<n;i+=2)l+=(num[i+1]-num[i]);
    printf("%d\n",l);
    return 0;
}
