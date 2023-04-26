#include<stdio.h>
char A[36] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char f(int a, int b){
	int i = 1;
	if(a < 0){
		printf("-");a = -1 * a;
	}
	if(a < b)printf("%c", A[a]);
	else{
		while(a >= i * b)i++;
		i--;printf("%c", A[i]);
		a = a - i*b;
		f(a, b);
	}
}
int main()
{
	int t, n, r, i;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d%d", &n, &r);
		f(n, r);
		printf("\n");
	}
	return 0;	
}