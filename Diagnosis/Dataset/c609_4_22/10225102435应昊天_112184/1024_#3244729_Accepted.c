#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int time_cmp(const void* a,const void* b);
int size_cmp(const void* a,const void* b);
int name_cmp(const void* a,const void* b);
typedef struct{
	int year;
	int month;
	int day;
	int hour;
	int min;
	int size;
	char name[126];
}file;
int main(){
	char c; 
	int T = 0;
	char std[5];
	int flag = 1;
	scanf("%d",&T);
	while(flag){
		file* p = (file*)malloc(sizeof(file) * T);
		for(int i = 0;i < T;i++){
			scanf("%d",&(p+i)->year);
			getchar();
			scanf("%d",&(p+i)->month);
			getchar();
			scanf("%d",&(p+i)->day);
			getchar();
			scanf("%d",&(p+i)->hour);
			getchar();
			scanf("%d",&(p+i)->min);
			scanf("%d",&(p+i)->size);
			scanf("%s",(p+i)->name);
		}	
		while((c = getchar()) != '/');
		scanf("%s",std);
		//printf("%s\n",std);
		if (strcmp(std,"TIME") == 0)
			qsort(p,T,sizeof(p[0]),time_cmp);
		else if(strcmp(std,"SIZE") == 0)
			qsort(p,T,sizeof(p[0]),size_cmp);
		else
			qsort(p,T,sizeof(p[0]),name_cmp);
		for(int i = 0;i < T;i++){
			printf("%d-%02d-%02d %02d:%02d %16d %s\n",(p+i)->year,(p+i)->month,(p+i)->day,
												(p+i)->hour,(p+i)->min,(p+i)->size,(p+i)->name);
		}
		free(p);
		scanf("%d",&T);
		//printf("%d",T);
		if(T != 0)
			printf("\n");
		else
			flag = 0;
	}
	return 0;
} 
int time_cmp(const void* a,const void* b){
	file* aa = (file*)a;
	file* bb = (file*)b;
	if(aa->year == bb->year){
		if(aa->month == bb->month){
			if(aa->day == bb->day){
				if(aa->hour == bb->hour){
					if(aa->min == bb->min)
						return(strcmp(aa->name,bb->name));
					else
						return aa->min - bb->min;
				}else
					return aa->hour - bb->hour;
			}else
				return aa->day - bb->day;
		}else
			return aa->month - bb->month;
	}else
		return aa->year - bb->year;
}

int size_cmp(const void* a,const void* b){
	file* aa = (file*)a;
	file* bb = (file*)b;
	if(aa->size == bb->size)
		return strcmp(aa->name,bb->name);
	else{
		if(aa->size > bb->size)
			return 1;
		else
			return -1; 
	}
}

int name_cmp(const void* a,const void* b){
	file* aa = (file*)a;
	file* bb = (file*)b;
	return strcmp(aa->name,bb->name);
}