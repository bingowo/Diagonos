#include<stdio.h>
#include<stdlib.h>
void solve(){
	int n,m,N,i=0;
	scanf("%d%d",&n,&m);
	char s[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	N=n;
	char ss[200];
	if(n<0){
		n=-n;
	}
	for(;n/m!=0;i++){
		ss[i]=s[n%m];
		n=n/m;
	}
	ss[i]=s[n];
	if(N<0){
		printf("-");
	}
	for(;i>=0;i--){
		printf("%c\n",ss[i]);
	}
}
int main()
{
	int t;
	scanf("%d\n",&t);
	for(;t>0;t--){
		solve();
	}
	return 0;
 } 