#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{
	int year;
	char month[20];
	int day;
}DATE;
int index(char* s);
int cmp(const void* a,const void* b);
static char maya_month[20][10] = 
{
    "pop","no","zip", "zotz", "tzec", "xul",
    "yoxkin", "mol", "chen", "yax", "zac", 
    "ceh", "mac", "kankin", "muan", "pax", 
    "koyab", "cumhu","uayet"
};
int main(){
	int T;
	int num;
	char* s;
	char* t;
	char* dot;
	scanf("%d",&T);
	for(int i = 0;i < T;i++){
		scanf("%d",&num);
		DATE * p = (DATE*)malloc(sizeof(DATE) * (num + 10));
		int j;
		for(j = 0;j < num;j++){
			scanf("%d",&(p+j)->day);
			getchar();
			scanf("%s",(p+j)->month);
			scanf("%d",&(p+j)->year);
		}
		qsort(p,j,sizeof(p[0]),cmp);
		printf("case #%d:\n",i);
		for(int k = 0;k < j;k++){
			printf("%d%c %s %d\n",(p+k)->day,'.',(p+k)->month,(p+k)->year);
		}
		free(p);
	}
}
int index(char* s){
	int i;
	for(i = 0;i < 19;i++){
		if(strcmp(maya_month[i],s) == 0)	
			break;
	}
	return i;
}
int cmp(const void* a,const void* b){
	DATE* aa = (DATE*)a;
	DATE* bb = (DATE*)b;
	if(aa->year == bb->year){
		if(index(aa->month) == index(bb->month))
			return aa->day - bb->day;
		else
			return index(aa->month) - index(bb->month);
	}else
		return aa->year - bb->year;
}