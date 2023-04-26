#include <stdio.h>
#include <stdlib.h>

int count(long long u)
{
    int number=0;
    while(u!=0)
    {
        u=u&(u-1);
        number++;
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

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0;j<T;j++)
    {
        int N,i;
        long long a[10000];
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%lld",&a[i]);
        }
        qsort(a,N,sizeof(long long),cmp);
        printf("case #%d:\n",j);
        for(i=0;i<N;i++)
        {
            printf("%lld ",a[i]);
        }
        printf("\n");
    }
    return 0;
}