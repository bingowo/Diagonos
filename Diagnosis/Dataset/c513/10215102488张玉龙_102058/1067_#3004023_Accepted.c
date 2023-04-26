#include<stdio.h>
#include<string.h>
long long result[100]={0};
long long f(int n)
{
	if(n==0)
		result[n]=0;
	else if(n==1||n==2)
		result[n]=1;
	else if(result[n]!=0)
		return result[n];
	else
		result[n]=f(n-1)+f(n-2)+f(n-3);
	return result[n];
} 
int main()
{
	int t,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		printf("case #%d:\n%lld\n",i,f(n));
	} 
	return 0;
}
