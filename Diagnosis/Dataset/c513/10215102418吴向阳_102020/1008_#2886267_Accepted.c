#include <stdio.h>
#include <math.h>
int main(){
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		int x,y,diff=0;
		scanf("%d %d",&x,&y);
		int n=x^y;
		while(n){
			if(n&1==1) diff++;
			n=n>>1;
		}
		printf("%d\n",diff);
	}
	return 0;
}