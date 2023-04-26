#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    int*ap=(int*)a;
    int*bp=(int*)b;
    if(*ap>*bp)
        return 1;
    else
        return -1;
}

int main()
{
    int n,i;
    scanf("%d",&n);  //点的数量
    int a[100000]={0};
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    long long int m=0;
    int j=0,k;
    for(k=2*j;(k=2*j)<n;j++)
    {
        m=m+a[k+1]-a[k];
    }
    printf("%lld",m);
}
