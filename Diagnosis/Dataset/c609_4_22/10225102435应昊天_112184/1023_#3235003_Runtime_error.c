#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{
	int year;
	int month;
	int day;
	char *maya;
}DATE;
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
		DATE * p = (DATE*)malloc(sizeof(DATE) * num);
		int j;
		for(j = 0;j < num;j++){
			s = (char*)malloc(sizeof(char)*20);
			t = (char*)malloc(sizeof(char)*20);
			scanf("%[^\n]",s);
			strcpy(p[j].maya,s);
			dot = strchr(s,'.');
			p[j].day  = 0;
			p[j].year = 0;
			while(s < dot){
				p[j].day =  p[j].day * 10 + *s - '0';
				s++;
			}
			if(isspace(*s))
				s++;
			while(!isspace(*s)){
				*t++ = *s++;
			}
			*t = '\0';
			for(int k = 0;k < 20;k++){
				if(strcmp(maya_month[k],t) == 0)
					p[j].month = k;
			}
			if(isspace(*s))
				s++;
			while(*s){
				p[j].year = p[j].year * 10 + *s - '0';
			}
			free(s);
			free(t);
		}
		qsort(p,j,sizeof(p[0]),cmp);
		printf("case #%d:\n",i);
		for(int k = 0;k < j;k++){
			printf("%s\n",p[k].maya);
		}
		free(p);
	}
}
int cmp(const void* a,const void* b){
	DATE* aa = (DATE*)a;
	DATE* bb = (DATE*)b;
	if(aa->year == bb->year){
		if(aa->month == bb->month)
			return aa->day - bb->day;
		else
			return aa->month - bb->month;
	}else
		return aa->year - bb->year;
}