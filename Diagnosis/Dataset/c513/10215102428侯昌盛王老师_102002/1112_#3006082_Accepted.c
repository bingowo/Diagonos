#include <stdio.h>

int main()
{
	long c[1001]={0};
	c[0]=1;
	int v[4]={1,2,3,4};
	int i=0,j;
	for(i;i<4;i++)
	{
		for(j=v[i];j<1001;j++)
		{
			c[j]+=c[j-v[i]];
		}
	}
	int m,e;
	scanf("%d",&m);
	for(e=0;e<m;e++)
	{
		int k;
		scanf("%d",&k);
		printf("%d\n",c[k]);
	}
	return 0;

} 