#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int year,month,day;
    char d[50],m[50];
}node;
int cmp(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    if(s1.year!=s2.year)
        return s1.year-s2.year;
    else
    {
        if(s1.month!=s2.month)
            return s1.month-s2.month;
        else
            return s1.day-s2.day;
    }
}

int main()
{
   int t;
   scanf("%d\n",&t);
   for(int i=0;i<t;i++)
   {
       int n;
       scanf("%d",&n);
       node a[n];
       for(int i=0;i<n;i++)
       {
          // char s1[5],s2[10];
           scanf("%s %s %d",a[i].d,a[i].m,&a[i].year);
           int len=strlen(a[i].d);
           a[i].day=0;
           for(int j=0;j<len-1;j++)
            a[i].day=a[i].day*10+a[i].d[j]-'0';

           if(strcmp(a[i].m,"pop")==0)a[i].month=1;
           else if(strcmp(a[i].m,"no")==0)a[i].month=2;
           else if(strcmp(a[i].m,"zip")==0)a[i].month=3;
           else if(strcmp(a[i].m,"zotz")==0)a[i].month=4;
           else if(strcmp(a[i].m,"tzec")==0)a[i].month=5;
           else if(strcmp(a[i].m,"xul")==0)a[i].month=6;
           else if(strcmp(a[i].m,"yoxkin")==0)a[i].month=7;
           else if(strcmp(a[i].m,"mol")==0)a[i].month=8;
           else if(strcmp(a[i].m,"chen")==0)a[i].month=9;
           else if(strcmp(a[i].m,"yax")==0)a[i].month=10;
           else if(strcmp(a[i].m,"zac")==0)a[i].month=11;
           else if(strcmp(a[i].m,"ceh")==0)a[i].month=12;
           else if(strcmp(a[i].m,"mac")==0)a[i].month=13;
           else if(strcmp(a[i].m,"kankin")==0)a[i].month=14;
           else if(strcmp(a[i].m,"muan")==0)a[i].month=15;
           else if(strcmp(a[i].m,"pax")==0)a[i].month=16;
           else if(strcmp(a[i].m,"koyab")==0)a[i].month=17;
           else if(strcmp(a[i].m,"cumhu")==0)a[i].month=18;
           else if(strcmp(a[i].m,"uayet")==0)a[i].month=19;
       }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<n;i++)
            printf("%s %s %d\n",a[i].d,a[i].m,a[i].year);
   }
}
