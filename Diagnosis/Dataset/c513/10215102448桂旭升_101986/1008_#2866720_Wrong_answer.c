#include<stdio.h>
#include<string.h>
char A[2] = {'0', '1'};
char B[33];
int g(int a){
	int lens = strlen(B), i, c;
	for(i = 0; i < lens; i++){
		if(B[i] == '1')c++;
	}
	return c;
}
int f(int a){
	int i = 0, j = 0, lens = 0;
	for(j = 0; j < 33; j++){
		B[j] = 0;
	}
	if(a < 2){
		B[i] = A[a];B[i + 1] = 0;
	}
	else{
		while(a >= 2){
		B[i] = A[a%2];
		a = a/2;
		i++;
		}
		B[i] = A[a];
		B[i + 1] = 0;
	}
	return g(a);
}

int main()
{
	int t, n, r, i, j, s, a;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d%d", &n, &r);
		a = n^r;
		printf("%d", f(a)); 
		printf("\n");
		}
	return 0;
}