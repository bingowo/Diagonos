#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char date[15];
	char time[6];
	int size;
	char id[100];
}Data;
int cmp_time(const void* p1,const void* p2){
	Data* a = (Data*) p1;
	Data* b = (Data*) p2;
	for(int i=0;i<10;i++){
		if(a->date[i]!=b->date[i])
			return a->date[i]-b->date[i];
	}
	for(int i=0;i<5;i++){
		if(a->time[i]!=b->time[i])
			return a->time[i]-b->time[i];
	}
	return strcmp(a->id,b->id);
}
int cmp_size(const void*p1,const void*p2){
	Data* a = (Data*)p1;
	Data* b = (Data*)p2;
	return a->size-b->size;
}
int cmp_name(const void* p1,const void* p2){
	Data* a = (Data*)p1;
	Data* b = (Data*)p2;
	return strcmp(a->id,b->id);
} 
int main()
{	
	int n=0;
	scanf("%d",&n);
	while(1){
	Data data[n];
	for(int i=0;i<n;i++){
		scanf("%s %s %d %s",data[i].date,data[i].time,&data[i].size,data[i].id);
	}
	char a[5],cmd[12];
	scanf("%s %s",a,cmd);
	if(cmd[1]=='N')
		qsort(data,n,sizeof(Data),cmp_name);
	if(cmd[1]=='S')
		qsort(data,n,sizeof(Data),cmp_size);
	if(cmd[1]=='T'){
		qsort(data,n,sizeof(Data),cmp_time);
	}
		
	for(int i=0;i<n;i++){
		printf("%s %s %16d %s\n",data[i].date,data[i].time,data[i].size,data[i].id);
	}
	scanf("%d",&n);
	if(n==0)
		break;
	}
	return 0;
} 