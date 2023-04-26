#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int int_pow(int base,int exp);
int main(){
	int T;
	scanf("%d",&T);
	char s[T][10000];
	for(int i = 0;i < T;i++){
		scanf("%s",s[i]);
	} 
	int n = 0;
	for(int i = 0;i < T;i++){
		char*t = (char*)malloc(sizeof(char)*32);
		strcpy(t,s[i]);
		for(int j = 0;j < strlen(t);j++){
			if(s[i][j] == '1')
				n += int_pow(3,strlen(t)-1-j);
			else if(s[i][j] == '-')
				n -= int_pow(3,strlen(t)-1-j);
			else
				continue;
		}
		printf("case #%d:\n",i);
		printf("%d\n",n);
		n = 0;
	}
	return 0;
}
int int_pow(int base,int exp){
	int n = 1;
	for(int i = 0;i < exp;i++){
		n *= base; 
	}
	return n;
} 