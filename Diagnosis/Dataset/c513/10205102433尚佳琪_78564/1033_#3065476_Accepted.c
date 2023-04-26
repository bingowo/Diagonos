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
   char maya[19][10]={"pop","no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac",
    "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
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
            for(int j=0;j<19;j++)
            {
                if(strcmp(a[i].m,maya[j])==0)
                    a[i].month=j;
            }

       }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<n;i++)
            printf("%s %s %d\n",a[i].d,a[i].m,a[i].year);
   }
}
