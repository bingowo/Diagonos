#include <stdio.h>
void f(int n,int r){
	if(n/r){f(n/r,r);}
	if(n%r>9)printf("%c",n%r+'A'-10);
	else printf("%c",n%r+'0');
}
int main(){
	int t,i;scanf("%d",&t);
	for(i=0;i<t;i++){
	 int n,r;
		scanf("%d%d",&n,&r);
		if(n<0){printf("-");n=-n;}
		if(n==0){printf("0\n");continue;}
		f(n,r);
		printf("\n");
	}
	return 0;
} 
