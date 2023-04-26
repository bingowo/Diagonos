#include <stdio.h>
int j;
void f(int n,int r,char s[]){
	if(n/r){
		f(n/r,r,s);
	}
	if(n%r>9){
		s[j++]=n%r-10+'A';
		s[j]='\0';
	}else{
		s[j++]=n%r+'0';
		s[j]='\0';
	}
}
int main(){
	int t,i;
	scanf("%d",&t);
	int n,r;
	char s[32];
	for(i=0;i<t;i++){
		scanf("%d%d",&n,&r);
		if(n<0){
			printf("-");n=-n;
		}
		if(n==0)printf("0");
		j=0;
		f(n,r,s);
		printf("%s\n",s);
	}
	return 0;
} 