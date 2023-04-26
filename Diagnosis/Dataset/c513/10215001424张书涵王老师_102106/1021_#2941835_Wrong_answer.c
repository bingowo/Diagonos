#include <stdio.h>
#include <stdlib.h>

int b1[128]={0};

struct zifuchuan
{
    char a[21];
};

int cmp(const void*a,const void*b)
{
    struct zifuchuan*ap=(struct zifuchuan*)a;
    struct zifuchuan*bp=(struct zifuchuan*)b;
    int i;
    for(i=0;ap->a[i]&&bp->a[i];i++)
    {
        if(ap->a[i]!=bp->a[i])
        {
            if(ap->a[i]<91&&bp->a[i]<91)
                return (b1[bp->a[i]-'0']-b1[ap->a[i]-'0']);
            else
            {
                if(ap->a[i]>91&&bp->a[i]<91)
                    return (b1[bp->a[i]-'0']-b1[ap->a[i]-35-'0']);
                else
                {
                    if(ap->a[i]<91&&bp->a[i]>91)
                        return (b1[bp->a[i]-35-'0']-b1[ap->a[i]-'0']);
                    else
                        return (b1[bp->a[i]-35-'0']-b1[ap->a[i]-35-'0']);
                }
            }
        }
    }
}

int main()
{
    char s[27];
    while(scanf("%s\n",s)!=EOF)
    {
        int i=26,j;
        for(j=0;i>0;i--,j++)
            b1[s[j]-'0']=i;
        struct zifuchuan c[101];
        j=0,i=0;
        char d;
        for(i=0;;)
        {
            scanf("%c",&d);
            if(d==' ')
            {
                c[i].a[j]=0;
                i++;j=0;
            }
            else
            {
                if(d=='\n')
                    break;
                else
                    {
                        c[i].a[j]=d;
                        j++;
                    }
            }
        }
        qsort(c,i,sizeof(struct zifuchuan),cmp);
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
