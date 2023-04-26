//1001
#include <stdio.h>
int main(){
	int T,i;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		int n,r,j=0,flag=0;
		scanf("%d %d",&n,&r);
		if(n<0){
			flag=-1;
			n=-n;
		}
		int ans[40];
		while(n>0){
			ans[j]=n%r;
			n=n/r;
			j++;
		}
		//printf("test");
		if(flag==-1){
			printf("-");
		}
		for(int q=j-1;q>=0;q--){
			if(ans[q]>=10){
				char temp=ans[q]+55;
				printf("%c",temp);
			}
			else{
				printf("%d",ans[q]);
			}
		}
		printf("\n");
	}
	return 0;
}