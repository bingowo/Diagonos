#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		long long int n;
		scanf("%lld",&n); 
		int num[20],a=0;
		while(n>0){
			num[a]=n%2333;
			n/=2333;
			a++;
		}
		for(int i=a-1;i>0;i--){
			printf("%d ",num[i]);
		}
		printf("%d\n",num[0]);
	}
	
	return 0;
}