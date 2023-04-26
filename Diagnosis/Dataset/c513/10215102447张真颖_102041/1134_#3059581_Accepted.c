#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char num[12];
    int c,m,e,a;
}STUDENT;

int cmpa(const void*pa,const void*pb)
{
    STUDENT a=*(STUDENT*)pa,b=*(STUDENT*)pb;
    if(a.a!=b.a) return b.a-a.a;
    else return strcmp(a.num,b.num);
}
int cmpc(const void*pa,const void*pb)
{
    STUDENT a=*(STUDENT*)pa,b=*(STUDENT*)pb;
    if(a.c!=b.c) return b.c-a.c;
    else return strcmp(a.num,b.num);
}
int cmpm(const void*pa,const void*pb)
{
    STUDENT a=*(STUDENT*)pa,b=*(STUDENT*)pb;
    if(a.m!=b.m) return b.m-a.m;
    else return strcmp(a.num,b.num);
}
int cmpe(const void*pa,const void*pb)
{
    STUDENT a=*(STUDENT*)pa,b=*(STUDENT*)pb;
    if(a.e!=b.e) return b.e-a.e;
    else return strcmp(a.num,b.num);
}


int main()
{
    int T=0;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int n=0;
        scanf("%d",&n);
        STUDENT tab[100]={{0},0,0,0};
        for(int i=0;i<n;i++)
        {
            scanf("%s%d%d%d",tab[i].num,&tab[i].c,&tab[i].m,&tab[i].e);
            double t=(tab[i].c+tab[i].m+tab[i].e)/3.0;
            tab[i].a=(int)(t+0.5);
        }
        printf("case #%d:\n",cas);
        printf("A:\n");
        qsort(tab,n,sizeof(tab[0]),cmpa);
        int i=0;
        do
        {
            printf("%s\n",tab[i].num);
            i++;
        }while(tab[i].a==tab[i-1].a&&i<n&&i>0);

        printf("C:\n");
        qsort(tab,n,sizeof(tab[0]),cmpc);
        i=0;
        do
        {
            printf("%s\n",tab[i].num);
            i++;
        }while(tab[i].c==tab[i-1].c&&i<n&&i>0);

        printf("M:\n");
        qsort(tab,n,sizeof(tab[0]),cmpm);
        i=0;
        do
        {
            printf("%s\n",tab[i].num);
            i++;
        }while(tab[i].m==tab[i-1].m&&i<n&&i>0);

        printf("E:\n");
        qsort(tab,n,sizeof(tab[0]),cmpe);
        i=0;
        do
        {
            printf("%s\n",tab[i].num);
            i++;
        }while(tab[i].e==tab[i-1].e&&i<n&&i>0);

    }
    return 0;
}