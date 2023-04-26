#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct STU
{
    unsigned char c[70];
    int store;
    char day[20];
    char time[10];
}stu;

int cmp_NAME(const void* _a,const void*_b)
{
    stu* a=(stu*)_a;
    stu* b=(stu*)_b;
    return (strcmp(a->c,b->c));
}

int cmp_SIZE(const void* _a,const void*_b)
{
    stu* a=(stu*)_a;
    stu* b=(stu*)_b;
    if(a->store!=b->store) return ((a->store)>(b->store)?1:-1);
    else return (strcmp(a->c,b->c));
}

int cmp_TIME(const void* _a,const void*_b)
{
    stu* a=(stu*)_a;
    stu* b=(stu*)_b;
    if(strcmp(a->day,b->day)!=0){
    	return (strcmp(a->day,b->day));
	}else if(strcmp(a->time,b->time)!=0){
		return (strcmp(a->time,b->time));
	}else{
		return (strcmp(a->c,b->c));
	}
}
int main(){
	int n,i;
	stu s[120];
	while(scanf("%d",&n)!=EOF&&n!=0){
		for(i=0;i<n;i++){
			scanf("%s %s %d %s",s[i].day,s[i].time,&s[i].store,s[i].c);
		}
		char a[15];
		gets(a);
		gets(a);
		if(strstr(a,"LIST /NAME")!=NULL) qsort(s,n,sizeof(stu),cmp_NAME);
		else if(strstr(a,"LIST /SIZE")!=NULL) qsort(s,n,sizeof(stu),cmp_SIZE);
		else if(strstr(a,"LIST /TIME")!=NULL) qsort(s,n,sizeof(stu),cmp_TIME);
		for(i=0;i<n;i++){
			printf("%s %s %d %s",s[i].day,s[i].time,s[i].store,s[i].c);
		}
		printf("\n");
	}	
} 