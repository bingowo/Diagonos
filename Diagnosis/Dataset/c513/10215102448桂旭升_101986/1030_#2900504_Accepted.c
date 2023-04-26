#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
typedef struct {
	long long num;
	int fir;
} SCORE;
int cmp(const void *a, const void *b){
    int t; SCORE *pa = (SCORE *)a, *pb = (SCORE *)b;
    if((pb -> fir)!=(pa -> fir))return (pb -> fir)-(pa -> fir);
    else return (pa -> num)>(pb -> num)?1:-1;
}
SCORE* Input(int n)
{
    SCORE *a = (SCORE*)malloc(sizeof(SCORE)*n);
    int i, j = 0, len, k = 0, flag;
	long long temp;
    for(i = 0; i < n; i++){
        scanf("%lld", &a[i].num);
		
        if(a[i].num < 0)flag = -1;
		else flag = 1;
		temp = a[i].num * flag;
		if(temp == 0)a[i].fir = 0;
		else {
			while(temp != 0){
				a[i].fir = temp%10;
				temp /= 10;
			}
		}
	}
    return a; 
}
int main(){
	SCORE *A = NULL;
	int t, i, j, n, k;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d", &n);
		A = Input(n);
		qsort(A, n, sizeof(SCORE), cmp);
		printf("case #%d:\n", i);
		for(k = 0; k < n; k++){
			printf("%lld", A[k].num);
			if(k != n-1)printf(" ");
			else printf("\n");
		}
	}
	free(A);
	return 0;
}//printf("A[2] %d %d %d %d\n", A[2].num, A[2].score, A[2].win, A[2].lose);
		
	