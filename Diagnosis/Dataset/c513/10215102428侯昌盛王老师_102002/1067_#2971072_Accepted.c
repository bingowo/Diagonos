#include <stdio.h>
long long int arr[75];
long long int h(int n)
{
	if(n==0) return 0;
	else if(n<=2) return 1;
	if(arr[n]!=-1) return arr[n];
	else
	{
		arr[n]=h(n-1)+h(n-2)+h(n-3);
		return arr[n];
	 } 
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n,j;
		long long int sum;
		scanf("%d",&n);
		for(j=0;j<75;j++) arr[j]=-1;
		sum=h(n);
		printf("case #%d:\n",i);
		printf("%lld\n",sum);
	}
	return 0;
}