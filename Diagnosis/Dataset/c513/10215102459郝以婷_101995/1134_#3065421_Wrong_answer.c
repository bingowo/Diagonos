#include <stdio.h>
#include <stdlib.h>

struct stu
{
    char s[12];
    int a,c,m,e;
};

int cmpa(const void *pa,const void *pb)
{
    struct stu *a=(struct stu*)pa;
    struct stu *b=(struct stu*)pb;
    if(a->a==b->a)
        return strcmp(a->s,b->s);
    else
        return b->a-a->a;
}

int cmpc(const void *pa,const void *pb)
{
    struct stu *a=(struct stu*)pa;
    struct stu *b=(struct stu*)pb;
    if(a->c==b->c)
        return strcmp(a->s,b->s);
    else
        return b->c-a->c;
}

int cmpm(const void *pa,const void *pb)
{
    struct stu *a=(struct stu*)pa;
    struct stu *b=(struct stu*)pb;
    if(a->m==b->m)
        return strcmp(a->s,b->s);
    else
        return b->m-a->m;
}

int cmpe(const void *pa,const void *pb)
{
    struct stu *a=(struct stu*)pa;
    struct stu *b=(struct stu*)pb;
    if(a->e==b->e)
        return strcmp(a->s,b->s);
    else
        return b->e-a->e;
}

int main()
{
    int T,i,n,j,k;
    struct stu stu0[1000];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        k=0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%s",stu0[k].s);
            scanf("%d",&stu0[k].c);
            scanf("%d",&stu0[k].m);
            scanf("%d",&stu0[k].e);
            stu0[k].a=(stu0[k].c+stu0[k].m+stu0[k].e)/3;
            k++;
        }
        printf("case #%d:\n",i);
        printf("A:\n");
        qsort(stu0,n,sizeof(struct stu),cmpa);
        printf("%s\n",stu0[0].s);
        for(j=1;j<n;j++)
        {
            if(stu0[j].a==stu0[0].a)
                printf("%s\n",stu0[j].s);
        }
        printf("C:\n");
        qsort(stu0,n,sizeof(struct stu),cmpc);
        printf("%s\n",stu0[0].s);
        for(j=1;j<n;j++)
        {
            if(stu0[j].c==stu0[0].c)
                printf("%s\n",stu0[j].s);
        }
        printf("M:\n");
        qsort(stu0,n,sizeof(struct stu),cmpm);
        printf("%s\n",stu0[0].s);
        for(j=1;j<n;j++)
        {
            if(stu0[j].m==stu0[0].m)
                printf("%s\n",stu0[j].s);
        }
        printf("E:\n");
        qsort(stu0,n,sizeof(struct stu),cmpe);
        printf("%s\n",stu0[0].s);
        for(j=1;j<n;j++)
        {
            if(stu0[j].e==stu0[0].e)
                printf("%s\n",stu0[j].s);
        }
    }
    return 0;
}
