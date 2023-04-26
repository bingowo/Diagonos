#include <stdio.h>
#include <stdlib.h>
int cmpa(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int cmpd(const void *a,const void *b)
{
    return *(int*)b-*(int*)a;
}
int main()
{
    int t,n,i,j;
    int a[1000],b[1000];
    long long x;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%d",&a[j]);
        for(j=0;j<n;j++)
            scanf("%d",&b[j]);
        qsort(a,n,sizeof(a[0]),cmpa);
        qsort(b,n,sizeof(b[0]),cmpd);
        x=0;
        for(j=0;j<n;j++)
            x=x+a[j]*b[j];
        printf("case #%d:\n",i);
        printf("%lld\n",x);
    }
    return 0;
}
