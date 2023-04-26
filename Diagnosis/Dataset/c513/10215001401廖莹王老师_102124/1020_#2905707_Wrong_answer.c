#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct
{
    char sj[12];
    char fz[10];
    int size;
    char name[64];
}wenjian;
int cmpname(const void*a,const void*b)
{
    wenjian* p1,*p2;
    p1=(wenjian*)a;
    p2=(wenjian*)b;
    return strcmp(p1->name,p2->name);
}
int cmpsize(const void*a,const void*b)
{
    wenjian*p1,*p2;
    p1=(wenjian*)a;
    p2=(wenjian*)b;
    if(p1->size!=p2->size)return p1->size-p2->size;
    else return strcmp(p1->name,p2->name);
}
int cmptime(const void*a,const void*b)
{
    wenjian*p1,*p2;
    p1=(wenjian*)a;
    p2=(wenjian*)b;
    if(strcmp(p1->sj,p2->sj)!=0)return strcmp(p1->sj,p2->sj);
    else
    {
        if(strcmp(p1->fz,p2->fz)!=0)return strcmp(p1->fz,p2->fz);
        else return strcmp(p1->name,p2->name);
    }
}
int main()
{
    int i=0;
    int n;
    while(1)
    {
    scanf("%d",&n);
    if(n!=0)
    {

        int i=0;
        char list[5];
        char re[7];
        wenjian p[110];
        for(i=0;i<n;i++)
        {scanf("%s",p[i].sj);
        scanf("%s",p[i].fz);
        scanf("%d",&p[i].size);
        scanf("%s",p[i].name);
        }
        scanf("%s",list);
        scanf("%s",re);
        if(strcmp(re,"/NAME")==0)
            qsort(p,n,sizeof(p[0]),cmpname);
        else if(strcmp(re,"/SIZE")==0)
             qsort(p,n,sizeof(p[0]),cmpsize);
        else if(strcmp(re,"/TIME")==0)
            qsort(p,n,sizeof(p[0]),cmptime);
        printf("\n");

        for(i=0;i<n;i++)
        {
            printf("%s %s %16d %s\n",p[i].sj,p[i].fz,p[i].size,p[i].name);
        }
        if(i>=1)printf("\n");
        i++;
    }
    else break;
    }

    return 0;
}
