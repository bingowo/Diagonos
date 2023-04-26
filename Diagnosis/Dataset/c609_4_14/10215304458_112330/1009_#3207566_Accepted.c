#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int gcd(int a,int b){
	return a%b?gcd(b,a%b):b;
} 
int main(){
	int t,x,y,q,len,i;
	unsigned char n;
	char c,s[130];
	scanf("%d",&t);
	getchar();
	while(t--){
		len=0;
		while((c=getchar())!='\n'){
			s[len++]=c;
		}
		x=y=0;
		for(i=0;i<len;++i){
			n=s[i];
			y+=8;
			while(n){
				x+=n&1;				
				n>>=1;
			}
		}
		q=gcd(x,y);
		printf("%d/%d\n",x/q,y/q);
	}
    return 0;
}