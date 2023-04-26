#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int cmp(const void * a,const void* b)
{
    long long m=*((long long *)a);
    long long n=*((long long *)b);
    long long p=m,q=n;
    while(p>9 || p<-9)
        p=p/10;
    while(q>9 || q<-9)
        q=q/10;
    if(q<0) q=-q;
    if(p<0) p=-p;
    if(p==q)
    {
        if(m<n) return -1;
        else return 1;
    }
    else
    {
        if(p>q) return -1;
        else return 1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int N;
        scanf("%d",&N);
        long long a[N];
        for(int j=0;j<N;j++)
        {
            scanf("%lld",&a[j]);
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("%lld",a[0]);
        for(int k=1;k<N;k++)
        {
            printf(" %lld",a[k]);
        }
        printf("\n");
    }
}
