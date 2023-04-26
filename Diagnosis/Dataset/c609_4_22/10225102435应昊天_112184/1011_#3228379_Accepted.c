#include<stdio.h>
#include<string.h>
int main(){
	char s[30];
	scanf("%s",s);
	long long A = 0,B = 0,C = 1;
	if(strchr(s,'.') == NULL){
		for(int i = 0;i < strlen(s);i++){
			A = A * 3 + (s[i] - '0' == 2 ? -1 : s[i] - '0'); 
		}
		printf("%lld",A);
	}else{
		char* p = strchr(s,'.');
		char* q;
		for(q = s;q < p;q++){
			A = A * 3 + (*q - '0' == 2 ? -1 : *q - '0'); 
		}
		for(p = p + 1;p < s + strlen(s);p++){
			C *= 3;
			B = B * 3 + (*p - '0' == 2 ? -1 : *p - '0'); 
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
			printf("%lld %lld",B,C);
		else
			printf("%lld %lld %lld",A,B,C);
	}
	return 0;
}