#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a,const void *b)
{
    long long int p1,p2;
    p1=*(long long int *)a;
    p2=*(long long int *)b;
    if(p1>p2)
        return -1;
    else
        return 1;
}
int cmp2(const void *a,const void *b)
{
    long long int p1,p2;
    p1=*(long long int *)a;
    p2=*(long long int *)b;
    if(p1>p2)
        return 1;
    else
        return -1;
}
int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    long long int *x,*all;
    x=(long long int *)malloc(n*sizeof(long long int));
    all=(long long int *)malloc((n-m+1)*sizeof(long long int));
    for(i=0;i<n;i++)
    {
        scanf("%lld",&x[i]);
    }
    qsort(x,n,sizeof(x[0]),cmp1);
    for(i=0;i<n-m+1;i++)
    {
        int j;
        all[i]=0;
        for(j=1;j<m;j++)
        {
            all[i]+=x[i]-x[i+j];
        }
    }
    qsort(all,n-m+1,sizeof(all[0]),cmp2);
    printf("%lld",all[0]);
    free(x);
    free(all);
    return 0;
}
