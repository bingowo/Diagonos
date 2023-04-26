#include <stdio.h>
#include <stdlib.h>

struct zifu
{
    char s;
    double frequency;
};

int cmp(const void*a,const void*b)
{
    struct zifu*ap=(struct zifu*)a;
    struct zifu*bp=(struct zifu*)b;
    if(ap->frequency!=bp->frequency)
    {
        if(ap->frequency>bp->frequency)
            return -1;
        else
            return 1;
    }
    else
        return (bp->s-ap->s);
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        struct zifu a[150];
        double b[26]={0};
        int j,k=0;
        char c='0';
        for(j=0;j<26;j++)
            scanf("%lf ",&b[j]);//字母的使用频率
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
        qsort(a,k,sizeof(struct zifu),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<k;j++)
            printf("%c",a[j].s);
    }
}