#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int int_pow(int base,int exp);
static char tab[] = "0123456789ABCDEF"; 
int main(){
	int A,B;
	char s[32];
	scanf("%d %s %d",&A,s,&B);
	for(int i = 0;i < sizeof(s)/sizeof(s[0]);i++){
		if(s[i]>='a'&&s[i]<='f')
			s[i] += ('A' - 'a');   
	}
	int n = 0;                              
	for(int j = strlen(s)-1;j >= 0;j--){
		//printf("j:%d\n",j);
		if(s[j]>='A'&&s[j]<='F')
			n += (s[j] - 'A' + 10) * int_pow(A,strlen(s)-1-j);
		else
			n += (s[j] - '0') * int_pow(A,strlen(s)-1-j);
	}                                          //to decimal
	//printf("%d\n",n);
	if(n == 0)
		printf("%d",n);
	int k = 0;                                // n!=0
	char* t = (char*)malloc(sizeof(char)*32);
	while(n > 0){
		if(B < 10 || n % B < 10){
			t[k++] = n % B + '0';
		}
		else{
			t[k++] = n % B - 10 + 'A';
		}
		n /= B;
	}
	t[k] = '\0';
	for(int r = strlen(t)-1;r >= 0;r--){
		printf("%c",t[r]);
	}
	free(t);
	return 0;
}

int int_pow(int base,int exp){
	int n = 1;
	for(int i = 0;i < exp;i++){
		n *= base; 
	}
	return n;
} 