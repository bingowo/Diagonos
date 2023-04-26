#include <stdio.h>
int j=0;
void f(int n,int r,char s[]){
	if(n/r){
		f(n/r,r,s);
	}
	if(n%r>'9'){
		s[j++]=n%r-10+'A';
	}else s[j++]=n%r+'0';
}
int main(){
	int t,i;
	scanf("%d",&t);
	int n,r;
	char s[32];
	for(i=0;i<t;i++){
		scanf("%d%d",&n,&r);
		f(n,r,s);
		printf("%s",s);
	}
	return 0;
} 