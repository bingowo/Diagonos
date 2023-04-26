#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long int_pow(int base,int exp);
int main(){
	int T;
	scanf("%d",&T);
	char s[60];
	long long n = 0;  
	int dif = 1;                   //重复字符数 
	int b[123];              //存储字符对应数字 
	for(int r = 0;r < sizeof(b)/sizeof(b[0]);r++){
			b[r] = -1;
	}
	for(int i = 0;i < T;i++){
		scanf("%s",s);
		for(int j = 0;j < strlen(s);j++){
			if(j == 0)
				b[s[j]] = 1;
			else if(b[s[j]] == -1 && dif == 1){
				b[s[j]] = 0;           
				dif++;
			}
			else if(b[s[j]] == -1){
				b[s[j]] = dif;
				dif++;
			}
		}
		if(dif < 2)
			dif = 2;
		for(int k = 0;s[k] != '\0';k++){
			n += b[s[k]] * int_pow(dif,strlen(s)-1-k);
		}
		printf("case #%d:\n",i);
		printf("%lld\n",n);
		for(int r = 0;r < sizeof(b)/sizeof(b[0]);r++){
			b[r] = -1;
		}
		dif = 1;
		n = 0;
	}                
	return 0;
}
long long int_pow(int base,int exp){
	long long  n = 1;
	for(int i = 0;i < exp;i++){
		n *= base; 
	}
	return n;
} 