#include <stdio.h>
long long int arr[51];
long long int f(int n)
{
	if(n<=2) return n;
	else if(n==3) return 4;
	else if(n==4) return 8;
	if(arr[n]!=-1) return arr[n];
	else{
		arr[n]=f(n-1)+f(n-2)+f(n-3)+f(n-4);
		return arr[n];
	}
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n,j=0;
		for(j;j<51;j++) arr[j]=-1;
		long long int ans;
		scanf("%d",&n);
		ans=f(n);
		printf("case #%d:\n",i);
		printf("%lld\n",ans);
	}
	return 0;
}