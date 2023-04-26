#include<stdio.h>
#include<math.h>
#include<stdlib.h> 
#include<string.h>
int f(long long int x)
{
	if(x==1) return 1;
	else if(x==2) return 2;
	else if(x==3) return 4;
	else if(x==4) return 8;
	else
	{
		return f(x-1)+2*f(x-2)+4*f(x-3)+8*f(x-4);
	}
	
	
}
int main()
{
	long long int t,a,i=0,ans;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld",&a);
		ans=f(a);
		printf("case #%lld:\n",i);
		printf("%lld\n",ans);

	}
	
	
	
	return 0;
	
	
 } 