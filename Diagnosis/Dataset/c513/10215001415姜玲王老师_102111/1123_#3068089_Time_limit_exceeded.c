#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{char a[21];int t;} DNA;
int cmp(const void*p,const void*q)
{
    DNA p1=*(DNA*)p;
    DNA p2=*(DNA*)q;
    if(p1.t>p2.t) return 1;
    if(p1.t<p2.t) return -1;
    return strcmp(p1.a,p2.a);
}
int main()
{
    int n;
     DNA c[200000];
    char b[21];
    scanf("%d",&n);
    int i;
    int k,j=-1;
    for(i=0;i<n;i++)
    {
        scanf("%s",b);
        k=0;
        for(;k<=j;k++)

        {
           if(!strcmp(b,c[k].a))  {c[k].t++;break;}
        }
        if(k>j)
        {j++;
            strcpy(c[k].a,b);
            c[k].t=1;

        }
        }
        qsort(c,j+1,sizeof(c[0]),cmp);
        for(i=0;i<=j;i++)
        {
            printf("%s\n",c[i].a);
        }
}