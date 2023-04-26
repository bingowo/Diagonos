#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
char mon[20][7]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};

typedef struct{char month[7];int day,year,num;}time;

int cmp(const void*a,const void*b)
{
    time c=*(time*)a;
    time d=*(time*)b;
    int j;
    for(j=0;;j++){if(strcmp(c.month,mon[j])==0)c.num=j;break;}
    for(j=0;;j++){if(strcmp(d.month,mon[j])==0)d.num=j;break;}
    if(c.year!=d.year)return c.year-d.year;
    else if(c.num<d.num)return 1;
    else if(c.num>d.num)return -1;
    else return c.day-d.day;
}


   int main()
   {
       int n,i,j,cas;
       time *s;
       scanf("%d",&n);
       for(i=0;i<n;i++)
       {
           scanf("%d",&cas);
           s=(time*)malloc(cas*sizeof(time));
           for(j=0;j<cas;j++)scanf("%d.%s%d",&s[j].day,s[j].month,&s[j].year);
           qsort(s,cas,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<cas;j++)printf("%d. %s %d\n",s[j].day,s[j].month,s[j].year);
       }
       free(s);

    return 0;
}