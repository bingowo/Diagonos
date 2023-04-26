#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct {char a[12];int A;int C;int M;int E;}student;
int cmpA(const void*c,const void*d)
{
    student p1=*(student*)c;
    student p2=*(student*)d;
    if(p1.A>p2.A) return -1;
    if(p1.A<p2.A) return 1;
    return strcmp(p1.a,p2.a);
}
int cmpC(const void*c,const void*d)
{
    student p1=*(student*)c;
    student p2=*(student*)d;
    if(p1.C>p2.C) return -1;
    if(p1.C<p2.C) return 1;
    return strcmp(p1.a,p2.a);
}
int cmpM(const void*c,const void*d)
{
    student p1=*(student*)c;
    student p2=*(student*)d;
    if(p1.M>p2.M) return -1;
    if(p1.M<p2.M) return 1;
    return strcmp(p1.a,p2.a);
}
int cmpE(const void*c,const void*d)
{
    student p1=*(student*)c;
    student p2=*(student*)d;
    if(p1.E>p2.E) return -1;
    if(p1.E<p2.E) return 1;
    return strcmp(p1.a,p2.a);
}
int main()
{
    int t;
    scanf("%d",&t);
    int i,n,k,j;
    for(i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&n);
        student b[100];
        double h;
        for(k=0;k<n;k++)
        {
           scanf("%s",b[k].a);
           scanf("%d%d%d",&b[k].C,&b[k].M,&b[k].E);
           h=(b[k].C+b[k].M+b[k].E)*1.0/3.0+0.5;
           b[k].A=(int)h;
        }
        qsort(b,n,sizeof(b[0]),cmpA);
        printf("A:\n");
        printf("%s\n",b[0].a);
        for(j=1;b[j].A==b[j-1].A&&j<n;j++)
        {
            printf("%s\n",b[j].a);
        }
        qsort(b,n,sizeof(b[0]),cmpC);
        printf("C:\n");
        printf("%s\n",b[0].a);
        for(j=1;b[j].C==b[j-1].C&&j<n;j++)
        {
            printf("%s\n",b[j].a);
        }
        qsort(b,n,sizeof(b[0]),cmpM);
        printf("M:\n");
        printf("%s\n",b[0].a);
        for(j=1;b[j].M==b[j-1].M&&j<n;j++)
        {
            printf("%s\n",b[j].a);
        }
        qsort(b,n,sizeof(b[0]),cmpE);
        printf("E:\n");
        printf("%s\n",b[0].a);
        for(j=1;b[j].E==b[j-1].E&&j<n;j++)
        {
            printf("%s\n",b[j].a);
        }


    }
}