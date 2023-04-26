#include<stdio.h>
int main()
{
	int k,n;
	scanf("%d%d",&k,&n);
	int num[101],i=4;
	num[1] = 0;num[2] = 1;num[3] = 1;
	for(;i<=n;i++){	
		if(i-k-1>0)			
			num[i] = 2*num[i-1] - num[i-k-1];
		else
			num[i] = 2*num[i-1]; 
	}
	printf("%d",num[n]);
	return 0;
}