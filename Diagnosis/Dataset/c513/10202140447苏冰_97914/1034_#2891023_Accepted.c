#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct SSS
{
    double m;
    char c;
    int x;
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
    else
        return ((a->x)>(b->x) ? 1 : -1);
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
            {
                s[j].m=a[x[j]-'A'];
                s[j].x=(x[j]-'A')*2+1;
            }
            else if(x[j]>='a' && x[j]<='z')
            {
                 s[j].m=a[x[j]-'a'];
                 s[j].x=(x[j]-'a')*2;
            }
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
