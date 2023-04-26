#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
int day,month,year;}
date;
date dates[10000];
int t;
int n;
int intdates[10000];
char month[20][7]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin",
 "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
/*int chartoint(char *c)
{
    int answer=0;
    int i=0;
    while(c[i]!='\0')
    {
        answer+=c[i]-'0';
        answer*=10;
    }
    answer/=10;
    return answer;
}*/
int monthtoint(char *s)
{
    int i=0;
    for(;i<=20;i++)
    {
        if(strcmp(s,month[i])==0)
            break;
    }
    return i;
}
int cmp(const void *p1,const void *p2)
{
    date *a=(date*)p1;date *b=(date*)p2;
    if(intdates[a->year]==intdates[b->year])
    {
        if(intdates[a->month]==intdates[b->month])
            return intdates[a->day]-intdates[b->day];
        return intdates[a->month]-intdates[b->month];
    }
    return intdates[a->year]-intdates[b->year];
}
int main()
{
    scanf("%d",&t);
    char c[3];
    for(int i=0;i<t;i++)
    {
        char temmonth[10];
        int index=0;
        scanf("%d",&n);
        for(int f=0;f<n;f++){
        for(int j=0;j<3;j++)
        {
            c[j]=getchar();
            if (c[j]=='.')
            {
                c[j]='\0';
                break;
            }
        }
        intdates[index]=atoi(c);
        dates[f].day=index;
        index+=1;
        scanf("%s",temmonth);
        intdates[index]=monthtoint(temmonth);
        dates[f].month=index;
        //printf("%d",monthtoint(temmonth));
        index+=1;
        scanf("%d",&intdates[index]);
        dates[f].year=index;
        index+=1;
        }
        qsort(dates,n,sizeof(date),cmp);
        printf("case #%d:\n",i);
        for(int m=0;m<n;m++)
        {
            printf("%d.%s %d\n",intdates[dates[m].day],month[intdates[dates[m].month]],intdates[dates[m].year]);
        }

    }
    return 0;
}
