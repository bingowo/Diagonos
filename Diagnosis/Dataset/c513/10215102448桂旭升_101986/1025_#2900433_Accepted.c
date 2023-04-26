#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
typedef struct {
	char c[25];
	int num;
} SCORE;
int cmp(const void *a, const void *b){
    int t; SCORE *pa = (SCORE *)a, *pb = (SCORE *)b;
    if((pb -> num)!=(pa -> num))return (pb -> num)-(pa -> num);
    else return strcmp(pa -> c, pb -> c);
}
int count(const char c[]){
	int s[100] = {0};
	int len = strlen(c), i, num = 0;
	for(i = 0; i < len; i++){
		s[(int)c[i]]+=1;
	}
	for(i = 0; i < 100; i++){
		if(s[i] != 0)num++;
	}
	return num;
}
SCORE* Input(int n)
{
    SCORE *a = (SCORE*)malloc(sizeof(SCORE)*n);
    int i, j = 0, len, k = 0;
    char c;
    for(i = 0; i < n; i++){
        scanf("%s", &a[i].c);
		a[i].num = count(a[i].c);
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
			printf("%s\n", A[k].c);
		}	
	}
	free(A);
	return 0;
}//printf("A[2] %d %d %d %d\n", A[2].num, A[2].score, A[2].win, A[2].lose);
		
	