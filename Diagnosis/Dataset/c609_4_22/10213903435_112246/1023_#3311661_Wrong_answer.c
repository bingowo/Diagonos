#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//int cmp(const void *e1,const void *e2)
//{
//    const char Maya[]="pop,no,zip,zotz,tzec,xul,yoxkin,mol,chen,yax,zac,ceh,mac,kankin,muan,pax,koyab,cumhu,uayet";
//    char s1[20],s2[20];
//    strcpy(s1,(char *)e1),
//    strcpy(s2,(char *)e2);
//    char *year1,*year2,*month1,*month2,*day1,*day2;
//    strcpy(year1,strrchr(s1,' ')),strcpy(year2,strrchr(s2,' '));
//    day1=strtok(s1," ");
//    month1=strtok(NULL," ");
//    year1=strtok(NULL," ");
//    day2=strtok(s2," ");
//    month2=strtok(NULL," ");
//    year2=strtok(NULL," ");
//    if(strcmp(year1,year2))return strcmp(year1,year2);
//    else if(strstr(Maya,month1)!=strstr(Maya,month2))return (strstr(Maya,month1)-strstr(Maya,month2))/sizeof(char *);
//    else return strcmp(day1,day2);
//}
//int main()
//{
//    int T;
//    scanf("%d",&T);
//    for(int j=0;j<T;j++)
//    {
//        int N;
//        scanf("%d",&N);
//        char **p=(char **)malloc(sizeof(char *)*N);
//        getchar();
//        for(int i=0;i<N;i++)
//        {
//            p[i]=(char *)malloc(sizeof(char)*20);
//            fgets(p[i],19,stdin);
//        }
//        int tmp=cmp(p[0],p[1]);
//        qsort(p,N,sizeof(p[0]),cmp);
//        for(int i=0;i<N;i++)
//        {
//            printf("case #%d:\n%s",i,p[i]);
//            free(p[i]);
//        }
//        free(p);
//    }
//    return 0;
//}

typedef struct
{
    int day;
    int year;
    char month[20];
} Date;
int cmp(const void *e1,const void *e2)
{
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
        //printf("case #%d:\n",i);
        for(int k=0;k<N;k++)
        {
            printf("%d. %s %d\n",p[k].day,p[k].month,p[k].year);
        }
        free(p);
    }
}
