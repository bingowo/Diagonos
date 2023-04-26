#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char date[11];
	char time[6];
	int size;
	char name[70];
}LIST;
int cmp1(const void* a,const void* b);
int cmp2(const void* a,const void* b);
int cmp3(const void* a,const void* b);

int main()
{
	int n;
	scanf("%d",&n);
	char order[10];
	while (n!=0){
		LIST list[100];
		int i;
		for (i=0;i<n;i++){
			scanf("%s %s %d %s",list[i].date,list[i].time,&list[i].size,list[i].name);
		}
		scanf("%s",order);
		flag=comp(order);
		if (strcmp(order,"LIST/NAME")==0){
			qsort(list,n,sizeof(LIST),cmp1);
		}
		else if (strcmp(order,"LIST/SIZE")==0){
			qsort(list,n,sizeof(LIST),cmp2);
		}
		else {
			qsort(list,n,sizeof(LIST),cmp3);
		}
		for (i=0;i<n;i++){
			printf("%s %s %16d %s\n",list[i].date,list[i].time,list[i].size,list[i].name);
		}
		printf("\n");
        scanf("%d",&n);
		
	}
	return 0;
}

int cmp1(const void* a,const void* b)
{
	LIST x,y;
	x=*(LIST*)a;
	y=*(LIST*)b;
	return strcmp(x.name,y.name);
}

int cmp2(const void* a,const void* b)
{
	LIST x,y;
	x=*(LIST*)a;
	y=*(LIST*)b;
	if (x.size<y.size){
		return -1;
	}
	else if(x.size>y.size) {
		return 1;
	}
	else{
		return strcmp(x.name,y.name);
	}
}
int cmp3(const void* a,const void* b)
{
	LIST x,y;
	x=*(LIST*)a;
	y=*(LIST*)b;
	if (strcmp(x.date,y.date)!=0){
		if (strcmp(x.time,y.time)!=0){
			return strcmp(x.name,y.name);
		}
		return strcmp(x.time,y.time);
	}
	return strcmp(x.date,y.date);
	
}
