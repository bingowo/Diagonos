#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data{
	long long size;
	char time[20];
	char name[64];
};

int cmp_TIME(const void* p1,const void* p2){
	struct data* a = (struct data*)p1;
	struct data* b = (struct data*)p2;
	if(strcmp(a->time,b->time)!=0)
	    return strcmp(a->time,b->time);
	return strcmp(a->name,b->name);
}

int cmp_SIZE(const void* p1,const void* p2){
	struct data* a = (struct data*)p1;
	struct data* b = (struct data*)p2;
	if(a->size>b->size)
		return 1;
	return -1;
}

int cmp_NAME(const void* p1,const void* p2){
	struct data* a = (struct data*)p1;
	struct data* b = (struct data*)p2;
	return strcmp(a->name,b->name);
}

int main()
{
	int n;
	while(scanf("%d",&n)&&n!=0){
	char yy[20],hm[10];
	struct data file[110];
	for(int i=0;i<n;i++){
		scanf("%s%s%lld%s",yy,hm,&file[i].size,file[i].name);
		sprintf(file[i].time,"%s %s",yy,hm);
	}
	char cmd[15];
	scanf("%s%s",hm,cmd);
	if(cmd[1]=='T'){
		qsort(file,n,sizeof(file[0]),cmp_TIME);
	}
	if(cmd[1]=='S'){
		qsort(file,n,sizeof(file[0]),cmp_SIZE);
	}
	if(cmd[1]=='N'){
		qsort(file,n,sizeof(file[0]),cmp_NAME);
	}
	for(int i=0;i<n;i++){
		printf("%s %16d %s\n",file[i].time,file[i].size,file[i].name);
	}
	printf("\n");
	}
	
	return 0;
 } 
 