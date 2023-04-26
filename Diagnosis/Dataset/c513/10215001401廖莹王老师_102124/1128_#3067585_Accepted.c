#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char s[350];
    char ym[350];
    char dz[350];
}web;
int cmp(const void*a,const void*b)
{
    web *k1,*k2;
    k1=(web*)a;k2=(web*)b;
    if(strcmp(k1->ym,k2->ym)!=0)return strcmp(k1->ym,k2->ym);
    else return strcmp(k1->dz,k2->dz);

}
int main()
{
    int n,i=0,j=0,m=0,l=0;
    scanf("%d",&n);
    web p[110];
    for(i=0;i<n;i++)
    {   char t[350]={0};
        scanf("%s",t);
        if(t[4]=='s')continue;
        else
        {
            strcpy(p[l].s,t);
            for(j=7,m=0;p[l].s[j];j++,m++){if(p[l].s[j]=='/')break;else {p[l].ym[m]=p[l].s[j];}}
            for(j++,m=0;p[l].s[j];j++,m++)p[l].dz[m]=p[l].s[j];
            l++;
        }
    }
    qsort(p,l,sizeof(p[0]),cmp);
    for(i=0;i<l;i++)printf("%s\n",p[i].s);
    return 0;
}
