#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int f(long long a)
{
    long long tmp=1;
    int i,cnt=0;
    for(i=0; i<64; i++)
    {
        if(a&tmp)
            cnt++;
        tmp<<=1;
    }
    return cnt;
}

long long cmp(const void *a, const void *b)
{
    int num_a, num_b;
    long long aa, bb;
    aa=*(long long *)a;
    bb=*(long long *)b;
    num_a=f(aa);
    num_b=f(bb);
    if(num_a!=num_b)
        return num_b-num_a;
    else
        return aa-bb;
}

int main()
{
    int T;
    scanf("%d",&T);
    int cas=0;
    for(cas=0; cas<T; cas++)
    {
        long long int a[10001];
        int i,cnt;
        scanf("%d",&cnt);
        for(i=0; i<cnt; i++)
            scanf("%lld",&a[i]);
        qsort(a,cnt,sizeof(a[0]),cmp);
        printf("case #%d:\n",cas);
        for(i=0; i<cnt-1; i++)
            printf("%lld ",a[i]);
        printf("%lld\n",a[cnt-1]);
    }
}
