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

char s[20];

int cmpname(const void* a,const void* b){ 
	return strcmp(((RECORD*)a)->name, ((RECORD*)b)->name); 
}

int cmpsize(const void* a,const void* b){
	int t; RECORD *pa = (RECORD*)a, *pb = (RECORD*)b;
	if(pa -> size != pb -> size)return (pa -> size) - (pb -> size);
	else return cmpname(pa, pb);
}

int cmptime(const void* a,const void* b){ 
	int t, i; RECORD *pa = (RECORD*)a, *pb = (RECORD*)b;
	if(pa -> day != pb -> day)return strcmp(((RECORD*)a)->day, ((RECORD*)b)->day);
	else if(pa -> time != pb -> time)return strcmp(((RECORD*)a)->time, ((RECORD*)b)->time);
	else return cmpname(pa, pb);
	
}

RECORD* Input(int n)
{
    RECORD *a = (RECORD*)malloc(sizeof(RECORD)*n);
    int i, j = 0;
    for (i=0;i<n;i++) {//printf("1\n");
		scanf("%s %s %d %s", &a[i].day, &a[i].time, &a[i].size, &a[i].name);
	}
	
	return a; 
}

int main(){
	
	int t, i, j, n, k = 0;
	
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