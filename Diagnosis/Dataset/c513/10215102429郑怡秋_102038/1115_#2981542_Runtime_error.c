#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void add(int a[],int b[])
{
	
	return ;
}
int main()
{
	int k,n;
	scanf("%d %d",&k,&n);
	int *ans[30]={0};
	ans[1][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=k&&i-j>=0;j++)
		{
			add(ans[i],ans[i-j]);
		}//printf("%d\n",ans[i]);
	}
	printf("%d",ans[n-1]);
	return 0;
	
}