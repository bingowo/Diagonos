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
    int l=strlen(a.id);
    if(b.a==a.a){
        for(int i=0;i<l;i++)
        if(a.id[i]!=b.id[i])return a.id[i]-b.id[i];
        
    }
    return b.a-a.a;
}
int cmpc(const void *p1,const void *p2)
{
    stu a=*((stu*)p1);
    stu b=*((stu*)p2);
    int l=strlen(a.id);
    if(b.c==a.c){
        for(int i=0;i<l;i++)
        if(a.id[i]!=b.id[i])return a.id[i]-b.id[i];
        
    }
    return b.c-a.c;
}
int cmpm(const void *p1,const void *p2)
{
    stu a=*((stu*)p1);
    stu b=*((stu*)p2);
    if(b.m==a.m){
        for(int i=0;i<l;i++)
        if(a.id[i]!=b.id[i])return a.id[i]-b.id[i];
        
    }
    return b.m-a.m;
}
int cmpe(const void *p1,const void *p2)
{
    stu a=*((stu*)p1);
    stu b=*((stu*)p2);
    if(b.e==a.e){
        for(int i=0;i<l;i++)
        if(a.id[i]!=b.id[i])return a.id[i]-b.id[i];
        
    }
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
        for(int j=1;j<n;j++)
        {
            if(a[j].c==a[0].c)printf("%s\n",a[j].id);
            else break;
        }
        printf("%s\n",a[0].id);
        printf("M:\n");
        qsort(a,n,sizeof(a[0]),cmpm);
        for(int j=1;j<n;j++)
        {
            if(a[j].m==a[0].m)printf("%s\n",a[j].id);
            else break;
        }
        printf("%s\n",a[0].id);
        printf("E:\n");
        qsort(a,n,sizeof(a[0]),cmpe);
        for(int j=1;j<n;j++)
        {
            if(a[j].e==a[0].e)printf("%s\n",a[j].id);
            else break;
        }
        printf("%s\n",a[0].id);
    }
    return 0;
}