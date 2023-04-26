#include <stdio.h>
#include <stdlib.h>

int cmpa(const void*a,const void*b)
{
    int aa=*(int*)a,bb=*(int*)b;
    return aa-bb;
}
int cmpb(const void*a,const void*b)
{
    int aa=*(int*)a,bb=*(int*)b;
    return bb-aa;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n=0,a[1000]={0},b[1000]={0};
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        qsort(a,n,sizeof(a[0]),cmpa);
        qsort(b,n,sizeof(b[0]),cmpb);
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=a[i]*b[i];
        printf("case #%d:\n%d\n",i,sum);
    }
    return 0;
}
