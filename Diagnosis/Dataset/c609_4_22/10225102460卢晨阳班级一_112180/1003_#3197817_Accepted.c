#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		long long int n;
		int a[100]={0};
		int cnt=0;
		scanf("%lld",&n);
		if(n==0)
		printf("0\n");
		else{
			while(n!=0){
			a[cnt]=n%2333;
			n=n/2333;
			cnt++;
		}
		for(int j=cnt-1;j>=0;j--)
		printf("%d ",a[j]);
		printf("\n");
		}
	}
	return 0;
 } 