#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int k=0;
struct combination
{
    char c[17];
};

void pick(char *s1,int* b,struct combination*s2,int lenth,int num,int total)
{
    int i,j,p;
    for(i=num-1;i>=lenth-1;i--)
    {
        b[lenth-1]=s1[i];
        if(lenth>1)
            pick(s1,b,s2,lenth-1,i,total);
        else
        {
            for(j=total-1,p=0;j>=0;j--,p++)
                s2[k].c[p]=b[j];
            k++;
        }
    }
}


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
    struct combination* ap=(struct combination*)a;
    struct combination* bp=(struct combination*)b;
    int i;
    for(i=0;ap->c[i]||bp->c[i];i++)
    {
        if(ap->c[i]<91&&bp->c[i]>96)
            return -1;
        if(ap->c[i]>96&&bp->c[i]<91)
            return 1;
        if(ap->c[i]>bp->c[i]&&ap->c[i]&&bp->c[i])
            return 1;
        if(ap->c[i]&&bp->c[i]&&ap->c[i]<bp->c[i])
            return -1;
        if(ap->c[i]==0)
            return -1;
        if(bp->c[i]==0)
            return 1;
    }
    return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        k=0;
        struct combination s2[1000]={{0}};
        char s[17]={0};
        scanf("%s",s);
        int a[127]={0};
        int j,p=0,l,M;
        char s1[17]={0};
        int b[17]={0};
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
        for(l=1;l<=p;l++)
        {
            M=l;
            pick(s1,b,s2,l,p,M);//从s1取，存到s2，取l个
        }
        for(j=0;j<k;j++)
        {
            l=strlen(s2[j].c);
            qsort(s2[j].c,l,sizeof(char),cmp);
        }
        qsort(s2,k,sizeof(struct combination),cmp2);
        for(j=0;j<k;j++)
            printf("%s\n",s2[j].c);
    }
}