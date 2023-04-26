#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char month[19][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
typedef struct
{
    int day;
    int year;
    char month[10];
    int month0;
}date;

long long myabs(long long a)
{
    if(a>=0)
        return a;
    else
        return -a;
}

int cmpfuncup (const void * a, const void * b)
{
   int c=*(int*)a - *(int*)b ;
        return c;
}

int cmpfuncdate (const void * a, const void * b)
{
   date *da=(date *)a;
   date *db=(date *)b;
   if(da->year!=db->year) return da->year>db->year? 1:-1;
   else if(da->month0!=db->month0) return da->month0>db->month0? 1:-1;
   else
    return da->day>db->day? 1:-1;
}

int monthtonumber(char *a)
{
    for(int t=0;t<19;t++)
    {if(strcmp(a,month[t])==0)
        return t+1;}
}



int main()
{
    int quesnum;
    scanf("%d\n",&quesnum);
    for(int i=0;i<quesnum;i++)
    {
        printf("case #%d:\n",i);
        int kazu;
        scanf("%d",&kazu);
        date d[10002];
        for(int j=0;j<kazu;j++)
            scanf("%d. %s %d",&d[j].day,&d[j].month,&d[j].year);
        for(int j=0;j<kazu;j++)
            d[j].month0=monthtonumber(d[j].month);
        qsort(d,kazu,sizeof(d[0]),cmpfuncdate);
        for(int j=0;j<kazu;j++)
            printf("%d. %s %d",d[j].day,d[j].month,d[j].year);
    }

    return 0;
}
