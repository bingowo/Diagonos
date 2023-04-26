#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	int w[10]={0};
	int sum=0;
	int i=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		sum+=w[i];
	}
	//printf("sum:%d\n",sum);
	int f[11][10000];//f[i][j]表示用前i个砝码能否称出重量为j 
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			if(f[i-1][j]==1)//用前i-1个砝码可以称出j 
			{
				f[i][j]=1;
				f[i][abs(j+w[i])]=1;//j增加第i个砝码的重量 
				f[i][abs(j-w[i])]=1;//j减去第i个砝码的重量也可以被称出 
			}
		}
	}
	for(i=1;i<=sum;i++)
	{
		printf("%d",f[n][i]);
	} 
}