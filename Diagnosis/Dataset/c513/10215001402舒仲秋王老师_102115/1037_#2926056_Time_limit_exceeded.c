#include <stdio.h>
#include <stdlib.h>


int cmp(const void* a,const void* b)
{
    long int d1,d2;
    int t;
    d1=*((long int*)a),d2=*((long int*)b);
    if(d1>d2) t=-1;
    else t=1;
    return t;
}

int main()
{
    int n,m;
    long int *mid,*num;
    scanf("%d %d",&n,&m);
    int i,j;
    num=malloc(n*sizeof(long int));
    mid=malloc(n*sizeof(long int));
    for(i=0;i<n;i++)
        scanf("%ld",&num[i]);
    qsort(num,n,sizeof(num[0]),cmp);
    for(i=0;i<=n-m;i++)
    {
        mid[i]=0;
        for(j=i;j<i+m;j++)
            mid[i]+=num[i]-num[j];
    }
    qsort(mid,n-m+1,sizeof(mid[0]),cmp);
    printf("%ld",mid[n-m]);
    free(num),free(mid);
    return 0;
}
