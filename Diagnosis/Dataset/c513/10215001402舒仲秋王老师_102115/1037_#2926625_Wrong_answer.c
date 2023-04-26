#include <stdio.h>
#include <stdlib.h>
long int num[1000001];
long int mid[1000001];

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

    int n,m;
    scanf("%d %d",&n,&m);
    int i,j,q;
    for(i=0;i<n;i++)
        scanf("%ld",&num[i]);
    qsort(num,n,sizeof(num[0]),cmp);
    for(i=n-2,j=0;i>=m-1;i--,j++)
        mid[j]=num[i]-num[i-m+1]-num[i+1]+num[i];
    mid[j]=0;
    for(i=n-1,q=0;q<m-1;i--,q++)
        mid[j]+=num[i]-num[i-1];
    qsort(mid,n-m+1,sizeof(mid[0]),cmp);
    printf("%ld",mid[0]);
    return 0;
}
