#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {int day; char month[10]; int year;} date;

char m[][20] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac",
                "ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

int getmon(char s[])
{
    for (int i=0;i<20;i++)
        if (!strcmp(m[i],s)) return i; 
}

int cmp(const void* a,const void* b)
{
    date* c = (date*)a; date* d = (date*)b;
    if (c->year!=d->year) return c->year-d->year;
    if (getmon(c->month)!=getmon(d->month)) return getmon(c->month)-getmon(d->month);
    return c->day-d->day;
}

main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        date a[10001];
        int n;
        scanf("%d",&n);
        for (int j=0;j<n;j++)
        {
            scanf("%d. %s %d",&a[j].day,&a[j].month,&a[j].year);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%i:\n",i);
        for (int j=0;j<n;j++) printf("%d. %s %d\n",a[j].day,a[j].month,a[j].year);
    }
    return 0;
}