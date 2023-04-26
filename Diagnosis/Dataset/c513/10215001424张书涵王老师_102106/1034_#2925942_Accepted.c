#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct zifu
{
    char s;
    float frequency;
};

int cmp(const void*a,const void*b)
{
    struct zifu*ap=(struct zifu*)a;
    struct zifu*bp=(struct zifu*)b;
    if(fabs(ap->frequency-bp->frequency)<pow(10,-3))
    {
        if((ap->s<=90&&bp->s<=90)||(ap->s>90&&bp->s>90))
            return (ap->s-bp->s);
        else
        {
            if((ap->s-32)==bp->s)
                return -1;
            else
            {
                if((bp->s-32)==ap->s)
                    return 1;
                else
                {
                    if(ap->s>90)
                        return (ap->s-32-bp->s);
                    else
                        return (ap->s-bp->s-32);
                }
            }
        }
    }
    else
    {
        if(ap->frequency>bp->frequency)
            return -1;
        else
            return 1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        struct zifu a[150];
        float b[26]={0};
        int j,k=0;
        char c='0';
        for(j=0;j<26;j++)
            scanf("%f ",&b[j]);//字母的使用频率
        while(c!='\n')
        {
            scanf("%c",&c);
            a[k++].s=c;
        }
        for(j=0;a[j].s;j++)
        {
            if(a[j].s<=90)
                a[j].frequency=b[a[j].s-65];
            else
                a[j].frequency=b[a[j].s-97];
        }
        qsort(a,k-1,sizeof(struct zifu),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<(k-1);j++)
            printf("%c",a[j].s);
        printf("\n");
    }
}