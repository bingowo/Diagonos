#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char n[11] = {"LIST /NAME"};
char size[11] = {"LIST /SIZE"};
char time[11] = {"LIST /TIME"};

typedef struct{char blank[27],name[67];int year,month,day,hour,minutes,number;}file;

int cmpname(const void*a,const void*b)
{
    file c = *(file*)a;
    file d = *(file*)b;
    if(strcmp(c.name,d.name) < 0)return -1;
    else if(strcmp(c.name,d.name) > 0)return 1;
    else return 1;
}

int cmpsize(const void*a,const void*b)
{
    file c = *(file*)a;
    file d = *(file*)b;
    if(c.number < d.number)return -1;
    else if(c.number > d.number)return 1;
    else if(strcmp(c.name,d.name) < 0)return -1;
    else return 1;
}

int cmptime(const void*a,const void*b)
{
    file c = *(file*)a;
    file d = *(file*)b;
    if(c.year != d.year)return c.year - d.year;
    else if(c.month != d.month)return c.month - d.month;
    else if(c.day != d.day)return c.day - d.day;
    else if(c.hour != d.hour)return c.hour - d.hour;
    else if(c.minutes != d.minutes)return c.minutes - d.minutes;
    else if(strcmp(c.name,d.name) < 0)return -1;
    else return 1;
}

int main()
{
    int i,k,j,r,cas;
    char s[1007];
    file ss[107];
    while(scanf("%d",&cas)!=0)
    {
        
        gets(s);
        //if(cas == 0)break;
        for(i = 0; i < cas; i++)
        {
            gets(s);
            for(k = 0,ss[i].year = 0; s[k] != '-'; k++)ss[i].year = ss[i].year*10 + s[k]-'0';
            for(j = k+1,ss[i].month = 0; s[j] != '-'; j++)ss[i].month = ss[i].month*10 + s[j]-'0';
            for(k = j+1,ss[i].day = 0; s[k] != ' '; k++)ss[i].day = ss[i].day*10 + s[k]-'0';
            for(j = k+1,ss[i].hour = 0; s[j] != ':'; j++)ss[i].hour = ss[i].hour*10 + s[j]-'0';
            //if(!ss[i].hour)ss[i].hour = 24;
            for(k = j+1,ss[i].minutes = 0; s[k] != ' '; k++)ss[i].minutes = ss[i].minutes*10 + s[k]-'0';
            for(j = k,r = 0; s[j] == ' '; j++,r++)ss[i].blank[r] = s[j];
            ss[i].blank[r] = '\0';
            for(k = j,ss[i].number = 0; s[k] != ' '; k++)ss[i].number = ss[i].number*10 + s[k]-'0';
            for(j = k+1,r = 0; s[j] != '\0'; j++,r++)ss[i].name[r] = s[j];
            ss[i].name[r] = '\0';
        }
        gets(s);
        if(strcmp(s,n) == 0)
        {
            qsort(ss,cas,sizeof(ss[0]),cmpname);
            for(i = 0; i < cas; i++)printf("%d-%02d-%02d %02d:%02d%s%d %s\n",ss[i].year,ss[i].month,ss[i].day,ss[i].hour,ss[i].minutes,ss[i].blank,ss[i].number,ss[i].name);
            printf("\n");
        }
        else if(strcmp(s,size) == 0)
        {
            qsort(ss,cas,sizeof(ss[0]),cmpsize);
            for(i = 0; i < cas; i++)printf("%d-%02d-%02d %02d:%02d%s%d %s\n",ss[i].year,ss[i].month,ss[i].day,ss[i].hour,ss[i].minutes,ss[i].blank,ss[i].number,ss[i].name);
            printf("\n");
        }
        if(strcmp(s,time) == 0)
        {
            qsort(ss,cas,sizeof(ss[0]),cmptime);
            for(i = 0; i < cas; i++)printf("%d-%02d-%02d %02d:%02d%s%d %s\n",ss[i].year,ss[i].month,ss[i].day,ss[i].hour,ss[i].minutes,ss[i].blank,ss[i].number,ss[i].name);
            printf("\n");
        }
    }
    return 0;
}