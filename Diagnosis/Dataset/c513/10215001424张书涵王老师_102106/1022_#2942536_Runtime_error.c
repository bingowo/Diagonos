#include <stdio.h>
#include <stdlib.h>

struct mail
{
    char s1[1000];
    char zhuji[100];
    char yonghu[100];
};

int cmp(const void*a,const void*b)
{
    struct mail *ap=(struct mail*)a;
    struct mail *bp=(struct mail*)b;
    int i;
    for(i=0;ap->zhuji[i]&&bp->zhuji[i];i++)
    {
        if(ap->zhuji[i]>bp->zhuji[i])
            return 1;
        if(ap->zhuji[i]<bp->zhuji[i])
            return -1;
    }
    for(i=0;ap->yonghu[i]&&bp->yonghu[i];i++)
    {
        if(ap->yonghu[i]>bp->yonghu[i])
            return -1;
        if(ap->yonghu[i]<bp->yonghu[i])
            return 1;
    }
}

int main()
{
    int n;
    scanf("%d ",&n);
    int i;
    for(i=0;i<n;i++)
    {
        struct mail c[101]={{0},{0},{0}};
        int j=0;
        while(scanf("%s\n",c[j++].s1)!=EOF);
        int p=0,q=0;
        for(j=0;j<n;j++)
        {
            for(p=0;c[j].s1[p]!='@';p++)
                c[j].yonghu[p]=c[j].s1[p];
            c[j].yonghu[p]=0;
            for(q=0;c[j].s1[p];p++,q++)
                c[j].zhuji[q]=c[j].s1[p];
            c[j].zhuji[q]=0;
        }
        qsort(c,n,sizeof(struct mail),cmp);
        for(j=0;j<n;j++)
        {
            for(p=0;c[j].s1[p];p++)
                printf("%c",c[j].s1[p]);
            printf("\n");
        }
    }
}