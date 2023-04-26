#include <stdio.h>
#include <stdlib.h>
typedef struct{long long number;int C;int M;int E;int A;} score;
int cmpA(const void *a,const void *b)
{
    score *aa=(score *)a,*bb=(score *)b;
    if (aa->A!=bb->A)
        return bb->A-aa->A;
    else
        return aa->number-bb->number;
}
int cmpC(const void *a,const void *b)
{
    score *aa=(score *)a,*bb=(score *)b;
    if (aa->C!=bb->C)
        return bb->C-aa->C;
    else
        return aa->number-bb->number;
}
int cmpM(const void *a,const void *b)
{
    score *aa=(score *)a,*bb=(score *)b;
    if (aa->M!=bb->M)
        return bb->M-aa->M;
    else
        return aa->number-bb->number;
}
int cmpE(const void *a,const void *b)
{
    score *aa=(score *)a,*bb=(score *)b;
    if (aa->E!=bb->E)
        return bb->E-aa->E;
    else
        return aa->number-bb->number;
}


int main()
{
    int T;
    scanf("%d",&T);
    for (int cas=0;cas<T;cas++)
    {
        printf("case #%d:\n",cas);
        int n;
        scanf("%d",&n);
        score s[102]={};
        for (int i=0;i<n;i++)
        {
            scanf("%lld %d %d %d",&s[i].number,&s[i].C,&s[i].M,&s[i].E);
            s[i].A=(s[i].C+s[i].E+s[i].M)/3;
        }
        qsort(s,n,sizeof(s[0]),cmpA);
        printf("A:\n");
        int t=0;
        while (s[0].A==s[t].A&&t<n)
            printf("%lld\n",s[t++].number);

        qsort(s,n,sizeof(s[0]),cmpC);
        printf("C:\n");
        t=0;
        while (s[0].C==s[t].C&&t<n)
            printf("%lld\n",s[t++].number);

        qsort(s,n,sizeof(s[0]),cmpM);
        printf("M:\n");
        t=0;
        while (s[0].M==s[t].M&&t<n)
            printf("%lld\n",s[t++].number);

        qsort(s,n,sizeof(s[0]),cmpE);
        printf("E:\n");
        t=0;
        while (s[0].E==s[t].E&&t<n)
            printf("%lld\n",s[t++].number);

    }
}
