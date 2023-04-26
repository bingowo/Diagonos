#include <stdio.h>

int main()
{
	int k,n;
	scanf("%d %d",&k,&n);
	long long int a[101]={0};
	a[0]=0;a[1]=1;
	int i=2;
	long long sum=0;
	for(i;i<k;i++)
	{
		//printf("h\n");
		sum+=a[i-1];
		a[i]=sum;
	}
	if(n<=k) printf("%lld\n",a[n-1]);
	else{
		
		for(i=k;i<n;i++)
		{
			sum+=a[i-1];
			a[i]=sum;
			sum-=a[i-k];
		}
		printf("%lld\n",a[n-1]);
	}
	return 0;
}