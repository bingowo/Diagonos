#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct SSS
{
    double m;
    char c;
}sss;
double a[30];
int cmp(const void*_a,const void*_b)
{
    sss* a=(sss*)_a;
    sss* b=(sss*)_b;
    if(fabs((a->m)-(b->m))>1e-6)
    {
        return ((a->m) > (b->m) ? -1 : 1);
    }
    else if(((a->c)>='A' && (a->c)<='Z' && (b->c)>='A' && (b->c)<='Z') || ((a->c)>='a' && (a->c)<='z' && (b->c)>='a' && (b->c)<='z'))
        return ((a->c)>(b->c) ? 1 : -1);
    else if((a->c)>='A' && (a->c)<='Z' && (b->c)>='a' && (b->c)<='z')
        return 1;
    else if((a->c)>='a' && (a->c)<='z' && (b->c)>='A' && (b->c)<='Z')
        return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    sss s[110];
    char x[110];
    for(int i=0;i<T;i++)
    {
        for(int j=0;j<26;j++)
        {
            scanf("%lf",&a[j]);
        }
        scanf("%s",x);
        int j;
        for(j=0;j<strlen(x);j++)
        {
            s[j].c=x[j];
            if(x[j]>='A' && x[j]<='Z')
                s[j].m=a[x[j]-'A'];
            else if(x[j]>='a' && x[j]<='z')
                s[j].m=a[x[j]-'a'];
        }
        qsort(s,j,sizeof(sss),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<j;k++)
        {
            printf("%c",s[k].c);
        }
        printf("\n");
    }
    return 0;
}
