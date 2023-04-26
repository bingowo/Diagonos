#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct Maya{int day;int month;int year;char o[7];}MY;

int cmp(const void*a,const void* b)
{
    MY *p1=(MY *)a;
    MY *p2=(MY *)b;
    if(p1->year>p2->year)
    {
        return 1;
    }
    else if(p1->year<p2->year)
    {
        return -1;
    }
    else if (p1->month>p2->month)
    {
        return 1;
    }
    else if (p1->month<p2->month)
    {
        return -1;
    }
    else if (p1->day>p2->day)
    {
        return 1;
    }
    else
    {
        return -1;
    }

}

int month2idx(char* m)
{ int i;
  static char* month[] =
{"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
  for (i=0;;i++) if (!strcmp(m,month[i])) return i;
}


int main()
{
    int count,count1,number;

    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        scanf("%d",&number);
        MY M[100];
        MY*p=M;
        for(int i=0;i<number;i++)
        {
            int jishuqi=3;
            while(jishuqi)
            {
                if(jishuqi==3)
                scanf("%d.",&M[i].day);
                if(jishuqi==2)
                {
                    scanf("%s",M[i].o);
                    M[i].month=month2idx(M[i].o);
                }
                if(jishuqi==1)
                {
                    scanf("%d",&M[i].year);
                }
                jishuqi--;
            }
        }
        qsort(p,number,sizeof(M[0]),cmp);
        printf("case #%d:\n",count1-count-1);
        for(int i=0;i<number;i++)
    {
        printf("%d. %s %d\n",M[i].day,M[i].o,M[i].year);
    }
    }
}
