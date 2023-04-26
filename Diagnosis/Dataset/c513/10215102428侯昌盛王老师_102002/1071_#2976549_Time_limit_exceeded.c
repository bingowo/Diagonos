#include <stdio.h>
#include <math.h>
long long int f(int k,int min)
{
	if(min==1) return k;
	else if(k==min) return 1;
	return f(k-1,min)+f(k-1,min-1);
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int a,b,k,n,m,min;
		scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
		long long int ans;
	
		if(n<m) min=n;
		else min=m;
		ans=f(k,min);
		ans=ans*pow(a,n)*pow(b,m);
		if(ans>=10007) ans%=10007;
		printf("case #%d:\n",i);
		printf("%lld\n",ans);
	}
	return 0;
}