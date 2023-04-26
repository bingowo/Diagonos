#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
	int k,n;
	scanf("%d %d",&k,&n);
	int ans[1000]={0};
	ans[1]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=k&&i-j>=0;j++)
		{
			ans[i]+=ans[i-j];
		}//printf("%d\n",ans[i]);
	}
	printf("%d",ans[n-1]);
	return 0;
	
}