#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n;
		scanf("%d",&n);
		int a[100]={0};
		int cnt=0;
		while(n!=0){
			a[cnt]=n%2;
			n=n/2;
			cnt++;
		}
		int max=1;
		int idx=1;
		for(int j=0;j<cnt;j++){
			if(a[j]!=a[j+1])
				idx++;
			else if(a[j]==a[j+1]){
				if(idx>=max){
					max=idx;
					idx=1;
				}else
					idx=1;
			}
		}
		printf("case #%d:\n%d\n",i,max);
//		for(int j=cnt-1;j>=0;j--)
//		printf("%d",a[j]);
//		printf("\n");
	}
	return 0;
 } 