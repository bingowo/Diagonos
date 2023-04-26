#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    char dt[11];
    char tm[6];
    int sz;
    char nm[71];
}FL;

int cmptm(const void *a,const void *b)
{
    FL *p1=(FL*)a,*p2=(FL*)b;
    if(!strcmp(p1->dt,p2->dt))
    {
        if(!strcmp(p1->tm,p2->tm))
            return strcmp(p1->nm,p2->nm);
        return strcmp(p1->tm,p2->tm);
    }
    return strcmp(p1->dt,p2->dt);
}

int cmpnm(const void *a,const void *b)
{
    FL *p1=(FL*)a,*p2=(FL*)b;
    return strcmp(p1->nm,p2->nm);
}

int cmpsz(const void *a,const void *b)
{
    FL *p1=(FL*)a,*p2=(FL*)b;
    if(p1->sz==p2->sz) return strcmp(p1->nm,p2->nm);
    return p1->sz-p2->sz;
}

int main()
{
    int n;
    scanf("%d",&n);
    char cm[6],lt[5];
    while(n)
    {
        FL fl[101];
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%s %s %d %s",fl[i].dt,fl[i].tm,&fl[i].sz,fl[i].nm);
        }
        scanf("%s %s",lt,cm);
        if(!strcmp(cm,"/NAME"))
            qsort(fl,n,sizeof(fl[0]),cmpnm);
        else if(!strcmp(cm,"/SIZE"))
            qsort(fl,n,sizeof(fl[0]),cmpsz);
        else
            qsort(fl,n,sizeof(fl[0]),cmptm);
        for(i=0;i<n;i++)
            printf("%s %s %16d %s\n",fl[i].dt,fl[i].tm,fl[i].sz,fl[i].nm);
        printf("\n");
        if(!scanf("%d",&n)) break;
    }
    return 0;
}
