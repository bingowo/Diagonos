#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    int*ap=(int*)a;
    int*bp=(int*)b;
    return (*ap-*bp);
}

int main()
{
    int n,i;
    scanf("%d",&n);  //点的数量
    int a[1000];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    int m=0,j=0,k;
    for(k=2*j;k<n;j++)
    {
        k=2*j;
        m=m+a[k+1]-a[k];
    }
    printf("%d",m);
}
