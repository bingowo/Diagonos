#include <stdio.h>
#include <stdlib.h>

int count(long long u)
{
    int d=1,number=0;
    for(int t=0;t<64;t++)
    {
        if(u&d) number++;
        d=d<<1;
    }
    return number;
}
int cmp(const void* a,const void* b)
{
    long long ua=*(long long*)a;
    long long ub=*(long long*)b;
    int a1=count(ua);
    int b1=count(ub);
    if(a1==b1) return ua<ub?-1:1;
    else return a1<b1?1:-1;
}
void Sort(long long *p,long long n)
{
    qsort(p,n,sizeof(long long),cmp);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0;j<T;j++)
    {
        int N,i;
        long long a[1000];
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%lld",a+i);
            Sort(a,N);
        }
        printf("case #%d:\n",j);
        for(i=0;i<N;i++)
        {
            printf("%lld ",a[i]);
        }
        printf("\n");
    }
    return 0;
}