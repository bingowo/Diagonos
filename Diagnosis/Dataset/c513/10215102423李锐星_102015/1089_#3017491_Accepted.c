#include <stdio.h>

void solve()
{
	long long a,b,n;
	scanf("%lld %lld %lld",&a,&b,&n);
	long long x=1;
	int i;
	for (i=0;i<n;i++){
		x*=10;
	}
	long long res=1%x;
	while(b)
	{
		if(b&1){
			res=(res%x*a%x)%x;
		}
		a=a*a%x;
		b>>=1;
	}
	int ans[10];
	for (i=0;i<10;i++){
		ans[i]=0;
	}
	for (i=0;res>0;i++){
		ans[i]=res%10;
		res/=10;
	}
	for (i=n-1;i>=0;i--){
		printf("%d",ans[i]);
	}
	printf("\n");
	
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		printf("case #%d:\n",i);
		solve();
	}
	return 0;
}