#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void add(int a[],int b[])
{
	int carry=0;
	;
	for(int i=0;i<30;i++) 
	{
		int n=a[i]+b[i]+carry;
		a[i]=n%10;
		carry=n/10;
	}
}
int main()
{
	int k,n;
	scanf("%d %d",&k,&n);
	int ans[110][30]={0};
	ans[1][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=k&&i-j>=0;j++)
		{
			add(ans[i],ans[i-j]);
		}//printf("%d\n",ans[i]);
	}
	int a=30;
	while(ans[n-1][a]==0) a--;
	for(int j=0;j<=a;j++) printf("%d",ans[n-1][j]);
	return 0;
	
}