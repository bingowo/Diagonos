#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int T,n,m;
char s[2005];
void solve(char c){
	m+=8;
	while(c) n+=c%2,c/=2;
}
int gcd(int x,int y){
	if(x%y==0) return y;
	else return gcd(y,x%y);
}
int main(){
	scanf("%d\n",&T);
	while(T--){
		n=0,m=0,gets(s);
		for(int i=0;s[i]!='\0';i++) solve(s[i]);
		if(n==m) puts("1");
		else if(n==0) puts("0");
		else printf("%d/%d\n",n/gcd(m,n),m/gcd(m,n));
	} 
	return 0; 
} 