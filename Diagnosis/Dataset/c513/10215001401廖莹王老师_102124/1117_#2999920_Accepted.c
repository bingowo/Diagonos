#include <stdio.h>
#include <stdlib.h>
#define N 1000000
long long abss(long long t)
{   long long l=t;
    if(t>0)return l;
    else return -l;
}
long long maxx(long long m,long long n)
{
    if(m>n)return m;
    else return n;
}
long long x=0,y=0;
int cmp(const void*a,const void*b)
{
    long long *k1,*k2;
    k1=(long long *)a;k2=(long long *)b;
    long long m1=0,m2=0,m3=0,l1=0,l2=0,l3=0;
    m1=abss(*k1-x);m2=abss(*(k1+1)-y);m3=maxx(m1,m2);
    l1=abss(*k2-x);l2=abss(*(k2+1)-y);l3=maxx(l1,l2);
    if(m3!=l3){if(m3>l3)return 1;else return -1; }
    else
    {
        if(*k1!=*k2){if(*k1>*k2)return 1;else return -1;}
        else {if(*(k1+1)>*(k2+1))return 1;else return -1;}
    }
}
int main()
{
    long long n=0,i=0,p=0,q=0;
    long long a[N][2];memset(a,0,sizeof a);
    scanf("%lld %lld",&x,&y);
    scanf("%lld",&n);
    for(i=0;i<n;i++)scanf("%lld %lld",&a[i][0],&a[i][1]);
    qsort(a,n,sizeof(a[0]),cmp);
    p=abss(a[0][0]-x);q=abss(a[0][1]-y);p=maxx(p,q);
    printf("%lld\n",p);
    printf("%lld %lld\n",a[0][0],a[0][1]);
    return 0;
}
