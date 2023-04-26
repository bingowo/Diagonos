#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

typedef struct {
	long long ce;
    long long ding;
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
    int i;
	long long r, h;
    for(i = 0; i < n; i++){
        scanf("%lld%lld", &r, &h);
        a[i].ding = r*r;
        a[i].ce = 2*r*h;//printf("%d %d\n", A[1].ding, A[1].ce);
    }
    return a; 
}

int main(){
	SCORE *A = NULL;
	long long res = 0;
	long long t = 0;
	int i, j, n, m;
	scanf("%d%d", &n, &m);
	A = Input(n);
	
	qsort(A, n, sizeof(SCORE), cmpding);
	if(m == n){
		for(i = 0; i < m; i++){
			res += A[i].ce;
		}
		res += A[m - 1].ding;
	}
	else if(m == 1){
		for(i = 0; i < n; i++){
			if((A[i].ce + A[i].ding) > res)res = A[i].ce + A[i].ding;
		}
	}
	else{
		for(i = n - 1; i >= m - 1; i--){
			qsort(A, i, sizeof(SCORE), cmpce);
			for(j = 0; j < m - 1; j++){
				t += A[j].ce;
			}
			t = A[i].ding + A[i].ce + t;//printf("%lld\n", t);
			if(t > res){
				res = t;
			}
			qsort(A, i, sizeof(SCORE), cmpding);
			t = 0;
		}
	}
	printf("%lld\n", res);
	free(A);
	return 0;
}//printf("A[2] %d %d %d %d\n", A[2].num, A[2].score, A[2].win, A[2].lose);
		
	