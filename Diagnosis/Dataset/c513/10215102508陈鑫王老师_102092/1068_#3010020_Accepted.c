#include <stdio.h>
 
long long b[32][32];
int i,j,k,n,m,t;
 
int main()
{
	for(i=1;i<32;i++)
		b[i][0]=1;
	for(i=1;i<32;i++)
		for(j=1;j<=i;j++)
		{	
			if(b[i-1][j])
			{
				b[i][j]+=b[i-1][j]*2;
				t=i-j-2;
				if(t>0)
				{
					for(k=0;k<=j;k++)
						b[i][j]-=b[t][k];
				}
				else 
					b[i][j]-=1;
			}
			t=i-j-1;
			if(t>0)
			{
				for(k=0;k<j;k++)
					b[i][j]+=b[t][k];
			}
			else 
				b[i][j]+=1;				
		}
	while(scanf("%d%d",&n,&m)&&n!=-1&&m!=-1)
	{
		long long ans=0;
		for(i=m;i<=n;i++)
			ans+=b[n][i];
		printf("%lld\n",ans);
	}
}
