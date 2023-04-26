#include <stdio.h>
#include <stdlib.h>

struct zifuchuan
{
    char a[21];
    int q[21];
};

int cmp(const void*a,const void*b)
{
    struct zifuchuan*ap=(struct zifuchuan*)a;
    struct zifuchuan*bp=(struct zifuchuan*)b;
    int i;
    for(i=0;;i++)
    {
        if(ap->q[i]!=bp->q[i]&&ap->q[i]!=0&&bp->q[i]!=0)
        return (bp->q[i]-ap->q[i]);
        if(ap->q[i]==0)
            return -1;
        if(bp->q[i]==0)
            return 1;
    }
}

int main()
{
    char s[27]={0};
    while(scanf("%s\n",s)!=EOF)
    {
        int i=26,j;
        int b1[128]={0};
        for(j=0;i>0;i--,j++)
            b1[s[j]]=i;
        struct zifuchuan c[101]={{0},{0}};
        j=0,i=0;
        int k;
        char d;
        for(k=0;;)
        {
            scanf("%c",&d);
            if(d==' ')
            {
                c[k].a[j]=0;
                k++;j=0;
            }
            else
            {
                if(d=='\n')
                {
                    c[k].a[j]=0;
                    k++;
                    break;
                }
                else
                    {
                        c[k].a[j]=d;
                        j++;
                    }
            }
        }
        char c1;
        for(i=0;i<k;i++)
        {
            for(j=0;c[i].a[j];j++)
            {
                c1=c[i].a[j];
                if(c1<91)
                    c[i].q[j]=b1[c1];
                else
                    c[i].q[j]=b1[c1-32];
            }
            c[i].q[j]=0;
            j=0;
        }
        qsort(c,k,sizeof(struct zifuchuan),cmp);
        i=0;j=0;
        for(i=0;c[i].a[j];i++)
        {
            for(j=0;c[i].a[j];j++)
                printf("%c",c[i].a[j]);
            printf(" ");
            j=0;
        }
        printf("\n");
    }
}