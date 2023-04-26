#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct{
	char date[11];
	char time[6];
	int size;
	char name[70];
}LIST;
int comp(const char *a);
int cmp1(const void* a,const void* b);
int cmp2(const void* a,const void* b);
int cmp3(const void* a,const void* b);

int main()
{
	int n;
	scanf("%d",&n);
	LIST *list;
	char front[5],order[6];
	while (n!=0){
	    list=(LIST*)malloc(n*sizeof(LIST));
		for (int i=0;i<n;i++){
			scanf("%s",list[i].date);
			scanf("%s",list[i].time);
			scanf("%d",&list[i].size);
			scanf("%s",list[i].name);
		}
		scanf("%s %s",front,order);
		int flag;
		flag=comp(order);
		if (flag==1){
			qsort(list,n,sizeof(LIST),cmp1);
		}
		else if (flag==2){
			qsort(list,n,sizeof(LIST),cmp2);
		}
		else {
			qsort(list,n,sizeof(LIST),cmp3);
		}
		for (int i=0;i<n;i++){
			printf("%s %s %16d %s\n",list[i].date,list[i].time,list[i].size,list[i].name);
		}
        free(list);
        scanf("%d",&n);
		if (n!=0){
			printf("\n");
		}
	}
	return 0;
}

int comp(const char *a)
{
	if (strcmp(a,"/NAME")==0){
		return 1;
	}
	else if (strcmp(a,"/SIZE")==0){
		return 2;
	}
	else{
		return 3;
	}
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
	else {
		return 1;
	}
}
int cmp3(const void* a,const void* b)
{
	LIST x,y;
	x=*(LIST*)a;
	y=*(LIST*)b;
	return strcmp(x.time,y.time);
}
