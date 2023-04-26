#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
char mon[20][7]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};

typedef struct{char month[7],d;int day,year,num;}time;

int cmp(const void*a,const void*b)
{
    time c=*(time*)a;
    time d=*(time*)b;
    int j,sum1,sum2;
    for(j=0;;j++)
        {if(strcmp(c.month,mon[j]))c.num=j;break;}
    for(j=0;;j++)
        {if(strcmp(d.month,mon[j]))d.num=j;break;}
    sum1=c.year*1000+c.num*20+c.day;
    sum2=d.year*1000+d.num*20+d.day;
    return sum1-sum2;
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
           for(j=0;j<cas;j++)scanf("%d%c%s%d",&s[j].day,&s[j].d,s[j].month,&s[j].year);
           qsort(s,cas,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<cas;j++)printf("%d. %s %d\n",s[j].day,s[j].month,s[j].year);
       }
       free(s);

    return 0;
}