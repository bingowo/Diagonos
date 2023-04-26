#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[1005],ans[8005]; 
int l,stk[20];
void solve(int x,int p){
	int top=0;
	while(x) stk[++top]=x%2,x/=2;
	for(int i=1;i<=p-top;i++) putchar('0');
	while(top) putchar('0'+stk[top--]);
}
int main(){
	scanf("%s",s);
	l=strlen(s);
	printf("0001");
	solve(l,10);
	int res=0,cnt=0;
	for(int i=0;i<l;i++){
		res=res*10+s[i]-'0',cnt++;
		if(cnt==3||i==l-1) solve(res,cnt*3+1),res=0,cnt=0;
	}
	return 0;
}