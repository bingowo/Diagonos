#include <stdio.h>
int j;
void f(int n,char s[]){
	if(n/2){
		f(n/2,s);
	}
	s[j++]=n%2+'0';
	s[j]='\0';
}
int main(){
	int t,i,k;
	scanf("%d",&t);
	int n,ret,cd;char s[32];
	for(i=0;i<t;i++){
		j=0;ret=1;cd=1;
		scanf("%d",&n);
		printf("case #%d:\n",i);
		f(n,s);
		for(k=0;k<j-1;){
			if(s[k]!=s[++k]){
				cd++;
			}else if(cd>ret){
				ret=cd;cd=1;
			}
		}
		printf("%d\n",cd>ret?cd:ret);
	}
} 