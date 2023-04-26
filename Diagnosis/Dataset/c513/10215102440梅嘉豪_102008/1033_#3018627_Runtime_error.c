#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char* month[] ={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

typedef struct 
{
    int year,month,day;
    char* s_month;
}DATE;
DATE* set_date(int y,char* m,int d);
void destroy_date(DATE* p);
int cmp(const void* a,const void *b);
void print_date(DATE* p);


int main()
{
    int T;
    scanf("%d",&T);
    DATE* dates[10001];
    for(int i=0;i<T;i++)
    {
        int N,y,d;
        char m[10];
        scanf("%d",&N);
        for(int j=0;j<N;j++)    
        {
            scanf("%d.%s%d",&d,m,&y);
            dates[j]=set_date(y,m,d);
        }print_date(dates[0]);
        /*qsort(dates,N,sizeof(DATE*),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)    
        {
            print_date(dates[j]);
            destroy_date(dates[j]);
        }*/
    }

}
DATE* set_date(int y,char* m,int d)
{
    DATE* p=(DATE*)malloc(sizeof(DATE));
    p->s_month=strdup(m);
    for(int i=0;i<20;i++)
    {
        if(!strcmp(m,month[i]))
        {
        p->month=i;
        break;
        }
    }
    p->day=d;
    p->year=y;
    return p;
}
void destroy_date(DATE* p)
{
    free(p->s_month);
    free(p);
}
int cmp(const void* a,const void *b)
{
    DATE* pa=*(DATE**)a;
    DATE* pb=*(DATE**)b;
    // DATE* pa=*ppa;
    // DATE* pb=*ppb;

    if(pa->year!=pb->year)  return pa->year<pb->year?-1:1;
    if(pa->month!=pb->month)    return pa->month<pb->month?-1:1;
    return pa->day<pb->day?-1:1;
}
void print_date(DATE* p)
{
    printf("%d. %s %d\n",p->day,p->s_month,p->year);
}
