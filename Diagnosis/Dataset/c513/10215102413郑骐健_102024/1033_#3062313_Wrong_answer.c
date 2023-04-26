#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int num = 20;


char m[19][20]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh","mac","kankin", "muan", "pax", "koyab",
"cumh","uayet"
};
struct data
{
    int year;
    int day;
    char month [20];
};

int cmp(const void *p1,const void*p2)
{
    struct data* p_1 = (struct data*)p1;
    struct data* p_2 = (struct data*)p2;
    if(p_1->year>p_2->year)return 1;
    else if(p_1->year<p_2->year)return -1;
    else
    {
        if(check(p_1->month)==check(p_2->month))
        {
            return p_1->day -p_2->day;
        }
        else return check(p_1->month)-check(p_2->month);
    }
}
int check(char *p)
{
    for(int i=0;i<19;i++)
    {
        if(!strcmp(p,m[i]))return i;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int k=0;k<n;k++)
    {
        printf("case #%d:\n",k);
        int rq;
        scanf("%d",&rq);
        struct data* all = (struct data*)malloc(sizeof(struct data)*10000);
        for(int i=0;i<rq;i++)
        {
            scanf("%d",&(all[i].day));
            char less;
            scanf("%c",&less);
            scanf("%s",&(all[i].month));
//            printf("%d\n",check(all[i].month));
            scanf("%d",&(all[i].year));
        }
        qsort(all,rq,sizeof(struct data),cmp);
        for(int z=0;z<rq;z++)
        {
            printf("%d. %s %d%c",all[z].day,all[z].month,all[z].year,(k==n-1&&z==rq-1)?0:'\n');
        }
    }
   // system("pause");
    return 0;
}
