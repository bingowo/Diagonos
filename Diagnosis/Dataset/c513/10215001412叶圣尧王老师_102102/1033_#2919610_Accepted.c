#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static char* prime[] =
{"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

struct st
{
    int day;
    char s[10];
    int month;
    int year;
};

int val(char*s)
{
    int i;
    for(i=0;i<19;i++)
    {
        if(strcmp(s,prime[i])==0)
        {return i+1;break;}
    }
}

int cmp(const void*a,const void*b)
{
    struct st*c=(struct st*)a;
    struct st*d=(struct st*)b;
    if(c->year!=d->year)return c->year-d->year;
    else if(c->month!=d->month)return c->month-d->month;
    else return c->day-d->day;
}

int main()
{
    int T,t;scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        int n,i;scanf("%d",&n);struct st maya[n];
        for(i=0;i<n;i++)
        {
            scanf("%d. %s %d",&maya[i].day,maya[i].s,&maya[i].year);
            maya[i].month=val(maya[i].s);
        }
        qsort(maya,n,sizeof(maya[0]),cmp);
        printf("case #%d:\n",t);
        for(i=0;i<n;i++)
        printf("%d. %s %d\n",maya[i].day,maya[i].s,maya[i].year);
    }
}
