#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p3,const void* p4)
{
    int* p1=(int* )p3;
    int* p2=(int* )p4;
    if((*(p1))<(*(p2))) return -1;
    else return 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int* p=(int* )malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",p+i);
    qsort(p,n,sizeof(int),cmp);
    long long int x=0;
    for(int k=0;k<n;k+=2) x+=*(p+k+1)-*(p+k);
    printf("%lld",x);
    return 0;
}
