#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char hao[15];
    int c;
    int m;
    int e;
    int a;
}stu;

int qiua(int u,int v,int w)
{
    int sum=u+v+w;
    int zheng=sum/3;
    int yu=sum%3;
    if(yu<2) return zheng;
    else return zheng+1;

}


int cmpa(const void*a,const void*b)
{
    stu aa=*((stu*)a);
    stu bb=*((stu*)b);
    int aaa=aa.a;
    int bbb=bb.a;
    if(aaa>bbb) return -1;
    else if(aaa<bbb) return 1;
    else return strcmp(aa.hao,bb.hao);
}

int cmpc(const void*a,const void*b)
{
    stu aa=*((stu*)a);
    stu bb=*((stu*)b);
    int aaa=aa.c;
    int bbb=bb.c;
    if(aaa>bbb) return -1;
    else if(aaa<bbb) return 1;
    else return strcmp(aa.hao,bb.hao);
}

int cmpm(const void*a,const void*b)
{
    stu aa=*((stu*)a);
    stu bb=*((stu*)b);
    int aaa=aa.m;
    int bbb=bb.m;
    if(aaa>bbb) return -1;
    else if(aaa<bbb) return 1;
    else return strcmp(aa.hao,bb.hao);
}

int cmpe(const void*a,const void*b)
{
    stu aa=*((stu*)a);
    stu bb=*((stu*)b);
    int aaa=aa.e;
    int bbb=bb.e;
    if(aaa>bbb) return -1;
    else if(aaa<bbb) return 1;
    else return strcmp(aa.hao,bb.hao);
}

int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        stu x[110];
        memset(x,-1,sizeof(stu)*110);
        int j;
        for(j=0;j<n;j++)
        {
            memset(x[j].hao,0,sizeof(char)*15);
        }
        for(j=0;j<n;j++)
        {
            scanf("%s",x[j].hao);
            scanf("%d%d%d",&x[j].c,&x[j].m,&x[j].e);
            x[j].a=qiua(x[j].c,x[j].m,x[j].e);
        }
        printf("case #%d:\n",i);
        qsort(x,n,sizeof(stu),cmpa);
        printf("A:\n");
        j=0;
        while(x[j].a==x[0].a)
        {
            printf("%s\n",x[j].hao);
            j++;
        }

        qsort(x,n,sizeof(stu),cmpc);
        printf("C:\n");
        j=0;
        while(x[j].c==x[0].c)
        {
            printf("%s\n",x[j].hao);
            j++;
        }

        qsort(x,n,sizeof(stu),cmpm);
        printf("M:\n");
        j=0;
        while(x[j].m==x[0].m)
        {
            printf("%s\n",x[j].hao);
            j++;
        }

        qsort(x,n,sizeof(stu),cmpe);
        printf("E:\n");
        j=0;
        while(x[j].e==x[0].e)
        {
            printf("%s\n",x[j].hao);
            j++;
        }
    }
}
