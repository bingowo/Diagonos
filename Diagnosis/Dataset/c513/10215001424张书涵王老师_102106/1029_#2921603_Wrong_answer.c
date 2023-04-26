#include <stdio.h>
#include <stdlib.h>

struct zifuchuan
{
    char s[300];
};

int cmp(const void*a,const void*b)
{
    struct zifuchuan*ap=(struct zifuchuan*)a;
    struct zifuchuan*bp=(struct zifuchuan*)b;
    if((ap->s[0])<=64||(ap->s[0])>=91)
        return -1;
    if((bp->s[0])<=64||(bp->s[0])>=91)
        return -1;
    int i;
    for(i=0;(ap->s[i])&&(bp->s[i]);i++)
    {
        if(ap->s[i]!=bp->s[i])
            return (ap->s[i]-bp->s[i]);
    }
}

int main()
{
    int T;
    scanf("%d ",&T);
    int i;
    for(i=0;i<T;i++)
    {
        struct zifuchuan a[100];
        char b[1000];
        int k,j=0,p;
        gets(b);
        for(k=0;b[j]!='\n'&&b[j]!='\0';k++)
        {
            for(p=0;b[j]!=' '&&b[j]!='\n'&&b[j]!='\0';j++,p++)
                a[k].s[p]=b[j];
                if(b[j]==' ')
                    j++;
        }
        qsort(a,k,sizeof(struct zifuchuan),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<k;j++)
        {
            for(p=0;a[j].s[p];p++)
                printf("%c",a[j].s[p]);
            printf(" ");
        }
        printf("\n");
    }
}
