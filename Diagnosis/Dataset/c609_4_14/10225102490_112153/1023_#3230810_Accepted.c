#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *m[] = {"pop", "no", "zip", "zotz", "tzec","xul", "yoxkin", "mol", "chen", "yax",
"zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};

typedef struct
{
    int day;
    char mon[11];
    int year;
} Date;

int ccmp(char a[])
{

    for (int i = 0; i < 19; i++)
    {
        if (strcmp(a,m[i]) == 0)
        {
            //printf("i=%d\n",i);
            return i;
        }
    }
    //printf("ccmp\n");
    return -1;
}


int cmp(Date*a,Date*b)
{
    //printf("cmp\n");
    if (a->year != b->year) return a->year - b->year;
    else if (ccmp(a->mon) != ccmp(b->mon)) return ccmp(a->mon) - ccmp(b->mon);
    else return a->day - b->day;
}

void Sort(Date *ps, int n)
{
    qsort(ps,n,sizeof(Date),cmp);
    //printf("1\n");
}


int main()
{
    int T;
    scanf("%d",&T);
    for (int p = 0; p < T; p++)
    {
        int n;
        scanf("%d",&n);
        Date *a = (Date*)malloc(sizeof(Date) * n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d. %s %d\n",&a[i].day,&a[i].mon,&a[i].year);
        }
        Sort(a,n);
        printf("case #%d:\n",p);
        for (int i = 0; i < n; i++)
        {
            printf("%d. %s %d\n",a[i].day,a[i].mon,a[i].year);
        }

    }
}
