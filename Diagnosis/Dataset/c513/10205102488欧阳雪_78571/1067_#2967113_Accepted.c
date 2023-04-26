#include<stdio.h>
/*long long f(int n)
{
	if(n==0){
		return 0;
	}
	if(n==1||n==2){
		return 1;
	}
	return f(n-1)+f(n-2)+f(n-3);
}*/
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		long long a[100]={0}; 
		a[0]=0,a[1]=1,a[2]=1;
		for(int i=3;i<=n;i++)
		{
			a[i]=a[i-1]+a[i-2]+a[i-3];
		}
		printf("case #%d:\n",i);
		printf("%lld\n",a[n]);
	}
}