#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[15];
    int A;
    int C;
    int M;
    int E;
}ben;
int cmpA(const void *a,const void *b)
{
    ben* s1=(ben*)a,*s2=(ben*)b;
    if(s1->A<s2->A) return 1;
    else return -1;
}
int cmpC(const void *a,const void *b)
{
    ben* s1=(ben*)a,*s2=(ben*)b;
    if(s1->C<s2->C) return 1;
    else return -1;
}
int cmpM(const void *a,const void *b)
{
    ben* s1=(ben*)a,*s2=(ben*)b;
    if(s1->M<s2->M) return 1;
    else return -1;
}
int cmpE(const void *a,const void *b)
{
    ben* s1=(ben*)a,*s2=(ben*)b;
    if(s1->E<s2->E) return 1;
    else return -1;
}
int cmp(const void *a,const void *b)
{
    ben* s1=(ben*)a,*s2=(ben*)b;
    if(strcmp(s1->s,s2->s)>0) return 1;
    else return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int f=0;f<t;f++)
    {
        int n;
        scanf("%d",&n);
        ben* p=(ben*) malloc(n*sizeof(ben));
        for(int i=0;i<n;i++)
        {
            scanf("%s",p[i].s);
            scanf("%d%d%d",&p[i].C,&p[i].M,&p[i].E);
            double temp=(double)(p[i].C+p[i].M+p[i].E);
            p[i].A=(int)(temp/3+0.5);
        }
        printf("case #%d:\n",f);
        qsort(p,n,sizeof(p[0]),cmpA);
        int num=1;
        printf("A:\n");
        for(int i=0;i<n;i++)
        {
            if(i+1<n&&p[i+1].A==p[i].A) num++;
            else break;
        }
        if(num>1) qsort(p,num,sizeof(p[0]),cmp);
        for(int i=0;i<num;i++)
        {
            printf("%s\n",p[i].s);
        }
        qsort(p,n,sizeof(p[0]),cmpC);
        printf("C:\n");
        num=1;
        for(int i=0;i<n;i++)
        {
            if(i+1<n&&p[i+1].C==p[i].C) num++;
            else break;
        }
        if(num>1) qsort(p,num,sizeof(p[0]),cmp);
        for(int i=0;i<n;i++)
        {
            printf("%s\n",p[i].s);
            if(i+1<n&&p[i+1].C!=p[i].C) break;
        }
        qsort(p,n,sizeof(p[0]),cmpM);
        printf("M:\n");
        num=1;
        for(int i=0;i<n;i++)
        {
            if(i+1<n&&p[i+1].M==p[i].M) num++;
            else break;
        }
        if(num>1) qsort(p,num,sizeof(p[0]),cmp);
        for(int i=0;i<n;i++)
        {
            printf("%s\n",p[i].s);
            if(i+1<n&&p[i+1].M!=p[i].M) break;
        }
        qsort(p,n,sizeof(p[0]),cmpE);
        printf("E:\n");
        num=1;
        for(int i=0;i<n;i++)
        {
            if(i+1<n&&p[i+1].E==p[i].E) num++;
            else break;
        }
        if(num>1) qsort(p,num,sizeof(p[0]),cmp);
        for(int i=0;i<n;i++)
        {
            printf("%s\n",p[i].s);
            if(i+1<n&&p[i+1].E!=p[i].E) break;
        }
        free(p);
    }
    return 0;
}