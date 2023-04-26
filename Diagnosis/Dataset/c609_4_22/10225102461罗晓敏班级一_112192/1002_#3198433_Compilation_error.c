#include <stdio.h>
int j=0;
void f(int n,char s[]){
	if(n/2){
		f(n/2,s);
	}
	s[j++]=n%2+'0';
}
int main(){
	int t,i,k;
	scamf("%d",&t);
	int n,ret=1,cd=1;char s[32];
	for(i=0;i<t;i++){
		scanf("%d",&n);
		printf("case #%d:",i);
		f(n,s);
		for(k=0;k<j;){
			if(s[k]!=s[++k]){
				cd++;
			}else if(cd>ret){
				ret=cd;cd=1;
			}
		}
		printf("%d",ret);
	}
} 