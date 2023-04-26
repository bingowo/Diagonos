#include<stdio.h>
typedef unsigned long long ull;
ull pow(int a,int b)
{
	ull ans=1;
	for(int i=0;i<b;i++)ans*=a;
	return ans;
}
ull f(int n,int m)
{
	if(n<m)return 0;
	else if(n==m)return 1;
	else return 2*f(n-1,m)+pow(2,n-m-1)-f(n-m-1,m);
}
int main()
{
	int n,m,i,j;
	while(~scanf("%d %d",&n,&m))
	{
		if(n==-1&&m==-1)return 0;
		printf("%llu\n",f(n,m));
	}
}