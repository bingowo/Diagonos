#include<stdio.h>
#include<string.h>
int main(){
	char s[30];
	scanf("%s",s);
	int A = 0,B = 0,C = 1;
	if(strchr(s,'.') == NULL){
		for(int i = 0;i < strlen(s);i++){
			A = A * 3 + (s[i] - '0' == 2 ? -1 : s[i] - '0'); 
		}
		printf("%d",A);
	}else{
		char* p = strchr(s,'.');
		char* q;
		for(q = s;q < p;q++){
			A = A * 3 + (*q - '0' == 2 ? -1 : *q - '0'); 
		}
		int cnt = s + strlen(s) - 1 - p;
		for(int i = 0;i < cnt;i++){
			C *= 3;
		}
		for(int j = strlen(s) - 1;j > p - s;j--){
			B = B * 3 + (s[j] - '0' == 2 ? -1 : s[j] - '0'); 
		}
		if(A > 0 && B < 0){
			A--;
			B += C;
		}
		if(A < 0 && B > 0){
			A++;
			B -= C;
			B = -B;
		}
		if(A == 0)
			printf("%d %d",B,C);
		else
			printf("%d %d %d",A,B,C);
	}
	return 0;
}