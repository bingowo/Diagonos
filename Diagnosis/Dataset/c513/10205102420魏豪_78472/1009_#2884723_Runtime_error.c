#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int GCD(int a,int b){
	if(b==0) return a;
	else return GCD(b,a%b);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int k=0;k<n;k++){
		char s[130];
		int a,count=0;
		gets(s);
		printf("%s",s);
		int len=strlen(s);
		for(int i=0;i<len;i++){
			a=s[i];
			while(a){
				a=a&(a-1);
				count++;
			}
		}
		int gcd;
		int x=8*len;
		gcd=GCD(count,x);
		printf("%d/%d\n",count/gcd,x/gcd);
	}
	return 0;
} 