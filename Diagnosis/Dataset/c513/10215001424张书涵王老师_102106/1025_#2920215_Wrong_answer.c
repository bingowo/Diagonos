#include <stdio.h>
#include <stdlib.h>

struct zifuchuan
{
    char s[1000];
    int number;
};

int cmp(const void* a,const void* b)
{
    int i;
    struct zifuchuan* ap=(struct zifuchuan*)a;
    struct zifuchuan* bp=(struct zifuchuan*)b;
    if(ap->number!=bp->number)
        return (bp->number-ap->number);
    else
    {
        for(i=0;(ap->s[i])&&(bp->s[i]);i++)
        {
            if(ap->s[i]!=bp->s[i])
                return (ap->s[i]-bp->s[i]);
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int n,j,k;
        scanf("%d",&n);
        struct zifuchuan c[10000];
        for(j=0;j<n;j++)
            scanf("%s",c[j].s);
        c[j].s[0]=0;
        for(j=0;j<n;j++)
            c[j].number=0;
        int d[128]={0};
        for(j=0;j<n;j++)
        {
            for(k=0;c[j].s[k];k++)
            {
                if(d[c[j].s[k]]==0)
                {
                    d[c[j].s[k]]=1;
                    c[j].number=c[j].number+1;
                }
            }
        }
        qsort(c,n,sizeof(struct zifuchuan),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)
        {
            for(k=0;c[j].s[k];k++)
                printf("%c",c[j].s[k]);
            printf("\n");
        }
    }
}
