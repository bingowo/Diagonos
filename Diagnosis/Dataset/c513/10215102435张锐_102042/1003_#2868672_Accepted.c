#include <stdio.h>
#include <stdlib.h>

long long int ones(long long unsigned a)
{
   return a==0?0:ones(a/2)+a%2;
}
int cmp(const void*a,const void*b)
{
    int t;
    long long int ia=*(long long int *)a,ib=*(long long int *)b;
    if(t=ones(ib)-ones(ia)) return t;
    if(ia>ib) return 1;
    if(ia<ib) return -1;
    return 0;
}
void Sort(long long int *p, int n)
{
    qsort(p,n,sizeof(*p),cmp);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        long long int s[10000];
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&s[j]);
        }
        Sort(s,n);
        for(int k=0;k<n;k++)
        {
            printf("%lld ",s[k]);
        }
        printf("\n");
    }
    return 0;
}