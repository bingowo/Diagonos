#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    long long r;
    long long f;
} NUM;

NUM mul(NUM a,NUM b)
{
    NUM n;
    n.f=a.r*b.f+b.r*a.f;
    n.r=a.r*b.r-a.f*b.f;
    return n;
}

NUM pwr(int a)
{
    NUM n,m;
    m.f=1; m.r=-1;
    n.f=0; n.r=1;
    int i;
    for (i=0;i<a;i++)
        n=mul(n,m);
    return n;
}




int main()
{
    int i,j;
    long long m;
    int arr[10000]={0};
    scanf("%llx",&m);
    for (i=0;m>>i;i++)
    {
        arr[i]=m>>i&1;
    }
    NUM n;
    n.r=0; n.f=0;
    for (j=0;j<i;j++)
    {
        if (arr[j]==1)
        {
            n.r+=pwr(j).r;
            n.f+=pwr(j).f;
        }
    }
    if (n.f==0) printf("%lld\n",n.r);
    else
    {
        if (n.r!=0)
        {
            printf("%lld",n.r);
            if (n.f>0) printf("+");
        }
        if (n.f==1) printf("i\n");
        else if (n.f==-1) printf("-i\n");
        else {printf("%lld",n.f);printf("i\n");}
    }
    return 0;
}
