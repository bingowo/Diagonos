#include <stdio.h>
#include <math.h>
#include <string.h>
long long int arr[1000][1000];
long long int f(int k,int min)
{
	
	if(min==1) return k;
	else if(k==min) return 1;
	if(arr[k][min]!=0)
	{
		arr[k][min]%=10007;
		return arr[k][min];
	}
	else
	{
		arr[k][min]=f(k-1,min)+f(k-1,min-1);
		arr[k][min]%=10007;
		return arr[k][min];
	}
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		long long int a,b,k,n,m,min;
		scanf("%lld %lld %lld %lld %lld",&a,&b,&k,&n,&m);
		long long int ans;
		if(n==0 || m==0) min=k;
		else if(n<m) min=n;
		else min=m;
		memset(arr,0,sizeof(arr[0]));
	
		ans=f(k,min);
		//printf("%lld\n",ans);
		ans%=10007;
		a%=10007;
		b%=10007;
		a=pow(a,n);
		a%=10007;
		b=pow(b,m);
		b%=10007;
		ans=ans*a*b;
		ans%=10007;
		printf("case #%d:\n",i);
		printf("%lld\n",ans);
	}
	return 0;
}