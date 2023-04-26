#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int a,b,k,n,m;
		scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
		long long arr[2000][2000];
		arr[0][0]=1;
		a%=10007;
		b%=10007;
		for(int j1=1;j1<=k;j1++)
		{
			arr[j1][0]=arr[j1-1][0]*a%10007;
		}
		for(int j2=1;j2<=k;j2++)
		{
			arr[0][j2]=arr[0][j2-1]*b%10007;
		}
		//以上是终止条件的设定 
		for(int j3=1;j3<=k;j3++)
		{
			for(int j4=1;j4<=k;j4++)
			{
				arr[j3][j4]=(arr[j3-1][j4]*a+arr[j3][j4-1]*b)%10007;
			}
		}
		printf("case #%d:\n",i);
		printf("%lld\n",arr[n][m]); 
	}
}