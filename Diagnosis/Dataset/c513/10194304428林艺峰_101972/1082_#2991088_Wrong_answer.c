#include<stdio.h>
#include<string.h>
char str_A[510], str_B[510];
int int_A[510], int_B[510], int_C[510], frac_A[510], frac_B[510], frac_C[510];
int max(int x, int y){
	return x > y ? x : y;
}
int main(){
	int n, i;
	scanf("%s%s%d", &str_A, &str_B, &n);
	int la = strlen(str_A), lb = strlen(str_B), flag = 0;
	int len_int_A = 0, len_int_B = 0, len_frac_A = 0, len_frac_B = 0;
	for(i = 0; i < la; ++i){
		if(flag){
			frac_A[len_frac_A++] = str_A[i] - '0';
		}
		else if(str_A[i] == '.'){
			flag = 1;
		}
		else{
			int_A[len_int_A++] = str_A[i] - '0';
		}
	}
	flag = 0;
	for(i = 0; i < lb; ++i){
		if(flag){
			frac_B[len_frac_B++] = str_B[i] - '0';
		}
		else if(str_B[i] == '.'){
			flag = 1;
		}
		else{
			int_B[len_int_B++] = str_B[i] - '0';
		}
	}
	for(i = 0; i < len_int_A / 2; ++i){
		int x = int_A[i];
		int_A[i] = int_A[len_int_A-1-i];
		int_A[len_int_A-1-i] = x;
	}
	for(i = 0; i < len_int_B / 2; ++i){
		int x = int_B[i];
		int_B[i] = int_B[len_int_B-1-i];
		int_B[len_int_B-1-i] = x;
	}
	int temp_frac = 0, temp_int = 0, len_frac_C = max(len_frac_A, len_frac_B), len_int_C = max(len_int_A, len_int_B);
	for(i = len_frac_C - 1; i >= 0; --i){
		frac_C[i] = (frac_A[i] + frac_B[i] + temp_frac) % 10;
		temp_frac = (frac_A[i] + frac_B[i] + temp_frac) / 10;
	}
	if(temp_frac != 0){
		temp_int += 1;
	}
	if(frac_C[n] >= 5){
		frac_C[n-1] += 1;
		temp_frac = 0;
		for(i = n - 1; i >= 0; --i){
			int x = (frac_C[i] + temp_frac) / 10;
			frac_C[i] = (frac_C[i] + temp_frac) % 10;
			temp_frac = x;
		}
		if(temp_frac != 0){
			temp_int += 1; 
		}
	}
	for(i = 0; i < len_int_C; ++i){
		int_C[i] = (int_A[i] + int_B[i] + temp_int) % 10;
		temp_int = (int_A[i] + int_B[i] + temp_int) / 10;
	}
	if(temp_int != 0){
		int_C[len_int_C++] = temp_int;
	}
	for(i = len_int_C - 1; i >= 0; --i){
		printf("%d",int_C[i]);
	}
	if(len_int_C == 0){
		printf("0");
	}
	printf(".");
	for(i = 0; i < n; ++i){
		printf("%d", frac_C[i]);
	}
	return 0;
}