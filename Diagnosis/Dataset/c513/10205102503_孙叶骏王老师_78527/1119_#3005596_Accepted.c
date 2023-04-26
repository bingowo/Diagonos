#include<stdio.h>
#include<stdlib.h>
#define N 1000
typedef struct
    {
        long long k;
        int s;
    }KS;

long long d;

double Speed(KS a)
{
    double s;
    s=1.0*d*a.s/(d-a.k);
    return s;
}

int cmp(const void*a,const void*b)
{
    KS A=*(KS*)a;
    KS B=*(KS*)b;
    if(Speed(A)>Speed(B))return 1;
    else return 0;
}

int main()
{
    int n;
    scanf("%lld\n%d\n",&d,&n);
    KS ks[N];
    for(int i=0;i<n;i++)
    {
        scanf("%lld %d\n",&ks[i].k,&ks[i].s);
    }
    qsort(ks,n,sizeof(ks[0]),cmp);
    printf("%.6f",1.0*d*ks[0].s/(d-ks[0].k));
}