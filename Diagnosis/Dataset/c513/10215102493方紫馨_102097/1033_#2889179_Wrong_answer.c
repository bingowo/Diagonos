#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int day;
	char month[10];
	int mon_num;
	int year;
}Maya;
int MON_NUM(char s[]){
	if(s[0]=='p')
		return 1;
	if(s[0]=='n')
		return 2;
	if(s[0]=='z'){
		if(s[1]=='i')
			return 3;
		if(s[1]=='o')
			return 4;
		if(s[1]=='a')
			return 11;
	}
	if(s[0]=='t')
		return 5;
	if(s[0]=='x')
		return 6;
	if(s[0]=='y'){
		if(s[1]=='o')
			return 7;
		if(s[1]=='a')
			return 10;
	}
	if(s[0]=='m'){
		if(s[1]=='o')
			return 8;
		if(s[1]=='a')
			return 13;
		if(s[1]=='u')
		return 15;
	}
	if(s[0]=='c'){
		if(s[1]=='h')
			return 9;
		if(s[1]=='e')
			return 12;
		if(s[1]=='u')
			return 18;
	}
	if(s[0]=='k'){
		if(s[1]=='a')
			return 14;
		if(s[1]=='o')
			return 17;
	}
	if(s[0]=='u')
		return 19;
		
}
int cmp(const void* p1,const void* p2){
	Maya *a = (Maya*)p1;
	Maya *b = (Maya*)p2;
	if(a->year!=b->year)
		return a->year-b->year;
	if(a->mon_num!=b->mon_num)
		return a->mon_num-b->mon_num;
	return a->day-b->day;
}
int main()
{
	int T,N;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&N);
		Maya date[N];
		for(int j=0;j<N;j++){
			scanf("%d",&date[j].day);
			getchar();
			scanf("%s",&date[j].month);
			scanf("%d",&date[j].year);
			date[j].mon_num = MON_NUM(date[j].month);
		}
		qsort(date,N,sizeof(Maya),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<N;j++){
			printf("%d. %s %d\n",date[j].day,date[j].month,date[j].year);
		}
	}
	return 0;
}