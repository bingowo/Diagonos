#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int day;
    int year;
    char month[20];
} Date;//
int cmp(const void *e1,const void *e2)
{///
    const char Maya[]="pop,no,zip,zotz,tzec,xul,yoxkin,mol,chen,yax,zac,ceh,mac,kankin,muan,pax,koyab,cumhu,uayet";
    Date d1=*(Date *)e1,d2=*(Date *)e2;
    if(d1.year!=d2.year)return d1.year-d2.year;
    else if(strstr(Maya,d1.month)!=strstr(Maya,d2.month))return (strstr(Maya,d1.month)-strstr(Maya,d2.month))/sizeof(char *);
    else return d1.day-d2.day;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N,j;
        Date *p=(Date *)malloc(sizeof(Date)*N);
        for(scanf("%d",&N),j=0;j<N;j++)
        {
            char s[2];
            scanf("%d",&p[j].day);
            scanf("%s",s);
            scanf("%s",p[j].month);
            scanf("%d",&p[j].year);
        }
        qsort(p,N,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<N;k++)
        {
            printf("%d. %s %d\n",p[k].day,p[k].month,p[k].year);
        }
        free(p);
    }
}