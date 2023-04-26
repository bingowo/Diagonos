#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef long long int lli;
typedef struct
{
    char number[12];
    int C,M,E;
}student;
 
int cmpa(const void* a,const void* b)
{
    student* p=(student*)a;
    student* q=(student*)b;
    int a1=(int)((p->C+p->E+p->M)/3.0+0.5);
    int a2=(int)((q->C+q->E+q->M)/3.0+0.5);
    if(a1!=a2) return a1>a2?-1:1;
    else return strcmp(p->number,q->number);
 
}
 
int cmpc(const void* a,const void* b)
{
    student* p=(student*)a;
    student* q=(student*)b;
    int a1=p->C;
    int a2=q->C;
    if(a1!=a2) return a1>a2?-1:1;
    else return strcmp(p->number,q->number);
}
 
int cmpm(const void* a,const void* b)
{
    student* p=(student*)a;
    student* q=(student*)b;
    int a1=p->M;
    int a2=q->M;
    if(a1!=a2) return a1>a2?-1:1;
    else return strcmp(p->number,q->number);
}
int cmpe(const void* a,const void* b)
{
    student* p=(student*)a;
    student* q=(student*)b;
    int a1=p->E;
    int a2=q->E;
    if(a1!=a2) return a1>a2?-1:1;
    else return strcmp(p->number,q->number);
}
 
 
 
 
void printa(student* p ,int a,int n)
{
 
    for(int i=0;i<n;i++)
    {
        int a1=((p+i)->C+(p+i)->M+(p+i)->E);
        a1=(int)(a1/3.0+0.5);
//        printf("a=%d",a1);
        if(a1==a) printf("%s\n",(p+i)->number);
        else break;
    }
}
 
void printc(student* p,int t,int n)
{
    for(int i=0;i<n;i++)
    {
        if((p+i)->C==t) printf("%s\n",(p+i)->number);
        else break;
    }
}
 
void printm(student* p,int t,int n)
{
    for(int i=0;i<n;i++)
    {
        if((p+i)->M==t) printf("%s\n",(p+i)->number);
        else break;
    }
}
 
void printe(student* p,int t,int n)
{
    for(int i=0;i<n;i++)
    {
        if((p+i)->E==t) printf("%s\n",(p+i)->number);
        else break;
    }
}
 
 
int main()
{
    int t;scanf("%d",&t);
 
    for(int k=0;k<t;k++)
    {
        int n;scanf("%d",&n);
        student p[n];
        for(int i=0;i<n;i++)
        {
            scanf("%s%d%d%d",&p[i].number,&p[i].C,&p[i].M,&p[i].E);
        }
        printf("case #%d:\n",k);
        //A
        printf("A:\n");
        qsort(p,n,sizeof(p[0]),cmpa);
        int a=(p[0].C+p[0].M+p[0].E)/3.0+0.5;
        printa(p,a,n);
        //C
        printf("C:\n");
        qsort(p,n,sizeof(p[0]),cmpc);
        printc(p,p[0].C,n);
 
        //M
        printf("M:\n");
        qsort(p,n,sizeof(p[0]),cmpm);
        printm(p,p[0].M,n);
 
        //E
        printf("E:\n");
        qsort(p,n,sizeof(p[0]),cmpe);
        printe(p,p[0].E,n);
 
    }
 
    return 0;
}