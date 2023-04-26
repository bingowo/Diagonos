#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int year(char* date)
{
    int i=0;
    for(i=0;date[i]!=' ';i++);
    for(i=i+1;date[i]!=' ';i++);
    int year=0;
    for(i=i+1;date[i];i++)
    year=date[i]-'0'+year*10;
    return year;
}
int month(char *date)
{
    char MONTHS[20][20]={"pop", "no", "zip", "zotz", "tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    int i,j;char months[20];
    for(i=0;date[i]!=' ';i++);
    for(i=i+1,j=0;date[i]!=' ';i++,j++)
    months[j]=date[i];
    months[j]='\0';
    for(i=0;i<19;i++)
    if(strcmp(months,MONTHS[i])==0)
    {
        break;
    }
    return i;
}
int day(char* date)
{
    int i;int day=0;
    for(i=0;date[i]!='.';i++)
    day=date[i]-'0'+day*10;
    return day;
}
int cmp(const void* e1,const void* e2)
{
    char* date1=*((char**)e1); char* date2=*((char**)e2);
    int year1=year(date1);int year2=year(date2);
    int month1=month(date1);int month2=month(date2);
    int day1=day(date1); int day2=day(date2);
    if(year1!=year2)
    return year1-year2;
    else
    {
        if(month1!=month2)
        return month1-month2;
        else return day1-day2;
    }
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int T;
        scanf("%d\n",&T);
        char **date=(char**)malloc(sizeof(char*)*T);
        for(int j=0;j<T;j++)
        {
           char* s=(char*) malloc(sizeof(char)*20);
           fgets(s, 20, stdin);
           date[j]=(char*)malloc(sizeof(char)*(strlen(s)+1));
           strcpy(date[j],s);
           free(s);
        }
        qsort(date,T,sizeof(date[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<T;j++)
        {printf("%s",date[j]);}
        free(date);
    }
}