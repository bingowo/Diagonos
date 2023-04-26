#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define ll long long

int cmp(const void *q1, const void *q2)
{
    ll * p1 = (ll *)q1;
    ll * p2 = (ll *)q2;

    if(*p1 > *p2)
    {return 1;}
    else
    {return -1;}
}

int main()
{
    int total;
    scanf("%d",&total);
    ll *p;
    ll m=0;
    p=(ll *)malloc(sizeof(ll)*total);
    for(int i=0;i<total;i++)
    {
        scanf("%lld",&p[i]);
    }
    qsort(p,total,sizeof(ll),cmp);
    for(int i = 0; i < total / 2; i++)
    {
        m+= (p[2*i + 1] - p[2 * i]);
    }
    printf("%lld\n",m);
    free(p);
    return 0;
}