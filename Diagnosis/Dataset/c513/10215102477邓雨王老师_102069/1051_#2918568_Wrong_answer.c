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
		char t[201];
		int j=0;
		int w=strlen(s)/3;
		int p=0;      //用来作为数组t的下标 
		while(j<w){
			long long sum=0;
			sum=s[3*j]*256*256+s[3*j+1]*256+s[3*j+2];
			while(sum>0){
				t[p]=base[sum%64];
				p++;
				sum=sum/64;
			}
			j++;
		}
		if(strlen(s)%3==1){
			long long sum=0;
			sum=s[strlen(s)-1]*16;
			t[p]=base[sum%64];
			p++;
			sum=sum/64;
			t[p++]=base[sum%64];
		} 
		else if(strlen(s)%3==2){
			long long sum=0;
			sum=(s[strlen(s)-1]+s[strlen(s)-2]*256)*4;
			t[p]=base[sum%64];
			p++;
			sum=sum/64;
			t[p++]=base[sum%64];
			sum=sum/64;
			t[p++]=base[sum%64];
		}
		t[p]='\0';
		int y;
		char c;
		for(y=0,j=strlen(t)-1;y<j;y++,j--) //反转
c=t[y],t[y]=t[j],t[j]=c;
		while(p<=3){
			t[p]='=';
			p++;
		}
		t[p]='\0';
		printf("case #%d:\n",i);
		printf("%s\n",t);}
	}