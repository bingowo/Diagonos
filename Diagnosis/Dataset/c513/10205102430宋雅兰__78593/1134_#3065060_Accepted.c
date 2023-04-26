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
    if(b.a==a.a)return strcmp(a.id,b.id);
    return b.a-a.a;
}
int cmpc(const void *p1,const void *p2)
{
    stu a=*((stu*)p1);
    stu b=*((stu*)p2);
    if(b.c==a.c)return strcmp(a.id,b.id);
    return b.c-a.c;
}
int cmpm(const void *p1,const void *p2)
{
    stu a=*((stu*)p1);
    stu b=*((stu*)p2);
    if(b.m==a.m)return strcmp(a.id,b.id);
    return b.m-a.m;
}
int cmpe(const void *p1,const void *p2)
{
    stu a=*((stu*)p1);
    stu b=*((stu*)p2);
    if(b.e==a.e)return strcmp(a.id,b.id);
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
            a[i].a=(int)((a[i].c+a[i].m+a[i].e)/(float)3+0.5);
        }
        
        printf("case #%d:\nA:\n",m);
        qsort(a,n,sizeof(a[0]),cmpa);
        printf("%s\n",a[0].id);
        for(int j=1;j<n;j++)
        {
            if(a[j].a==a[0].a)printf("%s\n",a[j].id);
            else break;
        }
        printf("C:\n");
        qsort(a,n,sizeof(a[0]),cmpc);
        printf("%s\n",a[0].id);
        for(int j=1;j<n;j++)
        {
            if(a[j].c==a[0].c)printf("%s\n",a[j].id);
            else break;
        }
        
        printf("M:\n");
        qsort(a,n,sizeof(a[0]),cmpm);
        printf("%s\n",a[0].id);
        for(int j=1;j<n;j++)
        {
            if(a[j].m==a[0].m)printf("%s\n",a[j].id);
            else break;
        }
        
        printf("E:\n");
        qsort(a,n,sizeof(a[0]),cmpe);
        printf("%s\n",a[0].id);
        for(int j=1;j<n;j++)
        {
            if(a[j].e==a[0].e)printf("%s\n",a[j].id);
            else break;
        }
        
    }
    return 0;
}