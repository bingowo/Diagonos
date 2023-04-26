#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
char mon[20][7]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};

typedef struct{char day[4],month[7];int year,num,sum;}time;

int cmp(const void*a,const void*b)
{
    time c=*(time*)a;
    time d=*(time*)b;
    int i,j;
    c.num=0;d.num=0;
    c.sum=0;d.sum=0;
    for(i=0;c.day[i]!='.';i++)c.sum=c.sum*10+c.day[i]-'0';
    for(i=0;d.day[i]!='.';i++)d.sum=d.sum*10+d.day[i]-'0';
    for(j=0;;j++){if(strcmp(c.month,mon[j]))c.num=j;break;}
    for(j=0;;j++){if(strcmp(d.month,mon[j]))d.num=j;break;}
    if(c.year!=d.year)return c.year-d.year;
    else if(c.num!=d.num)return c.num-d.num;
    else return c.sum-d.sum;
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
           for(j=0;j<cas;j++)scanf("%s%s%d",s[j].day,s[j].month,&s[j].year);
           qsort(s,cas,sizeof(time),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<cas;j++)printf("%s %s %d\n",s[j].day,s[j].month,s[j].year);
       }
       free(s);

    return 0;
}