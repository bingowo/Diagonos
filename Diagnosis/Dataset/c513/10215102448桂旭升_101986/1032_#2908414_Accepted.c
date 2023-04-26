#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct {
	int num[60];
} SCORE;
int cmp(const void *a, const void *b){
    int i = 0; SCORE *pa = (SCORE *)a, *pb = (SCORE *)b;
    while(1){
    	if((pa -> num[i]) != (pb -> num[i])) return (pa -> num[i]) < (pb -> num[i]) ? 1 : -1;
    	else if((pa -> num[i]) == -1 && (pb -> num[i]) == -1) return 0;
    	else {
    		i++;continue;
		}
		break;
	}
}
SCORE* Input(int n)
{
    SCORE *a = (SCORE*)malloc(sizeof(SCORE)*n);
    int i, j = 0;
    for(i = 0; i < n; i++){
        while(1){
        	scanf("%d", &a[i].num[j]);
        	if(a[i].num[j] == -1)break;
			else j++; 
		}
		j = 0;
    }
    return a; 
}
int main(){
	SCORE *A = NULL;
	int t, i, j, n, k = 0;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d", &n);
		A = Input(n);//printf("A[0] %d %d %d %d\n", A[0].num, A[0].score, A[0].win, A[0].lose);printf("A[2] %d %d %d %d\n", A[2].num, A[2].score, A[2].win, A[2].lose);
		qsort(A, n, sizeof(SCORE), cmp);
		for(j = 0; j < n; j++){
			while(A[j].num[k+1] != -1){
				printf("%d ", A[j].num[k++]);
			}
			printf("%d\n", A[j].num[k]);k = 0;	
		}
	}
	free(A);
	return 0;
} 