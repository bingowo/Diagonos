#include <stdio.h>
#include <stdlib.h>

struct zichuan
{
    char s1[1000];
    int lenth;
    int location;
};

int cmp(const void*a,const void*b)
{
    struct zichuan*ap=(struct zichuan*)a;
    struct zichuan*bp=(struct zichuan*)b;
    if(ap->lenth!=bp->lenth)
        return (bp->lenth-ap->lenth);
    return (ap->location-bp->location);
}

int main()
{
    char s[10000];
    scanf("%s",s);
    int i,j,k=0;
    struct zichuan s2[1000];
    for(i=0;s[i];i++)
    {
        char c[128]={0};
        for(j=i;;j++)
        {
            s2[k].location=i;
            s2[k].lenth=0;
            if(c[s[j]]==0)
            {
                c[s[j]]='1';
                s2[k].s1[j]=s[j];
            }
            else
                break;
        }
        k++;
    }
    qsort(s2,k,sizeof(struct zichuan),cmp);
    for(i=0;s2[0].s1[i];i++)
        printf("%c",s2[0].s1[i]);
}