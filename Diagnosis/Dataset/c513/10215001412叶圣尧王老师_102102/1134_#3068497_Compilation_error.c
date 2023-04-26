#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct
{
    char s[12];
    int A,C,M,E;
}XS;

int cmpa(const void*a,const void*b)
{
    XS*c=(XS*)a;XS*d=(XS*)b;
    if(c->A!=d->A)return d->A-c->A;
    else return strcmp(c->s,d->s);
}

int cmpc(const void*a,const void*b)
{
    XS*c=(XS*)a;XS*d=(XS*)b;
    if(c->C!=d->C)return d->C-c->C;
    else return strcmp(c->s,d->s);
}

int cmpm(const void*a,const void*b)
{
    XS*c=(XS*)a;XS*d=(XS*)b;
    if(c->M!=d->M)return d->M-c->M;
    else return strcmp(c->s,d->s);
}

int cmpe(const void*a,const void*b)
{
    XS*c=(XS*)a;XS*d=(XS*)b;
    if(c->E!=d->E)return d->E-c->E;
    else return strcmp(c->s,d->s);
}

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n;scanf("%d",&n);
        XS stu[n];
        for(int i=0;i<n;i++)
        {
            scanf("%s %d %d %d",stu[i].s,&stu[i].C,&stu[i].M,&stu[i].E);
            stu[i].A=(stu[i].C+stu[i].M+stu[i].E+1)/3;
        }
        printf("case #%d:\n",t);
        qsort(stu,n,sizeof(stu[0]),cmpa);
        printf("A:\n%s\n",stu[0].s);
        qsort(stu,n,sizeof(stu[0]),cmpc);
        prinft("C:\n%s\n",stu[0].s);
        qsort(stu,n,sizeof(stu[0]),cmpm);
        prinft("M:\n%s\n",stu[0].s);
        qsort(stu,n,sizeof(stu[0]),cmpe);
        prinft("E:\n%s\n",stu[0].s);
    }
}