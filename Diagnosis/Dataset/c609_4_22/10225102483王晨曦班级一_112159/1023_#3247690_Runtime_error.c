#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int val;
    int day;
    char month[20];
    int year;
}date;

int month2idx(char* m)
{
   static char* month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for (int i=0;; i++)
        if (!strcmp(m,month[i])) return i;
}

int cmp(const void *q1,const void *q2)
{
     return ((date*)q1)->val - ((date*)q2)->val;
}

int main()
{
    int T;  scanf("%d\n",&T);

    for(int v=0;v<T;v++)
    {
        date cal[101];

        int n;  scanf("%d\n",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d. %s %d\n",&cal[i].day,cal[i].month,&cal[i].year);
            cal[i].val = cal[i].year*1000 + month2idx(cal[i].month)*20 + cal[i].day;

        }

        qsort(cal,n,sizeof(cal),cmp);

        int h;
        printf("case #%d:\n",h++);
        for(int k=0;k<n;k++)
            printf("%d. %s %d\n",cal[k].day,cal[k].month,cal[k].year);
    }
    return 0;
}







