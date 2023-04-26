#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	int T;
	scanf("%d",&T);
	int k=0;
	while(T--){
		int ans[1005]={1};
		int m,n;
		scanf("%d %d",&m,&n);
		int carry=0;
		int w=0;
		while(n--){
			int i=0;
			while(ans[i]||carry){
				int temp=ans[i]*m+carry;
				ans[i]=temp%10;
				carry=temp/10;
				i++;
			}
		}
		int i=1004;
		printf("case #%d:\n",k++);
		for(;i>=0;i--){
			if(ans[i]!=0)
			break;
		}
		for(;i>=0;i--)
		printf("%d",ans[i]);
		printf("\n");
	}
	
	
	return 0;
}