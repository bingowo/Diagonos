#include <stdio.h>
int main(){
	int T,n,i,m;
    int stage[51];
	scanf ("%d",&T);
    stage[1]=1;stage[2]=2;stage[3]=4;stage[4]=8;
	for (i=0;i<T;i++){
		scanf ("%d",&n);
		printf("case #%d:\n",i);
        for (m=5;m<=n;m++){
            stage[m]=stage[m-1]+stage[m-2]+stage[m-3]+stage[m-4];
        }
		printf("%lld",stage[n]);
		
	}
	return 0;}