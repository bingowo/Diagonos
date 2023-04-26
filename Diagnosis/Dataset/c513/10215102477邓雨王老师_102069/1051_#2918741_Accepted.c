#include<stdio.h>
#include<string.h>
const int base[64] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 
	'w', 'x', 'y', 'z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '+', '/',
};
int main(){
	int chance;
	scanf("%d",&chance);
	int i;
	for(i=0;i<chance;i++){
		char s[101];
		scanf("%s",&s);
		char t[201]={'\0'};
		int j=0;
		int m=strlen(s)%3;
		int w=strlen(s)/3;
		int p=0;      //用来作为数组t的下标 
		while(j<w){
			long long sum=0;
			sum=s[3*j]*256*256+s[3*j+1]*256+s[3*j+2];
			t[4*j+3]=base[sum%64];
			p++;
			sum=sum/64;
			t[4*j+2]=base[sum%64];
			p++;
			sum=sum/64;
			t[4*j+1]=base[sum%64];
			p++;
			sum=sum/64;
			t[4*j]=base[sum%64];
			p++;
			sum=sum/64;
			j++;
		}
		if(strlen(s)%3==1){
			long long sum=0;
			sum=s[strlen(s)-1]*16;
			t[4*w+1]=base[sum%64];
			p++;
			sum=sum/64;
			t[4*w]=base[sum%64];
			p++;
		} 
		else if(strlen(s)%3==2){
			long long sum=0;
			sum=(s[strlen(s)-1]+s[strlen(s)-2]*256)*4;
			t[4*w+2]=base[sum%64];
			p++;
			sum=sum/64;
			t[4*w+1]=base[sum%64];
			p++;
			sum=sum/64;
			t[4*w]=base[sum%64];
			p++;
		}
		if(m==1){
			t[p++]='=';
			t[p++]='=';
		}
		else if(m==2){
			t[p++]='=';
		}
		t[p]='\0';
		printf("case #%d:\n",i);
		printf("%s\n",t);}
	}