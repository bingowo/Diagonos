#include<stdio.h>
#include<stdlib.h>

int cmp1 (const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int n;
    scanf("%d\n",&n);
    int i;
    int l[100001];
    for(i=0;i<n;i++)
        scanf("%d",&l[i]);
    qsort(l,n,sizeof(l[0]),cmp1);
    int res=0;
    for(int k=0;k<n;k++)
        res=res-l[k]+l[++k];
    printf("%d",res);
    return 0;
}