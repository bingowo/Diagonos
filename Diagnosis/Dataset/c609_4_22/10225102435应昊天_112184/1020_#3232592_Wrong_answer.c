#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int strnumcmp(const void* a,const void* b);
int main(){
	char p[101][39];
	int len = 0;
	while(scanf("%s",p[len++]) != EOF)
		;
	len--;
	qsort(p,len,sizeof(p[0]),strnumcmp);
	for(int i = 0;i < len;i++){
		printf("%s",p[i]);
		if(i != len-1)
			printf("%c",' '); 
	}
	return 0;
}
int strnumcmp(const void* a,const void* b){
	char * A = (char*)a;
	char * B = (char*)b;
	int num_A = 0,num_B = 0;
	int len_A = strlen(A);
	int len_B = strlen(B);
	for(int i = 0;i < len_A;i++){
		if(isdigit(A[i]))
			num_A = num_A * 10 + A[i] - '0';
	}
	for(int i = 0;i < len_B;i++){
		if(isdigit(B[i]))
			num_B = num_B * 10 + B[i] - '0';
	}
	if(num_A == num_B)
		return strcmp(A,B);
	else
		return num_A - num_B;
}