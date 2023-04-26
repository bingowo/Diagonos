#include <stdio.h>
#include <stdlib.h>


int cmp(const void* a,const void* b)
{
    long int d1,d2;
    int t;
    d1=*((long int*)a),d2=*((long int*)b);
    if(d1>d2) t=1;
    else t=-1;
    return t;
}

int main()
{
    long int num[1000001];long int mid[1000001];
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j;
    for(i=0;i<n;i++)
        scanf("%ld",&num[i]);
    qsort(num,n,sizeof(num[0]),cmp);
    for(i=0;i<n-m;i++)
        mid[i]=num[i+m]-num[i]-num[i+m]+num[i+m-1];
    mid[i]=0;
    for(j=n-1;j>=i+1;j--)
        mid[i]+=num[j]-num[j-1];
    qsort(mid,n-m+1,sizeof(mid[0]),cmp);
    printf("%ld",mid[0]);
    return 0;
}
