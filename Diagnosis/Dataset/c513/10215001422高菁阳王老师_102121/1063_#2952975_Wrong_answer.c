#include <stdio.h>
#include <stdlib.h>
long long swap(long long *a,long long *b){
	long long t;
	t=*a;
	*a=*b;
	*b=t;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long long x,y,ans=0;
	scanf("%lld %lld",&x,&y);
	if(x<y) swap(&x,&y);
	while(x>y){
		ans+=4*y*(x/y);
		x=x%y;
		if(x<y) swap(&x,&y);
	}
	printf("%lld",ans);
	return 0;
}