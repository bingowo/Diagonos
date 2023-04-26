#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	int m,n;
	long long int ret=1;
	for(int i=0;i<T;i++){
		scanf("%d%d",&m,&n);
		if(n>m/2)
			n=m-n;
		int a = n;
		for(int j=0;j<a;j++,m--){
			ret = ret * m;	
			while(ret%n==0&&n>1){
				ret/=n;n--;
			}		
		}
		printf("case #%d:\n",i);
		printf("%lld\n",ret);
	}
	
	
	return 0;
} 