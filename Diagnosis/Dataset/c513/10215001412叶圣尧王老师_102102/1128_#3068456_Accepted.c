#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char ym[300],xnym[300];
    char q[301];
}sj;

int cmp(const void*a,const void*b)
{
    sj*c=(sj*)a;
    sj*d=(sj*)b;
    if(strcmp(c->ym,d->ym)!=0)
    return strcmp(c->ym,d->ym);
    else return strcmp(c->xnym,d->xnym);
}

int main()
{
    int n,i,j,e,k=0;scanf("%d",&n);
    char s[301];sj p[n];
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        if(s[4]=='s')continue;
        strcpy(p[k].q,s);
        for(j=7;s[j]!='/'&&j<strlen(s);j++)
            p[k].ym[j-7]=s[j];
        p[k].ym[j-7]='\0';
        for(e=j;e<strlen(s);e++)
            p[k].xnym[e-j]=s[e];
        p[k].xnym[e-j]='\0';
        k++;
    }
    qsort(p,k,sizeof(p[0]),cmp);
    for(i=0;i<k;i++)
        printf("%s\n",p[i].q);
}