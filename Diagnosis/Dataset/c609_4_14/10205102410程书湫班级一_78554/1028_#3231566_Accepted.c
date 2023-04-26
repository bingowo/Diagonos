#include <stdio.h>
#include <stdlib.h>
struct linedata
{
    long long d[50];
    int cnt;
};
int cmp(const void *a,const void *b)
{
    struct linedata p=*((struct linedata *)a);
    struct linedata q=*((struct linedata *)b);
    for(int k=0;k<p.cnt&&k<q.cnt;k++)
    {
        if(p.d[k]>q.d[k]) return -1;
        else if(p.d[k]<q.d[k]) return 1;
    }
    if(p.cnt>q.cnt) return -1;
    else return 1;
}
int main()
{
    int T,N;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        scanf("%d",&N);
        struct linedata t[1000];
        int cnl=0;
        for(int i=0;i<N;i++)
        {
            int n=0;
            long long num;
            while(scanf("%lld",&num))
            {
                if(num==-1)
                {
                    break;
                }
                else
                {
                    t[i].d[n++]=num;
                    t[i].cnt=n;
                }
            }
        }
        qsort(t,N,sizeof(t[0]),cmp);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<t[i].cnt;j++)
            {
                if(j==(t[i].cnt-1)) printf("%lld\n",t[i].d[j]);
                else printf("%lld ",t[i].d[j]);
            }
        }
    }
    return 0;
}
