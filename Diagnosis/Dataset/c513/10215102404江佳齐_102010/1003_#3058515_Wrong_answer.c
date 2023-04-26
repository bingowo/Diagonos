#include <stdio.h>
#include <stdlib.h>
#define N 128
#define M 64
struct NUM
{
    long long int num;
    int cnt;
}p[10000];

int cmp(const void *a,const void *b)
{
    struct NUM d1,d2;
    d1=*((struct NUM *)a);
    d2=*((struct NUM *)b);
    if(d1.cnt!=d2.cnt) return d2.cnt-d1.cnt;
    else
    {
        if(d1.num>d2.num) return 1;
        else return -1;
    }
}

int main()
{
    int t,n,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%lld",&p[j].num);
            p[j].cnt=0;
            int tmp;
            if(p[j].num<0)
            {
                tmp=N+p[j].num;
                while(tmp)
                {
                    if(tmp%2==0) p[j].cnt++;
                    tmp=tmp/2;
                }
                p[j].cnt=M-p[j].cnt;
            }
            else
            {
                tmp=p[j].num;
                while(tmp)
                {
                    if(tmp%2==1) p[j].cnt++;
                    tmp=tmp/2;
                }
            }
        }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n-1;j++)
            printf("%lld ",p[j].num);
        printf("%lld\n",p[j].num);
    }
}
