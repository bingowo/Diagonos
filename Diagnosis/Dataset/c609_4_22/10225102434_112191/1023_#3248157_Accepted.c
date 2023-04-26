#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct
{
    int year;
    char month[7];
    int mon;
    int day;
}Date;
int Find(char *p,char s[19][7])
{
    int i;
    for(i = 0;i<19;i++)
    {
        if(strcmp(s[i],p)==0)return i;
    }
}
int cmp(const void *a,const void *b)
{
    Date*p1 = (Date*)a;
    Date*p2 = (Date*)b;
    if((p1->year) !=( p2->year))return (p1->year)-(p2->year);
    if((p1->year)  == (p2->year))
    {
        if((p1->mon)!=(p2->mon))return (p1->mon)-(p2->mon);
        else if(p1->mon == p2->mon)return p1->day-p2->day;
    }
}
int main()
{
    char s[19][7] ={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen"
    , "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
    int n,m,i,j;
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",&m);
        Date date[m];
        for(j = 0;j<m;j++)
        {
             scanf("%d",&date[j].day);
             getchar();getchar();
             scanf("%s",date[j].month);
             scanf("%d",&date[j].year);
             date[j].mon = Find(date[j].month,s);
        }
        qsort(date,m,sizeof(date[0]),cmp);
        printf("case #%d:\n",i);
        for(j = 0;j<m;j++)
            printf("%d. %s %d\n",date[j].day,date[j].month,date[j].year);
    }
    return 0;
}
