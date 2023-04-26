#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long
int n,r,top; 
char s[2000005];
int main() {
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		
		if(i==0) putchar('0'),s[0]=0;
		else{
			int pos=1<<(i-1);
			for(int j=0;j<pos;j++) printf("%c",s[j]=='1'?'0':'1'),s[j+pos]=s[j]=='1'?'0':'1';
		}
	}
	return 0;
}