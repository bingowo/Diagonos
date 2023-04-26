#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int day;
    int mon;
    int year;
    char s[20];
} data;


int MonthMap(char *s)
{
	int ret;
	if(strcmp(s, "pop") == 0)			{ ret = 1;}
	else if(strcmp(s, "no") == 0)		{ ret = 2;}
	else if(strcmp(s, "zip") == 0)		{ ret = 3;}
	else if(strcmp(s, "zotz") == 0)		{ ret = 4;}
	else if(strcmp(s, "tzec") == 0)		{ ret = 5;}
	else if(strcmp(s, "xul") == 0)		{ ret = 6;}
	else if(strcmp(s, "yoxkin") == 0)	{ ret = 7;}
	else if(strcmp(s, "mol") == 0)		{ ret = 8;}
	else if(strcmp(s, "chen") == 0)		{ ret = 9;}
	else if(strcmp(s, "yax") == 0)		{ ret = 10;}
	else if(strcmp(s, "zac") == 0)		{ ret = 11;}
	else if(strcmp(s, "ceh") == 0)		{ ret = 12;}
	else if(strcmp(s, "mac") == 0)		{ ret = 13;}
	else if(strcmp(s, "kankin") == 0)	{ ret = 14;}
	else if(strcmp(s, "muan") == 0)		{ ret = 15;}
	else if(strcmp(s, "pax") == 0)		{ ret = 16;}
	else if(strcmp(s, "koyab") == 0)	{ ret = 17;}
	else if(strcmp(s, "cumhu") == 0)	{ ret = 18;}
	else if(strcmp(s, "uayet") == 0)	{ ret = 19;}
	
	return ret;
}

int cmp (const void *pa, const void *pb)
{
    data a=*(data*)pa;
    data b=*(data*)pb;
    if(a.year==b.year)
    {
        if(a.mon==b.mon)
        {
            return a.day-b.day;
        }
        else  return a.mon-b.mon;
    }
    else return  a.year-b.year;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int j=0; j<t; j++)
    {
        int n;
        scanf("%d",&n);
        data* p= (data*)malloc(sizeof(data)*n); 
        for(int i=0; i<n; i++)
        {
           scanf("%d. %s %d",&p[i].day,p[i].s,&p[i].year);
           p[i].mon = MonthMap(p[i].s);
        }
        qsort(p,n,sizeof(data),cmp);
        printf("case #%d:\n",j);
        for(int i=0; i<n; i++)
        {
            printf("%d. %s %d\n",p[i].day,p[i].s,p[i].year);
        }
        free(p);
    }
    
    return 0;

}