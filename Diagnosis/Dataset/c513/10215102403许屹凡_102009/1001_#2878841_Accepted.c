#include <stdio.h>
int main(){
	int T,i;
	char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	scanf("%d",&T);
	for(i=0; i<T; i++){
		int n,r;
		scanf("%d%d",&n,&r); int sign=1;
		if(n<0) {sign=-1; n=-n;	}
		int j=0; int ans[32];
		do{
			int b=n%r;
			ans[j++]=table[b];
			n=n/r;

		} while(n);
	if (sign<0) printf("-");
	for(j=j-1;j>=0;j--) printf("%c",ans[j]);
	printf("\n");
}
	return 0;
}
