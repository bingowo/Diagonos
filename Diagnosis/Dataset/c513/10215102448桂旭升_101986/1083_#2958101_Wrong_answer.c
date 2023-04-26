#include<stdio.h>  
int T;
/*计算能被5整除的次数*/
void solve()
{
	int n;
	scanf("%d",&n);
	int ret=0;
	int m=5;
	while(n>=m)
	{
		ret+=n/m;
		m*=5;
	}
	printf("%d\n",&ret);
}
int main()
{
	scanf("%d",&T);
	for(int step=0;step<T;step++)
	{
		printf("case #%d:\n",step);
		solve();
	}
	return 0;
}