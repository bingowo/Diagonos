#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    long long k;
}P;
P p[75];
long long digui(int n)
{
    p[0].k=0;p[1].k=1;p[2].k=1;
    if(n>=3)
    {
        if(p[n-1].k==-1)p[n-1].k=digui(n-1);
        else if(p[n-2].k==-1)p[n-2].k=digui(n-2);
        else if(p[n-3].k==-1)p[n-3].k=digui(n-3);
        p[n].k=p[n-1].k+p[n-2].k+p[n-3].k;
    }
    return p[n].k;
}
void jisuan(int h)
{
    int n;
    scanf("%d",&n);
    printf("case #%d:\n",h);
    printf("%lld\n",digui(n));
}
int main()
{
    int h,N;
    scanf("%d",&N);
    for(h=0;h<75;h++)p[h].k=-1;
    for(h=0;h<N;h++)
        jisuan(h);
    return 0;
}
