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
        return a->a-b->a;
}

int cmpc(const void *pa,const void *pb)
{
    struct stu *a=(struct stu*)pa;
    struct stu *b=(struct stu*)pb;
    if(a->c==b->c)
        return strcmp(a->s,b->s);
    else
        return a->c-b->c;
}

int cmpm(const void *pa,const void *pb)
{
    struct stu *a=(struct stu*)pa;
    struct stu *b=(struct stu*)pb;
    if(a->m==b->m)
        return strcmp(a->s,b->s);
    else
        return a->m-b->m;
}

int cmpe(const void *pa,const void *pb)
{
    struct stu *a=(struct stu*)pa;
    struct stu *b=(struct stu*)pb;
    if(a->e==b->e)
        return strcmp(a->s,b->s);
    else
        return a->e-b->e;
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
            scanf("%d",stu0[k].c);
            scanf("%d",stu0[k].m);
            scanf("%d",stu0[k].e);
            stu0[k].a=(stu0[k].c+stu0[k].m+stu0[k].e)/3;
            k++;
        }
        printf("case #%d:\n",i);
        printf("A:\n");
        qsort(stu0,n,sizeof(struct stu),cmpa);
        for(j=0;j<n;j++)
        {
            printf("%s\n",stu0[j].s);
        }
        printf("C:\n");
        qsort(stu0,n,sizeof(struct stu),cmpc);
        for(j=0;j<n;j++)
        {
            printf("%s\n",stu0[j].s);
        }
        printf("M:\n");
        qsort(stu0,n,sizeof(struct stu),cmpm);
        for(j=0;j<n;j++)
        {
            printf("%s\n",stu0[j].s);
        }
        printf("E:\n");
        qsort(stu0,n,sizeof(struct stu),cmpe);
        for(j=0;j<n;j++)
        {
            printf("%s\n",stu0[j].s);
        }
    }
    return 0;
}
