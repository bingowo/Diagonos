#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int val;
    int day;
    char month[20];
    int m;
    int year;
}date;

int month2num(char* m)
{
   static char* month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for (int i=0;i<20;i++)
        if (strcmp(m,month[i])==0) return i+1;
}

int cmp(const void *q1,const void *q2)
{
    date *p1=(date *)q1;
    date *p2=(date *)q2;

    if(p1->val<p2->val) return -1;
    else return 1;
}

int main()
{
    int T;  scanf("%d\n",&T);

    int cnt;
    for(cnt=0;cnt<T;cnt++)
    {
        date cal[10100]={0};

        int n;  scanf("%d\n",&n);
        for(int i=1;i<n+1;i++)
            scanf("%d. %s %d\n",&cal[i].day,cal[i].month,&cal[i].year);

        for(int j=1;j<n+1;j++)
            cal[j].m=month2num(cal[j].month);

        for(int j=1;j<n+1;j++)
            cal[j].val=cal[j].day+cal[j].m*20+cal[j].year*1000;

        qsort(cal+1,n,sizeof(cal[1]),cmp);

        printf("case #%d:\n",cnt);
        for(int k=1;k<n+1;k++)
            printf("%d. %s %d\n",cal[k].day,cal[k].month,cal[k].year);

    }
    return 0;
}







