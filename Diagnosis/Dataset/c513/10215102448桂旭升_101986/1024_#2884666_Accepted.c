#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
int w[10] = {0};
typedef struct {
	char num[13];
    int s;
    int sum;
} SCORE;
int ssum(int n){
	int i, sum = 0, a;
	for(i = 0; i < n; i++){
		scanf("%d", &a);
		sum += w[a - 1];
	}
	return sum;
}
int cmp(const void *a, const void *b){
    int t; SCORE *pa = (SCORE *)a, *pb = (SCORE *)b;
    if((pb -> sum) != (pa -> sum)) return (pb -> sum) - (pa -> sum);
    else return strcmp(pa -> num, pb -> num);
}
SCORE* Input(int n)
{
    SCORE *a = (SCORE*)malloc(sizeof(SCORE)*n);
    int i, j;
    for(i = 0; i < n; i++){
        scanf("%s%d", &a[i].num, &a[i].s);
    	a[i].sum = ssum(a[i].s);
    }
    return a; 
}
int main(){
	SCORE *A = NULL;
	int t, N, M, G, j, k, n = 0, i;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d%d%d", &N, &M, &G);
		for(j = 0; j < M; j++){
			 scanf("%d", &w[j]);
		}
		A = Input(N);//printf("A[0] %s %d %d\n", A[0].num, A[0].s, A[0].sum);
		qsort(A, N, sizeof(SCORE), cmp);
		for(k = 0; k < N; k++){
			if(A[k].sum >= G)n++;
		}
		printf("case #%d:\n", i);
		printf("%d\n", n);
		for(k = 0; k < N; k++){
			if(A[k].sum >= G)printf("%s %d\n", A[k].num, A[k].sum);
		}
		n = 0;
	}
	free(A);
	return 0;
}//printf("A[2] %d %d %d %d\n", A[2].num, A[2].score, A[2].win, A[2].lose);
		
	