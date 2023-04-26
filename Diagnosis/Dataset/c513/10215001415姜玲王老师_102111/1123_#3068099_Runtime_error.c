#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{char a[21];int t;} DNA;
int cmp1(const void*p,const void*q)
{
    char*p1=*(char**)p;
    char*p2=*(char**)q;
    return strcmp(p1,p2);
}
int cmp2(const void*p,const void*q)
{
    DNA p1=*(DNA*)p;
    DNA p2=*(DNA*)q;
    if(p1.t>p2.t) return 1;
    if(p1.t<p2.t) return -1;
    return strcmp(p1.a,p2.a);
}
int main()
{
    int n,j=1;
    char p[200000][21];
     DNA c[200000];
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%s",p[i]);
    }
    qsort(p,n,sizeof(p[0]),cmp1);
    strcpy(c[0].a,p[0]);
    c[0].t=1;
    for(i=1;i<n;i++)
    {
        if(strcmp(p[i],p[i-1]))
            {
             strcpy(c[j].a,p[i]);
             c[j].t=1;
             j++;
             }
        else{
            c[j-1].t++;
            }

    }
     qsort(c,j,sizeof(c[0]),cmp2);
        for(i=0;i<=j;i++)
        {
            printf("%s\n",c[i].a);
        }
}
