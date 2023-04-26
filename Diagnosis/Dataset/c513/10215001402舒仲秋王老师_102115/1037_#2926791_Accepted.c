#include <stdio.h>
#include <stdlib.h>
long int num[1000001];
long int mid[1000001];

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
    scanf("%d %d",&n,&m);
    long int i,p=0;
    for(i=0;i<n;i++)
        scanf("%ld",&num[i]);
    qsort(num,n,sizeof(num[0]),cmp);
    for(i=0;i<n-1;i++)
        mid[i]=num[i]-num[i+1];
    for(i=0;i<m-1;i++)
        p+=mid[i]*(m-i-1);
    long int sum=p;
    for(i=0;i<n-m;i++)
    {
        p-=mid[i]*(m-1);
        p+=(num[i+1]-num[i+m]);
        if(p<sum) sum=p;
    }
    printf("%ld",sum);
    return 0;
}
