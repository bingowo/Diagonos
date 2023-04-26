#include <stdio.h>
long long int f(int n,int m,int *count)
{
	if(n==m) return n;
	else{
		n+=m;
		m=0;
		int res=n,res2;
		while(res!=0)
		{
			res2=res%10;
			m=m*10+res2;
			res/=10;
		}
		count[0]++;
		return f(n,m,count);
	}
}

int main()
{
	int n,m=0,count[1]={0};
	scanf("%d",&n);
	int res=n,res2;
	while(res!=0)
	{
		res2=res%10;
		m=m*10+res2;
		res/=10;
	}
	long long ans;
	ans=f(n,m,count);
	printf("%d %lld\n",count[0],ans);
	return 0;
}