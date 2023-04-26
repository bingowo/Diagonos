#include <stdio.h>
#include <stdlib.h>

struct zichuan
{
    char s1[100000];
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
    char *s;
    s=(char *)calloc(100000,sizeof(char));
    scanf("%s",s);
    int i,j,k=0,k1;
    struct zichuan *s2;
    s2=(struct zichuan*)calloc(100000,sizeof(struct zichuan));
    for(i=0;s[i];i++)
    {
        char c[128]={0};
        s2[k].location=i;
        s2[k].lenth=0;
        for(j=i,k1=0;s[j];j++,k1++)
        {
            if(c[s[j]]==0)
            {
                c[s[j]]='1';
                s2[k].s1[k1]=s[j];
                s2[k].lenth=s2[k].lenth+1;
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