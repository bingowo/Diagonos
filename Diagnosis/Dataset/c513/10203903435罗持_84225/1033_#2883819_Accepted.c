#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct node
{
	char day[20];
	char monthname[10];
	int month;
	int year;
}a[10005];
int mycmp(const void*aa,const void*bb)
{
	struct node x = *(struct node*)aa;
	struct node y = *(struct node*)bb;
	if(x.year == y.year)
	{
		if(x.month == y.month)
		{
			int x_ri = 0;
			int time = 1;
			for(int i=strlen(x.day)-2;i>=0;i--)
			{
				x_ri += time*(x.day[i]-'0');
				time *= 10;
			}
			int y_ri = 0;
			time = 1;
			for(int i=strlen(y.day)-2;i>=0;i--)
			{
				y_ri += time * (y.day[i]-'0');
				time *= 10; 
			}
			if(x_ri > y_ri) return 1;
			else return -1;
		}
		else
		{
			if(x.month > y.month) return 1;
			else return -1;
		}
	}
	else
	{
		if(x.year > y.year) return 1;
		else return -1;
	}
}
int main(void)
{
	int T;
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
		{
			char month[10];
			scanf("%s %s %d",&a[i].day,month,&a[i].year);
			strcpy(a[i].monthname,month);
			if(strcmp(month,"pop")==0) a[i].month = 0;
			if(strcmp(month,"no")==0) a[i].month = 1;
			if(strcmp(month,"zip")==0) a[i].month = 2;
			if(strcmp(month,"zotz")==0) a[i].month = 3;
			if(strcmp(month,"tzec")==0) a[i].month = 4;
			if(strcmp(month,"xul")==0) a[i].month = 5;
			if(strcmp(month,"yoxkin")==0) a[i].month = 6;
			if(strcmp(month,"mol")==0) a[i].month = 7;
			if(strcmp(month,"chen")==0) a[i].month = 8;
			if(strcmp(month,"yax")==0) a[i].month = 9;
			if(strcmp(month,"zac")==0) a[i].month = 10;
			if(strcmp(month,"ceh")==0) a[i].month = 11;
			if(strcmp(month,"mac")==0) a[i].month = 12;
			if(strcmp(month,"kankin")==0) a[i].month = 13;
			if(strcmp(month,"muan")==0) a[i].month = 14;
			if(strcmp(month,"pax")==0) a[i].month = 15;
			if(strcmp(month,"koyab")==0) a[i].month = 16;
			if(strcmp(month,"cumhu")==0) a[i].month = 17;
			if(strcmp(month,"uayet")==0) a[i].month = 18;
		}
		qsort(a+1,n,sizeof(a[0]),mycmp);
		printf("case #%d:\n",kase);
		for(int i=1;i<=n;i++) 
			printf("%s %s %d\n",a[i].day,a[i].monthname,a[i].year);
	}
	return 0;
}