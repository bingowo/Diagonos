#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)){
		if(n==0)
			break;
		int i=n,ret=1;
		for(;i>0;i--){
			ret=ret*n;
			while(ret>=100){
				ret/=10;
			}
		}
		while(ret>=10){
			ret/=10;
		}
		printf("%d\n",ret);
	}
	return 0;
 } 