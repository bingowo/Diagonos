#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char day[4];
    char month[7];
    int year;
}DATE;

int fmonth(char s[])
{
    static char* month[]={"pop","no","zip","zotz","tzec","xul","yoxkin",
    "mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(int i=0;;i++)
        if(!strcmp(s,month[i])) return i;
}

int cmp(const void* a,const void* b)
{
    DATE *pa=(DATE*)a,*pb=(DATE*)b;
    if(pa->year!=pb->year) return pa->year-pb->year;
    else if(fmonth(pa->month)!=fmonth(pb->month)) return fmonth(pa->month)-fmonth(pb->month);
    else
    {
        int daya=0,dayb=0;
        for(int i=0;i<strlen(pa->day)-1;i++)
            daya=daya*10+pa->day[i]-'0';
        for(int i=0;i<strlen(pb->day)-1;i++)
            dayb=dayb*10+pb->day[i]-'0';
        return daya-dayb;
    }
    return 0;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        DATE* date=NULL;
        int N=0;
        scanf("%d",&N);
        date=(DATE*)malloc(N*sizeof(DATE));
        for(int i=0;i<N;i++)
            scanf("%s%s%d",date[i].day,date[i].month,&date[i].year);
        qsort(date,N,sizeof(date[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<N;i++)
            printf("%s %s %d\n",date[i].day,date[i].month,date[i].year);
        free(date);
    }
    return 0;
}
