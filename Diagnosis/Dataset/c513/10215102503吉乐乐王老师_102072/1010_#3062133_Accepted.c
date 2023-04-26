#include<stdio.h>
#include<string.h>
int main(){
	char s[500];
	int out[2000];
	scanf("%s",s);
	int len=strlen(s);
	int idx=0;
	for(int i=0;i+2<len;i+=3,idx+=10){
		int temp=(s[i]-'0')*100+(s[i+1]-'0')*10+s[i+2]-'0';
		for(int j=idx+9;j>=idx;j--){
			out[j]=temp%2;
			temp/=2;
		}
	}
	if(len%3==1){
		int temp=s[len-1]-'0';
		for(int j=idx+3;j>=idx;j--){
			out[j]=temp%2;
			temp/=2;
		}
		idx+=4;
	}
	else if(len%3==2){
		int temp=(s[len-2]-'0')*10+s[len-1]-'0';
		for(int j=idx+6;j>=idx;j--){
			out[j]=temp%2;
			temp/=2;
		}
		idx+=7;
	}
	int digitbit[10];
	int digit=len;
	for(int j=9;j>=0;j--){
		digitbit[j]=digit%2;
		digit/=2;
	}
	printf("0001");
	for(int i=0;i<10;i++){
		printf("%d",digitbit[i]);
	}
	for(int i=0;i<idx;i++){
		printf("%d",out[i]);
	}
}