#include <stdio.h>
#include <stdlib.h>
int b[128];

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
                return (b[bp->a[i]]-b[ap->a[i]]);
            else
            {
                if(ap->a[i]>91&&bp->a[i]<91)
                    return (b[bp->a[i]]-b[ap->a[i]-35]);
                else
                {
                    if(ap->a[i]<91&&bp->a[i]>91)
                        return (b[bp->a[i]-35]-b[ap->a[i]]);
                    else
                        return (b[bp->a[i]-35]-b[ap->a[i]-35]);
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
            b[s[j]-'0']=i;
        struct zifuchuan c[101];
        j=0,i=0;
        char d;
        for(i=0;;)
        {
            scanf("%c",&d);
            if(d==' ')
            {
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
    }
}
