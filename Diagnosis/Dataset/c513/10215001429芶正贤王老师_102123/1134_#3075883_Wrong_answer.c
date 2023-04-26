#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


typedef struct
{
    char id[15];
    int gc,gm,ge;
    double ga;
}STRUCT;

int cmpa(const void*a,const void*b)
{
    STRUCT *x=(STRUCT*)a;
    STRUCT *y=(STRUCT*)b;
    if(fabs((x->ga)-(y->ga))>=1e-6)
        return ((y->ga)-(x->ga));
    else
        return strcmp(x->id,y->id);
}
int cmpc(const void*a,const void*b)
{
    STRUCT *x=(STRUCT*)a;
    STRUCT *y=(STRUCT*)b;
    if((x->gc)!=(y->gc))
        return ((y->gc)-(x->gc));
    else
        return strcmp(x->id,y->id);
}
int cmpm(const void*a,const void*b)
{
    STRUCT *x=(STRUCT*)a;
    STRUCT *y=(STRUCT*)b;
    if((x->gm)!=(y->gm))
        return ((y->gm)-(x->gm));
    else
        return strcmp(x->id,y->id);
}
int cmpe(const void*a,const void*b)
{
    STRUCT *x=(STRUCT*)a;
    STRUCT *y=(STRUCT*)b;
    if((x->ge)!=(y->ge))
        return ((y->ge)-(x->ge));
    else
        return strcmp(x->id,y->id);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)//进入问题
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        STRUCT CASE[n];
        for(int j=0;j<n;j++)
        {
            scanf("%s",CASE[j].id);
            scanf("%d",&CASE[j].gc);
            scanf("%d",&CASE[j].gm);
            scanf("%d",&CASE[j].ge);
            CASE[j].ga = ((double)(CASE[j].gc+CASE[j].gm+CASE[j].ge))/3;
        }

        printf("A:\n");//对A排序
        qsort(CASE,n,sizeof(STRUCT),cmpa);
        for(int r=0;r<n;r++)
        {
            if(fabs(CASE[r].ga - CASE[0].ga)<1e-6)
                printf("%s\n",CASE[r].id);
            else
                break;
        }

        printf("C:\n");//对C排序
        qsort(CASE,n,sizeof(STRUCT),cmpc);
        for(int r=0;r<n;r++)
        {
            if(CASE[r].gc == CASE[0].gc)
                printf("%s\n",CASE[r].id);
            else
                break;
        }

        printf("M:\n");//对M排序
        qsort(CASE,n,sizeof(STRUCT),cmpm);
        for(int r=0;r<n;r++)
        {
            if(CASE[r].gm == CASE[0].gm)
                printf("%s\n",CASE[r].id);
            else
                break;
        }

        printf("E:\n");//对E排序
        qsort(CASE,n,sizeof(STRUCT),cmpe);
        for(int r=0;r<n;r++)
        {
            if(CASE[r].ge == CASE[0].ge)
                printf("%s\n",CASE[r].id);
            else
                break;
        }

    }
    return 0;
}

