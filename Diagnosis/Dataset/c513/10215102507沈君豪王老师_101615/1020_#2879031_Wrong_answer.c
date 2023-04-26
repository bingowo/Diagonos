#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char date[11];
	char time[6];
	int size;
	char name[128];
}File;

int cmpName(const void *a, const void *b)
{
	File *pa = (File *)a;
	File *pb = (File *)b;
	return strcmp(pa->name, pb->name);
}

int cmpSize(const void *a, const void *b)
{
	File *pa = (File *)a;
	File *pb = (File *)b;
	if(pa->size != pb->size){
		return pa->size - pb->size;	
	}else{
		return strcmp(pa->name, pb->name);	
	}
}

int cmpTime(const void *a, const void *b)
{
	File *pa = (File *)a;
	File *pb = (File *)b;
	if(strcmp(pa->date, pb->date) != 0){
		return strcmp(pa->date, pb->date);
	}else if(strcmp(pa->time, pb->time) != 0){
		return strcmp(pa->time, pb->time);
	}else{
		return strcmp(pa->name, pb->name);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	while(n != 0){
		File files[n];
		char instruction[5], temp[5];
		for(int i = 0 ;i < n ; i ++){
			scanf("%s %s %d %s", files[i].date, files[i].time, &files[i].size, files[i].name);
		}
		scanf("%s %s", temp, instruction);
		if(strcmp(instruction, "/NAME") == 0){
			qsort(files, n, sizeof(File), cmpName);
		}else if(strcmp(instruction, "/SIZE") == 0){
			qsort(files, n, sizeof(File), cmpSize);
		}else if(strcmp(instruction, "/TIME") == 0){
			qsort(files, n, sizeof(File), cmpTime);
		}
		for(int i = 0 ; i < n ; i ++){
			printf("%s %s %16d %s\n", files[i].date, files[i].time, files[i].size, files[i].name);
		}
		scanf("%d", &n);
	}
	
	return 0;
}