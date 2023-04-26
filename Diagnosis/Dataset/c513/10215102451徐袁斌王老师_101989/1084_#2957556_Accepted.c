#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,a;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		long long int ans=0;
		scanf("%d",&a);
		ans=(long long int)pow(2,a);
		printf("case #%d:\n%lld\n",i,ans);
		
	}
	
	
}