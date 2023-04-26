#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p3,const void* p4)
{
    int* p1=(int* )p3;
    int* p2=(int* )p4;
    if((*(p1))>(*(p2))) return 1;
    else return -1;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n=0;
        scanf("%d",&n);
        int* p1=(int* )malloc(n*sizeof(int));
        int* p2=(int* )malloc(n*sizeof(int));
        for(int i=0;i<n;i++) scanf("%d",p1+i);
        for(int j=0;j<n;j++) scanf("%d",p2+j);
        qsort(p1,n,sizeof(int),cmp);
        qsort(p2,n,sizeof(int),cmp);
        int x=0;
        for(int ii=0;ii<n;ii++) x+=(*(p1+ii))*(*(p2+n-ii-1));
        printf("case #%d:\n%d\n",t,x);
        free(p1);
        free(p2);
    }
    return 0;
}
