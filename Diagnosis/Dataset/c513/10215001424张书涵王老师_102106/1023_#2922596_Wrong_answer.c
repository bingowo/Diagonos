#include <stdio.h>
#include <stdlib.h>

struct zichuan
{
    char s[40];
    int number;
};

int cmp(const void*a,const void* b)
{
    int i;
    struct zichuan*ap=(struct zichuan*)a;
    struct zichuan*bp=(struct zichuan*)b;
    if(ap->number!=0&&bp->number==0)
        return 1;
    if(ap->number==0&&bp->number!=0)
        return -1;
    if(ap->number!=0&&bp->number!=0)
    {
        if(ap->number!=bp->number)
            return (ap->number-bp->number);
        else
        {
            for(i=0;ap->s[i]||bp->s[i];i++)
            {
                if(ap->s[i]!=bp->s[i])
                    return (ap->s[i]-bp->s[i]);
            }
        }
    }
    if(ap->number==0&&bp->number==0)
    {
        for(i=0;ap->s[i]||bp->s[i];i++)
        {
            if(ap->s[i]!=bp->s[i])
                return (ap->s[i]-bp->s[i]);
        }
    }
    return 0;
}

int main()
{
    struct zichuan a[100];
    char c[1000];
    gets(c);
    int i=0,j=0,k,l;
    for(i=0;c[j];i++)//i是字符串的个数
    {
        for(k=0;c[j]!=' '&&c[j];j++,k++)
        {
            a[i].s[k]=c[j];
        }
        a[i].s[k]=0;
        if(c[j]==' ')
            j++;
    }
    for(j=0;j<i;j++)
    {
        l=0;
        a[j].number=0;
        for(k=0;a[j].s[k];k++)
        {
            if(a[j].s[k]<=57&&a[j].s[k]>=48)
            {
                a[j].number=10*a[j].number+a[j].s[k]-'0';
                l=l+1;
            }
        }
        if(l==0)
            a[j].number=-1;
    }
    qsort(a,i,sizeof(struct zichuan),cmp);
    for(j=0;j<i;j++)
    {
        for(k=0;a[j].s[k];k++)
            printf("%c",a[j].s[k]);
        printf(" ");
    }
}
