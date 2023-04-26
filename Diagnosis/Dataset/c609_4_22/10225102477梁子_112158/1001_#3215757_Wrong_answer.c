#include<stdio.h>
#include<stdlib.h>
void solve(){
	int i=0,m,N,n;
	scanf("%d%d",&n,&m);
	char s[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	N=n;
	char ss[100];
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
	for(;i>0;i--){
		printf("%c",ss[i]);
		printf("\n"); 
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		solve();
	}
	return 0;
 } 