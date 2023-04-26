#include<stdio.h>
#include<string.h>
int A[128];
char B[128];
char C[62];
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

int main()
{
	int t, i, j;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		for(j = 0; j < 500; j++){
			A[j] = '\0'; B[j] = '\0'; C[j] = '\0';
		}
		scanf("%s", &B);
		printf("case #%d:\n", i);
		printf("%lld", f(B));
		printf("\n");
	}
	return 0;
}