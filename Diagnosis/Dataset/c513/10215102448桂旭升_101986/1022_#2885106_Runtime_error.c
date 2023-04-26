#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
char y[1000000] = {'\0'};
typedef struct {
	char num[1000000];
    char s[1000000];
} SCORE;
int cmp(const void *a, const void *b){
    int t; SCORE *pa = (SCORE *)a, *pb = (SCORE *)b;
    if((pb -> s) != (pa -> s)) return strcmp(pa -> s, pb -> s);;
    if((pb -> num) != (pa -> num)) return strcmp(pb -> num, pa -> num);
}
SCORE* Input(int n)
{
    SCORE *a = (SCORE*)malloc(sizeof(SCORE)*n);
    int i, j = 0;
    char c;
    for(i = 0; i < n; i++){
        scanf("%s", &y);while((c = getchar()) != '@')a[i].num[j++] = c;
        a[i].num[j] = '\0';
		scanf("%s", &a[i].s);
    }
    return a; 
}
int main(){
	SCORE *A = NULL;
	int t, i, j;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		A = Input(t);
		//printf("A[0] %s %d %d\n", A[0].num, A[0].s, A[0].sum);
		qsort(A, t, sizeof(SCORE), cmp);
	}
	for(i = 0; i < t; i++){
		printf("%s@%s\n", A[i].num, A[i].s);
	}
	free(A);
	return 0;
}//printf("A[2] %d %d %d %d\n", A[2].num, A[2].score, A[2].win, A[2].lose);
		
	