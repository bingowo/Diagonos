#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct field{
	char name[70], day[70], time[70];
	int size;
}t[110];
int cmp1(const void *a, const void *b){
	const struct field *pa = a, *pb = b;
	if(strcmp((*pa).name, (*pb).name) < 0)	return -1;
	return 1;	
}
int cmp2(const void *a, const void *b){
	const struct field *pa = a, *pb = b;
	if((*pa).size < (*pb).size)	return -1;
	else if((*pa).size > (*pb).size)	return 1;
	else{
		if(strcmp((*pa).name, (*pb).name) < 0)	return -1;
		return 1;
	}
}
int cmp3(const void *a, const void *b){
	const struct field *pa = a, *pb = b;
	if(strcmp((*pa).day, (*pb).day) < 0)	return -1;
	else if(strcmp((*pa).day, (*pb).day) > 0)	return 1;
	else{
		if(strcmp((*pa).time, (*pb).time) > 0)	return 1;
		else if(strcmp((*pa).time, (*pb).time) < 0) return -1;
		else{
			if(strcmp((*pa).name, (*pb).name) < 0)	return -1;
			return 1;
		}
	}
}
int main(){
	int n, i;
	char list[20];
	while(scanf("%d", &n)){
		if(n == 0)	break;
		for(i = 0; i < n; ++i){
			scanf("%s%s%d%s", &t[i].day, &t[i].time, &t[i].size, &t[i].name);
		}
		gets(list);
		gets(list);
		if(list[6] == 'N')	qsort(t, n, sizeof(t[0]), cmp1);
		else if(list[6] == 'S')	qsort(t, n, sizeof(t[0]), cmp2);
		else if(list[6] == 'T')	qsort(t, n, sizeof(t[0]), cmp3);
		for(i = 0; i < n; ++i)	printf("%s %s %16d %s\n", t[i].day, t[i].time, t[i].size, t[i].name);
		printf("\n");
	}
	return 0;
}