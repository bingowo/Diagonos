#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int num;
    int score;
    int win;
    int lose;
} SCORE;
int cmp(const void *a, const void *b){
    int t; SCORE *pa = (SCORE *)a, *pb = (SCORE *)b;
    if((pb -> score) != (pa -> score)) return (pb -> score) - (pa -> score);
    if((pb -> win) != (pa -> win)) return (pb -> win) - (pa -> win);
    if((pa -> lose) != (pb -> lose)) return (pa -> lose) - (pb -> lose);
    if((pa -> num) != (pb -> num)) return (pa -> num) - (pb -> num);
}
SCORE* Input(int n)
{
    SCORE *a = (SCORE*)malloc(sizeof(SCORE)*n);
    int i;
    for(i = 0; i < n; i++){
        a[i].num = i + 1;a[i].score = 0;a[i].win = 0;a[i].lose = 0;
        
    }
    return a; 
}
int main(){
	SCORE *A = NULL;
	int n, m, i, a, b, c;
	scanf("%d %d", &n, &m);
	A = Input(n);
	do{
		for(i = 0; i < m; i++){
			scanf("%d %d %d", &a, &b, &c);
			if(c == 1){
				A[a - 1].score += 3;A[a - 1].win += 1;
				A[b - 1].score += -1;A[b - 1].lose += 1;
			}
			if(c == 0){
				A[a - 1].score += 1;
				A[b - 1].score += 1;
			}
			if(c == -1){
				A[a - 1].score += -1;A[a - 1].lose += 1;
				A[b - 1].score += 3;A[b - 1].win += 1;
			}
		}//printf("A[0] %d %d %d %d\n", A[0].num, A[0].score, A[0].win, A[0].lose);printf("A[2] %d %d %d %d\n", A[2].num, A[2].score, A[2].win, A[2].lose);
		qsort(A, n, sizeof(SCORE), cmp);
		for(i = 0; i < n; i++){
			printf("%d", A[i].num);
			if(i != n - 1)printf(" ");
			else printf("\n");
		}
		scanf("%d %d", &n, &m);
		A = Input(n);
	}while((m + n) != 0);
	free(A);
	return 0;
} 