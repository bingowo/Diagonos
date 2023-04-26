#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct {
	char day[20];
	char time[10];
	int size;
	char name[64];
}RECORD;

int cmpname(const void* a,const void* b){ 
	return (int)strcmp(((RECORD*)a)->name, ((RECORD*)b)->name); 
}

int cmpsize(const void* a,const void* b){
	int t; RECORD *pa = (RECORD*)a, *pb = (RECORD*)b;
	if(pa -> size != pb -> size)return (pa -> size) < (pb -> size)?-1:1;
	else return cmpname(pa, pb);
}

int cmptime(const void* a,const void* b){ 
	int t, i; RECORD *pa = (RECORD*)a, *pb = (RECORD*)b;
	if(strcmp(pa->day, pb->day) != 0)return strcmp(pa->day, pb->day);
	if(strcmp(pa->time, pb->time) != 0)return strcmp(pa->time, pb->time);
	return cmpname(pa, pb);
	
}

RECORD* Input(int n)
{
    RECORD *a = (RECORD*)malloc(sizeof(RECORD)*n);
    int i;
    for(i = 0; i < 20; i++){
    	a->day[i] = '\0';
	}
	for(i = 0; i < 10; i++){
    	a->time[i] = '\0';
	}
	for(i = 0; i < 64; i++){
    	a->name[i] = '\0';
	}
    for (i=0;i<n;i++) {//printf("1\n");
		scanf("%s %s %d %s", &a[i].day, &a[i].time, &a[i].size, &a[i].name);
		//printf("%s %s %d %s\n", a[i].day, a[i].time, a[i].size, a[i].name);
	}
	
	return a; 
}

int main(){
	
	int i, n;
	char s[20];
	while(1){
		scanf("%d", &n);
		if(n == 0)break;
		RECORD *A = NULL;
		A = Input(n);
		gets(s);gets(s);
		if(strcmp(s, "LIST /NAME") == 0)qsort(A, n, sizeof(RECORD), cmpname);
		if(strcmp(s, "LIST /TIME") == 0)qsort(A, n, sizeof(RECORD), cmptime);
		if(strcmp(s, "LIST /SIZE") == 0)qsort(A, n, sizeof(RECORD), cmpsize);
		for (i=0;i<n;i++)
			printf("%s %s %16d %s\n", A[i].day, A[i].time, A[i].size, A[i].name);
		printf("\n");
		free(A);
	}
	return 0;
} 