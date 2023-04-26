#include<stdio.h>
#include<stdlib.h>
int myreserve(int n)
{
	int a[11];
	int i=0,j,ans=0;
	while(n)
	{
		a[i++]=n%10;
		n/=10;
	}
	for(j=0;j<i;j++)
		ans=ans*10+a[j];
	return ans;
}
int solve(int n)
{
	int m=myreserve(n);
	if(m==n)return 0;
	else return 1+solve(n+m);
}
int main()
{
	int n,time;
	scanf("%d",&n);
	time=solve(n);
	for(int i=0;i<time;i++)
		n+=myreserve(n);
	printf("%d %d",time,n);
	
}