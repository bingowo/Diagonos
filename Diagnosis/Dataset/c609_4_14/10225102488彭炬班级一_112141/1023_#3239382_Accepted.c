#include <stdio.h>
#include <string.h>

char *table[] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

typedef struct
{
    int day;
    char month[7];
    int year;
    int number;
}Date;

int getmonth(char s[])
{
    int i = 0;
    while(strcmp(s,table[i])!=0) i++;
    return i;
}

int cmp(const void *a,const void *b)
{
    Date *p1 = (Date *)a;
    Date *p2 = (Date *)b;
    if(p1->year == p2->year)
    {
        if(p1->number == p2->number)
            return p1->day - p2->day;
        else
            return p1->number - p2->number;
    }
    else
        return p1->year - p2->year;
}

int main()
{
    int N;
    scanf("%d",&N);
    for(int i = 0;i < N;i++)
    {
        int n;
        scanf("%d",&n);
        Date date[n];
        for(int j = 0;j < n;j++)
        {
            scanf("%d. %s %d",&date[j].day,&date[j].month,&date[j].year);
            date[j].number = getmonth(date[j].month);
        }
        qsort(date,n,sizeof(date[0]),cmp);
        printf("case #%d:\n",i);
        for(int j = 0;j < n;j++)
            printf("%d. %s %d\n",date[j].day,date[j].month,date[j].year);
    }
}
