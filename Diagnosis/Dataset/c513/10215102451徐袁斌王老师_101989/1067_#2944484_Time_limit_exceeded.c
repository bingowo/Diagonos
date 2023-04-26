#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int f(int x)
{
	if(x==0) return 0;
	if(x==1) return 1;
	if(x==2) return 1;
	else return f(x-1)+f(x-2)+f(x-3);
}
int main()
{
	int t,n,ans;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		ans=f(n);
		printf("case #%d:\n%d\n",i,ans);
	}

	return 0;
	
 } 