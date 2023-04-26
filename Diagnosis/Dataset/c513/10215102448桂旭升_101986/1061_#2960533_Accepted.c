#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int A[128];
char B[128];
char C[62];
typedef struct {
	char s[16];
	long long con;
}SHENG;
long long f(char *p){
	int len = strlen(B), i = 0, j = 0; long long num = 0, res = 0;
	while(j < len){
		if(A[B[j]] == 0){
			A[B[j]]++; C[i++] = B[j]; num++;
		}
		j++;
	}
	C[i] = 0;
	if(num < 2)num = 2;
	j = 0; 
	while(j < len){
		for(i = 0; i < strlen(C); i++){
			if(B[j] == C[i]){
				if(i == 0)res = res * num + 1;
				else if(i == 1)res = res * num + 0;
				else res = res * num + i;
			}
		}
		j++;
	}
	return res;
}
int cmp(const void *a, const void *b){
	SHENG *pa = (SHENG*)a, *pb = (SHENG*)b;
	if(pa -> con != pb -> con)return (pa -> con > pb -> con);
	else return strcmp(pa ->s, pb -> s);
}
SHENG* Input(int n){
    SHENG *a = (SHENG*)malloc(sizeof(SHENG)*n);
    int i, j = 0, k = 0;//printf("%d\n", n);
	long long temp;
    for(i = 0; i < n; i++){
		for(j = 0; j < 128; j++){
			A[j] = '\0'; B[j] = '\0'; C[j] = '\0';
		}
        scanf("%s", &B);
		strcpy(a[i].s, B);
		a[i].con = f(B);
	}
    return a; 
}
int main()
{
	int t, i, j;
	SHENG *A = NULL;
	scanf("%d", &t);
	A = Input(t);
	qsort(A, t, sizeof(SHENG), cmp);
	for(i = 0; i < t; i++){
		printf("%s", A[i].s);
		if(i != t-1)printf("\n");
	}
	return 0;
}