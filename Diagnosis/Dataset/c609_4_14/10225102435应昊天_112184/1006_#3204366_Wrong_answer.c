#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int int_pow(int base,int exp);
int cnt_len(char* s);
int main(){
	int T;
	scanf("%d",&T);
	char a[T][60];
	for(int i = 0;i < T;i++){
		scanf("%s",a[i]);
	}
	int n = 0;                  
	int dif = 1;                   //重复字符数 
	for(int i = 0;i < T;i++){ 
		int b[123] = {0};          //存储字符对应数字 
		for(int j = 0;a[i][j] != '\0';j++){
			if(j == 0)
				b[a[i][j]] = 1;
			else if(b[a[i][j]] == 0 && dif == 1){
				b[a[i][j]] = -1;            //与置零重复 
				dif++;
			}
			else if(b[a[i][j]] == 0){
				dif++;
				b[a[i][j]] = dif - 1;
			}
		}
		if(dif < 2)
			dif = 2;
		for(int k = 0;a[i][k] != '\0';k++){
			if(b[a[i][k]] == -1)
				b[a[i][k]] = 0;
			n += b[a[i][k]] * int_pow(dif,cnt_len(a[i])-1-k);
		}
		printf("case #%d:\n",i);
		printf("%d\n",n);
		n = 0;
		dif = 1;
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
int cnt_len(char* s){
	char*p;
	p = s;
	while(*p != '\0'){
		p++;
	}
		
	return p-s;
}