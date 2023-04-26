#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char m[10];
    int year;
    int month;
    int day;
}date;
int ToMonth(char* p)
{
    static char* month[30]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(int i=0;i<=19;i++)  if(strcmp(p,month[i])==0)  return i;
}
int cmp(const void *a,const void *b)
{
    date *pa=(date*)a,*pb=(date*)b;
    if(pa->year != pb->year)  return pa->year - pb->year;
    else if(pa->month != pb->month)  return pa->month - pb->month;
    else if(pa->day != pb->day)  return pa->day - pb->day;
    else  return -1;
}
int main()
{
    int T,N,i,j,d,m;
    date a[10010];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        for(j=0;j<N;j++)
        {
            scanf("%d. %s %d",&a[j].day,&a[j].m,&a[j].year);
            a[j].month=ToMonth(a[j].m);
        }
        qsort(a,N,sizeof(date),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<N;j++)
        {
            printf("%d. %s %d\n",a[j].day,a[j].m,a[j].year);
        }
    }
    return 0;
}