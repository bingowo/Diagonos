#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct {
int val; //表示日期“大小”的值
int y; //年
int d; //日
char m[7]; //玛雅历的月份
}RECORD;

int cmp(const void* a,const void* b){ 
	return((RECORD*)a)->val - ((RECORD*)b)->val; 
}

int month2idx(char* m){ 
	int i;
	static char* month[] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
	for (i=0;;i++) if (!strcmp(m,month[i])) return i; 
}

RECORD* Input(int n)
{
    RECORD *a = (RECORD*)malloc(sizeof(RECORD)*n);
    int i, j = 0;
    for (i=0;i<n;i++) {//printf("1\n");
		scanf("%d.%s %d", &a[i].d, &a[i].m, &a[i].y);
		a[i].val = a[i].y*1000+month2idx(a[i].m)*20+a[i].d;
	}
	return a; 
}

int main(){
	
	int t, i, j, n, k = 0;
	scanf("%d", &t);
	for(j = 0; j < t; j++){
		RECORD *A = NULL;
		scanf("%d", &n);
		A = Input(n);
		qsort(A, n, sizeof(RECORD), cmp);
		printf("case #%d:\n", j);
		for (i=0;i<n;i++)
			printf("%d. %s %d\n",A[i].d,A[i].m,A[i].y);
		free(A);
	}
	
	return 0;
} 