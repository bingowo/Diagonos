#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
char table[19][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
typedef struct SSS
{
    char day[5];
    char month[10];
    int year;
    int mo;
}sss;
int cmp(const void*_a,const void*_b)
{
    sss* a=(sss*)_a;
    sss* b=(sss*)_b;
    if(a->year != b->year) return a->year - b->year;
    else if(strcmp(a->month,b->month)!=0) return a->mo - b->mo;
    else return strcmp(a->day,b->day);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int n;
        scanf("%d",&n);
        sss s[n];
        for(int i=0;i<n;i++)
        {
             scanf("%s%s%d",s[i].day,s[i].month,&s[i].year);
             for(int j=0;j<19;j++)
             {
                 if(strcmp(table[j],s[i].month)==0)
                 {
                     s[i].mo=j+1;
                     break;
                 }
             }
        }
        qsort(s,n,sizeof(sss),cmp);
        printf("case #%d:\n",cas);
        for(int i=0;i<n;i++)
        {
            printf("%s %s %d\n",s[i].day,s[i].month,s[i].year);
        }
    }
    return 0;
}
