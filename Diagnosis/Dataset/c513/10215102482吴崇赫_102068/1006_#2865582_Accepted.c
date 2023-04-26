#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int Trans(char* s);

int main(){
	int T,x=0;
	scanf("%d\n",&T);
	while(x<T){
		char test[N]={'\0'};
		scanf("%s",test);
		printf("case #%d:\n%d\n",x,Trans(test));
		x++;
	}
	return 0;
}


int Trans(char* s){
	int n=strlen(s);
	int ret=0;
	for(int i=0;i<n;i++){
		ret*=3;
		if(s[i]=='-')ret-=1;
		else if(s[i]=='1')ret+=1;
		else ret=ret;
	}
	return ret;
}
