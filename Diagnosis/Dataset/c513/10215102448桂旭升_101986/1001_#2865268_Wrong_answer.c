#include<stdio.h>
#include<string.h>
char A[36] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char B[33];
void reverse(char s[]) {
    int  R = strlen(s);
	if (R  <= 1)
		return ;
	else {
		char tmp = s[0];
		s[0] = s[R-1];
		s[R - 1] = '\0';
		reverse(s+1);
		s[R - 1] = tmp;
	}
}
char f(int a, int b){
	int i = 0;
	if(a < 0){
		printf("-");a = -1 * a;
	}
	if(a < b)B[i] = A[a];
	else{
		while(a >= b){
		B[i] = A[a%b];
		a = a/b;
		i++;;
		}
		B[i] = A[a];
	}
}

int main()
{
	int t, n, r, i, j, s;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d%d", &n, &r);
		f(n, r);
		reverse(B);
		s = strlen(B);
		for(j = 0; j < s; j++){
			printf("%c", B[j]); 
		}
		printf("\n");
	return 0;	
}
}