#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct{
    char id[12];
    int a,c,m,e;
}stu;
int cmpa(const void *p1,const void *p2)
{
    stu a=*((stu*)p1);
    stu b=*((stu*)p2);
    return b.a-a.a;
}
int cmpc(const void *p1,const void *p2)
{
    stu a=*((stu*)p1);
    stu b=*((stu*)p2);
    return b.c-a.c;
}
int cmpm(const void *p1,const void *p2)
{
    stu a=*((stu*)p1);
    stu b=*((stu*)p2);
    return b.m-a.m;
}
int cmpe(const void *p1,const void *p2)
{
    stu a=*((stu*)p1);
    stu b=*((stu*)p2);
    return b.e-a.e;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int m=0;m<T;m++)
    {
        int n;
        scanf("%d",&n);
        stu *a;
        a=(stu*)malloc(sizeof(stu)*n);
        for(int i=0;i<n;i++)
        {
            scanf("%s%d%d%d",a[i].id,&a[i].c,&a[i].m,&a[i].e);
            a[i].a=(a[i].c+a[i].m+a[i].e+0.5)/3;
        }
        
        printf("case #%d:\nA:\N",m);
        qsort(a,n,sizeof(a[0]),cmpa);
        printf("%s\n",a[0].id);
        printf(“C:\n”);
        qsort(a,n,sizeof(a[0]),cmpc);
        printf("%s\n",a[0].id);
        printf("M:\n");
        qsort(a,n,sizeof(a[0]),cmpm);
        printf("%s\n",a[0].id);
        printf("E:\n");
        qsort(a,n,sizeof(a[0]),cmpe);
        printf("%s\n",a[0].id);
    }
    return 0;
}