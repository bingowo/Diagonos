#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	char day[4];
	char month[7];
	int year;
}DATE;

int mon(char s[])
{
	if(strlen(s)==5){
		if(s[0]=='k'){
			return 17;
		}
		if(s[0]=='c'){
			return 18;
		}
		else{
			return 19;
		}
	}
	if(strlen(s)==6){
		if(s[0]=='y'){
			return 7;
		}
		return 14;
	}
	if(strlen(s)==4){
		if(s[0]=='z'){
			return 4;
		}
		if(s[0]=='t'){
			return 5;
		}
		if(s[0]=='c'){
			return 9;
		}
		return 15;
	}
	if(strlen(s)==2){
		return 2;
	}
	else{
		if(s[0]=='x'){
			return 6;
		}
		if(s[0]=='y'){
			return 10;
		}
		if(s[0]=='c'){
			return 12;
		}
		if(s[0]=='p'){
			if(s[1]=='o'){
				return 1;
			}
			else{
				return 16;
			}
		}
		if(s[0]=='z'){
			if(s[1]=='i'){
				return 3;
			}
			return 11;
		}
		else{
			if(s[1]=='o'){
				return 8;
			}
			return 13;
		}
	}
}

int cmp(const void* a,const void* b)
{
	DATE x,y;
	x=*(DATE*)a;
	y=*(DATE*)b;
	if(x.year<y.year){
		return -1;
	}
	if(x.year>y.year){
		return 1;
	}
	else{
		int m,n;
		m=mon(x.month);
		n=mon(y.month);
		if(m<n){
			return -1;
		}
		if(m>n){
			return 1;
		}
		else{
			int day1=0,day2=0;
			for (int i=0;i<strlen(x.day)-1;i++){
				day1=day1*10+x.day[i]-'0';
			}
			for (int i=0;i<strlen(y.day)-1;i++){
				day2=day2*10+y.day[i]-'0';
			}
			return day1-day2;
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	int i,N;
	DATE *date;
	for (i=0;i<T;i++){
		scanf("%d",&N);
		date=(DATE*)malloc(N*sizeof(DATE));
		int j;
		for (j=0;j<N;j++){
			scanf("%s %s %d",date[j].day,date[j].month,&date[j].year);
		}
		qsort(date,N,sizeof(date[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<N;j++){
			printf("%s %s %d\n",date[j].day,date[j].month,date[j].year);
		}
		free(date);
	}
	return 0;
}