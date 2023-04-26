#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cmp(const void *a1,const void *b1);
    long long sum(long long int* a,int m);
    int n,m;
    int i,j;
    long long int ans=0;
    long long int min=10000000;
    scanf("%d %d",&n,&m);
    long long int *a=(long long int*)malloc(sizeof(long long)*n);
    for(i=0;i<n;i++)
        scanf("%lld",a+i);


    qsort(a,n,sizeof(a[0]),cmp);


    for(i=0;i<=n-m;i++)
    {
        int g=0;
        long long int *cp=(long long int*)malloc(sizeof(long long)*m);
        int count=0;
        for(j=i;count<m;)
        {
            cp[g]=a[j];
            g++;
            count++;
            j++;
        }
        if(sum(cp,m)<=min) min=sum(cp,m);
        free(cp);
    }
    printf("%lld",min);
    return 0;
}


int cmp(const void *a1,const void *b1)
{
    long long int a=*(long long int *)a1;
    long long int b=*(long long int *)b1;
    return b-a;
}

long long sum(long long int* a,int m)
{
    long long ans=0;
    for(int i=0;i<m;i++)
        {
            ans=ans+(a[0]-a[i]);
        }
    return ans;
}
