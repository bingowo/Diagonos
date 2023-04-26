#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long int ll;
typedef struct {int num;ll in}SSS;

int solve(ll x)
{
    int count = 0;
    while(x != 0) {
        x = x & (x-1);
        count++;
    }
    return count;
}

int cmp(const void*a,const void*b)
{
    SSS * pa=(SSS *)a;
    SSS * pb=(SSS *)b;
    if((pa->num)!=(pb->num)){return((pa->num)>(pb->num)?-1:1);}
    return ((pa->in)>(pb->in)?1:-1);
}
int main()
{
    int i,j,t=0,T;
    scanf("%d",&T);
    while(t++<T)
    {
        int NN=0,NM=0,N;
        scanf("%d",&N);
        SSS n[N];
        while(NN<N)
        {
            scanf("%lld",&n[NN].in);
            n[NN].num=solve(n[NN].in);
            NN++;
        }
        qsort(n,N,sizeof(SSS),cmp);
        printf("case #%d:\n",t-1);
        while(NM++<N)
        {
            printf("%lld ",n[NM-1].in);
        }
        printf("\n");
    }
}
