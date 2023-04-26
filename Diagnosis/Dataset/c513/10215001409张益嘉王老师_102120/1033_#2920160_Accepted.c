#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int day;
    char month[20];
    int mon;
    int year;
}time;

int tran(char s[])
{
    int re;
    if(strcmp(s,"pop")==0) re=1;
    else if (strcmp(s,"no")==0) re=2;
    else if (strcmp(s,"zip")==0) re=3;
    else if (strcmp(s,"zotz")==0) re=4;
    else if (strcmp(s,"tzec")==0) re=5;
    else if (strcmp(s,"xul")==0) re=6;
    else if (strcmp(s,"yoxkin")==0) re=7;
    else if (strcmp(s,"mol")==0) re=8;
    else if (strcmp(s,"chen")==0) re=9;
    else if (strcmp(s,"yax")==0) re=10;
    else if (strcmp(s,"zac")==0) re=11;
    else if (strcmp(s,"ceh")==0) re=12;
    else if (strcmp(s,"mac")==0) re=13;
    else if (strcmp(s,"kankin")==0) re=14;
    else if (strcmp(s,"muan")==0) re=15;
    else if (strcmp(s,"pax")==0) re=16;
    else if (strcmp(s,"koyab")==0) re=17;
    else if (strcmp(s,"cumhu")==0) re=18;
    else if (strcmp(s,"uayet")==0) re=19;

    return re;
}

int cmp(const void*a,const void*b)
{
    time aa=*((time*)a);
    time bb=*((time*)b);
    if(aa.year<bb.year) return -1;
    else if (aa.year>bb.year) return 1;
    else
    {
        if(aa.mon<bb.mon) return -1;
        else if (aa.mon>bb.mon) return 1;
        else
        {
            if(aa.day<bb.day) return -1;
            else return 1;
        }
    }

}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,j;
        scanf("%d",&n);
        time t[15000];
        char c;
        memset(t,0,sizeof(time)*15000);
        for(j=0;j<n;j++)
        {
            scanf("%d%c%s%d",&t[j].day,&c,t[j].month,&t[j].year);
            t[j].mon=tran(t[j].month);
            //printf("test j=%d: %d. %s %d\n",j,t[j].day,t[j].month,t[j].year);
        }
        qsort(t,n,sizeof(time),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)
        {
            printf("%d. %s %d\n",t[j].day,t[j].month,t[j].year);
        }
    }

    return 0;
}
