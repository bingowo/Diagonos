#include <stdio.h>
#include <stdlib.h>

struct shuzi
{
    long long int yuanzhi;
    int zuigaowei;
};

int cmp(const void*a,const void*b)
{
    struct shuzi *ap=(struct shuzi *)a;
    struct shuzi *bp=(struct shuzi *)b;
    if(ap->zuigaowei!=bp->zuigaowei)
        return (bp->zuigaowei-ap->zuigaowei);
    else
    {
        if(ap->yuanzhi>bp->yuanzhi)
            return 1;
        else
            return -1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        if(N==1)
        {
            long long int n;
            scanf("%lld",&n);
            printf("case #%d:\n%lld\n",i,n);
        }
        else
        {
            int j=0;
            struct shuzi a[10000];
            long long int b[10000]={0};//存储输入的数字的正数
            for(j=0;j<N;j++)
                scanf("%lld",&(a[j].yuanzhi));
            int k;
            long long int m;
            for(k=0;k<N;k++)
            {
                if(a[k].yuanzhi<0)
                    b[k]=(-1)*(a[k].yuanzhi);
                else
                    b[k]=a[k].yuanzhi;
            }
            for(k=0;k<N;k++)
            {
                m=b[k];
                while(m>0)
                {
                    if(m/10==0)
                    {
                        a[k].zuigaowei=m;break;
                    }
                    else
                        m=m/10;
                }
            }
            qsort(a,N,sizeof(struct shuzi),cmp);
            printf("case #%d:\n",i);
            for(k=0;k<j;k++)
                printf("%lld ",(a[k].yuanzhi));
            printf("\n");
        }
    }
}
