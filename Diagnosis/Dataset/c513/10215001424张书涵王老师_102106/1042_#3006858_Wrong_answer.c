#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct zifu
{
    char s2[16];
};

int cmp(const void*a,const void*b)
{
    char* p1;
    char* p2;
    p1=(char*)a;
    p2=(char*)b;
    if(*p1<91&&*p2<91)
        return (*p1-*p2);
    if(*p1>91&&*p2>91)
        return (*p1-*p2);
    if(*p1>91&&*p2<91)
        return 1;
    return -1;
}

int cmp2(const void*a,const void*b)
{
    struct zifu* ap=(struct zifu*)a;
    struct zifu* bp=(struct zifu*)b;
    if(strcmp(ap->s2,bp->s2)>0)
        return 1;
    return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        char s[17]={0};
        scanf("%s",s);
        int a[127]={0};
        int j,p=0,l,l1;
        char s1[17]={0};
        for(j=0;s[j];j++)
        {
            if(a[s[j]]==0)
            {
                a[s[j]]=1;
                s1[p++]=s[j];
            }
        }
        qsort(s1,p,sizeof(char),cmp);
        printf("case #%d:\n",i);
        struct zifu s3[1000]={0};;
        int m=0,n;
        for(j=0;s1[j];j++)
        {
            n=0;
            s3[m].s2[n]=s1[j];
            m++;n++;
            for(l1=1;s1[j+l1];l1++)
            {
                n=0;
                for(l=0;s1[j+l1+l];l++)
                {
                    s3[m].s2[n]=s1[j];
                    n++;
                    for(p=(j+l1);(p-j-l1)<=l;p++)
                    {
                        s3[m].s2[n]=s1[p];
                        n++;
                    }
                    m++;
                    n=0;
                }
            }
        }
        qsort(s3,m,sizeof(struct zifu),cmp2);
        for(j=0;j<m;j++)
            printf("%s\n",s3[j].s2);
    }
}
