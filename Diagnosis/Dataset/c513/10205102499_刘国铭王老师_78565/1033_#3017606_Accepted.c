#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int year;
    int day;
    char mon[7];
    int val;
} DATE;

int cal(char* s)
{
    int i;
    char* month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(i=0;;i++)
    {
        if(!strcmp(s,month[i]))
            return i;
    }
}

int cmp(const void*a,const void*b)
{
    return (*(DATE*)a).val > (*(DATE*)b).val;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        DATE date[10001];
        for(int j=0;j<n;j++)
        {
            scanf("%d.%s%d",&date[j].day,&date[j].mon,&date[j].year);
            date[j].val=date[j].year*1000+cal(date[j].mon)*20+date[j].day;
        }
        qsort(date,n,sizeof(DATE),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
            printf("%d. %s %d\n",date[j].day,date[j].mon,date[j].year);
        }
    }
    return 0;
}
