#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	unsigned long long int t,n,ans;
	scanf("%lld",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%llu",&n);
		int a=0,b=1,c=1;
		ans=0;
		if(n==0) ans=0;
		else if(n==1) ans=1;
		else if(n==2) ans=1;
		else 
		{
			for(int j=0;j<n-2;j++)
			{
				ans=a+b+c;
				a=b;b=c;c=ans;
			}
		}
		printf("case #%d:\n%llu\n",i,ans);
	}

	return 0;
	
 } 