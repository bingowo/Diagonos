#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char stu[20];
    int C;
    int M;
    int E;
    int A;
}GRA;
int eq(int a,int b,int c)
{
    double x=a+b+c;
    x/=3;
    int y=(a+b+c)/3;
    if(x-(double)y>=0.5) y++;
    return y;
}
int cmpA(const void *a,const void* b)
{
    GRA*p1=(GRA*)a;
    GRA*p2=(GRA*)b;
    if(p2->A>p1->A) return 1;
    else if(p2->A<p1->A) return -1;
    else
    {
        return strcmp(p1->stu,p2->stu);
    }

}
int cmpC(const void *a,const void* b)
{
    GRA*p1=(GRA*)a;
    GRA*p2=(GRA*)b;
    if(p2->C>p1->C) return 1;
    else if(p2->C<p1->C) return -1;
    else
    {
        return strcmp(p1->stu,p2->stu);
    }

}
int cmpM(const void *a,const void* b)
{
    GRA*p1=(GRA*)a;
    GRA*p2=(GRA*)b;
    if(p2->M>p1->M) return 1;
    else if(p2->M<p1->M) return -1;
    else
    {
        return strcmp(p1->stu,p2->stu);
    }

}
int cmpE(const void *a,const void* b)
{
    GRA*p1=(GRA*)a;
    GRA*p2=(GRA*)b;
    if(p2->E>p1->E) return 1;
    else if(p2->E<p1->E) return -1;
    else
    {
        return strcmp(p1->stu,p2->stu);
    }

}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        GRA*p=(GRA*)malloc(n*sizeof(GRA));
        for(int j=0;j<n;j++)
        {
            scanf("%s%d%d%d",p[j].stu,&p[j].C,&p[j].M,&p[j].E);
            p[j].A=eq(p[j].C,p[j].M,p[j].E);
        }
        printf("case #%d:\n",i);
        //A
        qsort(p,n,sizeof(p[0]),cmpA);
        int a=0;
        printf("A:\n%s\n",p[0].stu);a++;
        while(a>0&&a<n&&p[a].A==p[a-1].A) printf("%s\n",p[a].stu),a++;
        //C
        qsort(p,n,sizeof(p[0]),cmpC);
        int c=0;
        printf("C:\n%s\n",p[0].stu);
        c++;
        while(c>0&&c<n&&p[c].C==p[c-1].C) printf("%s\n",p[c].stu),c++;
        //M
        qsort(p,n,sizeof(p[0]),cmpM);
        int m=0;
        printf("M:\n%s\n",p[0].stu);m++;
        while(m>0&&m<n&&p[m].M==p[m-1].M) printf("%s\n",p[m].stu),m++;
        //E
        qsort(p,n,sizeof(p[0]),cmpE);
        int e=0;
        printf("E:\n%s\n",p[0].stu);e++;
        while(e>0&&e<n&&p[e].E==p[e-1].E) printf("%s\n",p[e].stu),e++;
    }
    return 0;
}