#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	int cas=0;
	while(t--){
		int n;
		scanf("%d",&n);
		int bin[32];
		for(int i=31;i>=0;i--){
			bin[i]=n%2;n/=2;
		}
		int idx=0;
		while(bin[idx]==0)idx++;
		int ret=1;
		int cur=1;
		for(int i=idx+1;i<32;i++){
			if(bin[i]!=bin[i-1])cur+=1;
			else {
				ret=cur>ret?cur:ret;
				cur=1;
			}
		}
		ret=cur>ret?cur:ret;
		printf("case #%d:\n%d\n",cas++,ret);
	}
}