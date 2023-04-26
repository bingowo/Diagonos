#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	int T;
	scanf("%d",&T);
	int k=0;
	while(T--){
		char ans[1005]={1};
		int m,n;
		scanf("%d %d",&m,&n);
		while(n--){
			int i=0;
			int carry=0;
			while(ans[i]||carry){
				int temp=ans[i]*m+carry;
				ans[i]=temp%10;
				carry=temp/10;
				i++;
			}
		}
		int i=0;
		printf("case #%d:\n",k++);
		while(ans[i]){
			printf("%d\n",ans[i]);
			i++;
		}
		
	}
	
	
	return 0;
}