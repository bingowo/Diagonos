#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

typedef struct {
	int ce;
    int ding;
} SCORE;

int cmpding(const void *a, const void *b){
    int t; SCORE *pa = (SCORE *)a, *pb = (SCORE *)b;
    return pa -> ding > pb -> ding?1:-1;
}

int cmpce(const void *a, const void *b){
    int t; SCORE *pa = (SCORE *)a, *pb = (SCORE *)b;
    return pb -> ce > pa -> ce ? 1 : -1;
}

SCORE* Input(int n)
{
    SCORE *a = (SCORE*)malloc(sizeof(SCORE)*n);
    int i, r, h;
    char c;
    for(i = 0; i < n; i++){
        scanf("%d%d", &r, &h);
        a[i].ding = r*r;
        a[i].ce = 2*r*h;
    }
    return a; 
}

int main(){
	SCORE *A = NULL;
	int res = 0;
	int t = 0, i, j, n, m;
	scanf("%d%d", &n, &m);
	A = Input(n);
	
	qsort(A, n, sizeof(SCORE), cmpding);
	for(i = n - 1; i >= m; i--){
		qsort(A, i, sizeof(SCORE), cmpce);//printf("%d %d\n", A[0].ding, A[0].ce);printf("%d %d\n", A[1].ding, A[1].ce);
		for(j = 0; j < m - 1; j++){
			t += A[j].ce;
		}
		if((A[i].ding + A[i].ce + t) > res)res = (A[i].ding + A[i].ce + t);
		qsort(A, i, sizeof(SCORE), cmpding);
		t = 0;
	}
	printf("%d\n", res);
	free(A);
	return 0;
}//printf("A[2] %d %d %d %d\n", A[2].num, A[2].score, A[2].win, A[2].lose);
		
	