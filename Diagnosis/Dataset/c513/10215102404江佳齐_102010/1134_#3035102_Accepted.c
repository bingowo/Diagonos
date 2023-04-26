#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char s[15];
    int GC;
    int GM;
    int GE;
    int GA;
};

int cmp1(const void *a,const void *b)
{
    struct student d1,d2;
    d1=*((struct student *)a);
    d2=*((struct student *)b);
    if(d1.GA!=d2.GA) return d2.GA-d1.GA;
    else
    {
        if(strcmp(d1.s,d2.s)>0) return 1;
        else return -1;
    }
}

int cmp2(const void *a,const void *b)
{
    struct student d1,d2;
    d1=*((struct student *)a);
    d2=*((struct student *)b);
    if(d1.GC!=d2.GC) return d2.GC-d1.GC;
    else
    {
        if(strcmp(d1.s,d2.s)>0) return 1;
        else return -1;
    }
}

int cmp3(const void *a,const void *b)
{
    struct student d1,d2;
    d1=*((struct student *)a);
    d2=*((struct student *)b);
    if(d1.GM!=d2.GM) return d2.GM-d1.GM;
    else
    {
        if(strcmp(d1.s,d2.s)>0) return 1;
        else return -1;
    }
}

int cmp4(const void *a,const void *b)
{
    struct student d1,d2;
    d1=*((struct student *)a);
    d2=*((struct student *)b);
    if(d1.GE!=d2.GE) return d2.GE-d1.GE;
    else
    {
        if(strcmp(d1.s,d2.s)>0) return 1;
        else return -1;
    }
}
int main()
{
    int t,n;
    struct student p[100];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%s %d %d %d",p[j].s,&p[j].GC,&p[j].GM,&p[j].GE);
            int a=(p[j].GC+p[j].GM+p[j].GE)/3;
            if((p[j].GC+p[j].GM+p[j].GE)%3==2) p[j].GA=a+1;
            else p[j].GA=a;
        }
        qsort(p,n,sizeof(p[0]),cmp1);
        printf("case #%d:\nA:\n%s\n",i,p[0].s);
        for(int j=1;j<n;j++)
        {
            if(p[j].GA==p[j-1].GA)
                printf("%s\n",p[j].s);
            else break;
        }
        qsort(p,n,sizeof(p[0]),cmp2);
        printf("C:\n%s\n",p[0].s);
        for(int j=1;j<n;j++)
        {
            if(p[j].GC==p[j-1].GC)
                printf("%s\n",p[j].s);
            else break;
        }
        qsort(p,n,sizeof(p[0]),cmp3);
        printf("M:\n%s\n",p[0].s);
        for(int j=1;j<n;j++)
        {
            if(p[j].GM==p[j-1].GM)
                printf("%s\n",p[j].s);
            else break;
        }
        qsort(p,n,sizeof(p[0]),cmp4);
        printf("E:\n%s\n",p[0].s);
        for(int j=1;j<n;j++)
        {
            if(p[j].GE==p[j-1].GE)
                printf("%s\n",p[j].s);
            else break;
        }
    }
    return 0;
}
