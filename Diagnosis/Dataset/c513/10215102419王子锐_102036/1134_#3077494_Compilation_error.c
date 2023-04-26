#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    char sno[12];
    int c,m,e;
    int avg;
};

int cmpavg(const void *a,const void *b)
{
    struct student *p=(struct student *)a,*q=(struct student *)b;
    if(q->avg==p->avg) return strcmp(p->sno,q->sno);
    else return q->avg-p->avg;
}
int cmpC(const void *a , const void *b)
{
    struct student *p=( struct student *)a,*q=(struct student *)b;
    if(q->c==p->c) return strcmp(p->sno,q->sno);
    else return q->c-p->c;
}
int cmpM(const void *a , const void *b)
{
    struct student *p=( struct student *)a,*q=(struct student *)b;
    if(q->m==p->m) return strcmp(p->sno,q->sno);
    else return q->m-p->m;
}
int cmpE(const void *a , const void *b)
{
    struct student *p=( struct student *)a,*q=(struct student *)b;
    if(q->e==p->e) return strcmp(p->sno,q->sno);
    else return q->e-p->e;
}
int main()
{
    int T;scanf(%d" ,&T);
    for(int i=e;i<T;i++){
        int n;scanf("%d" ,&n);
        struct student s[100]; 
        for(int j=0;j<n;j++)
        {
            scanf("%s%d%d%d",s[j].sno,&s[j].c,&s[j].m,&s[j].e);
            s[j].avg=(int)((s[j].c+s[j].m+s[j].e)/3.0+0.5);
        }
        
        printf("case #%d:\n",i);
        
        int k=0;
        
        printf("A:\n");
        qsort(s,n,sizeof(s[0]),cmpavg);
        k=0;
        while(1)
        {
            printf("%s\n",s[k].sno);
            if(k+1<n&&s[k+1].avg==s[k].avg) k++;
            else break;
        }
        printf("C:\n");
        qsort(s,n,sizeof(s[0]),cmpC);
        k=0;
        while(1)
        {
            printf("%s\n",s[k].sno);
            if(k+1<n&&s[k+1].c==s[k].c) k++;
            else break;
        }
        printf("M:\n");
        qsort(s,n,sizeof(s[0]),cmpM);
        k=0;
        while(1)
        {
            printf("%s\n",s[k].sno);
            if(k+1<n&&s[k+1].m==s[k].m) k++;
            else break;
        }
        printf("E:\n");
        qsort(s,n,sizeof(s[0]),cmpE);
        while(1)
        {
            printf("%s\n",s[k].sno);
        k=0;);
            if(k+1<n&&s[k+1].e==s[k].e) k++;
            else break;
        }
}