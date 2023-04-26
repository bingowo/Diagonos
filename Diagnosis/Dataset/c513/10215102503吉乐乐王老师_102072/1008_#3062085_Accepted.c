#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int x,y;
		scanf("%d %d",&x,&y);
		int n=x^y;
		int ret=0;
		for(int i=0;i<64;i++){
			if(n&1)ret++;
			n=n>>1;
		}
		printf("%d\n",ret);
	}
}