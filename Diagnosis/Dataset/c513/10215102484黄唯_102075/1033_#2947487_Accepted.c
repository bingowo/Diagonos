#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int day;
	char month[10];
	int year;
}Date;

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

int cmp(const void *a, const void *b)
{
	Date *pa = (Date *)a;
	Date *pb = (Date *)b;
	if(pa->year != pb->year){
		return pa->year - pb->year;
	}else if(MonthMap(pa->month) != MonthMap(pb->month)){
		return MonthMap(pa->month) - MonthMap(pb->month);
	}else{
		return pa->day - pb->day;
	}
	
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i  = 0 ; i < t ; i ++){
		int n;
		scanf("%d", &n);
		Date date[n];
		for(int j = 0 ; j < n ; j ++ ){
			scanf("%d. %s %d", &date[j].day, date[j].month, &date[j].year);
			//这里用了scanf的一些性质，吞掉了不需要的'.' 
		}
		qsort(date, n, sizeof(Date), cmp);
		printf("case #%d:\n", i);
		for(int j = 0 ; j < n ; j ++){
			printf("%d. %s %d\n", date[j].day, date[j].month, date[j].year);
		}
	}
	
	return 0;
}
