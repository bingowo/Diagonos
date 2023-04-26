#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int n,m,k,a[202][202]={0},F[202][202]={0},ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for (int i = 1; i <=n; i++)
	{
	    for (int j = 1; j <=m; j++)
	    {
	        F[i][j] = F[i][j-1]+a[i][j];
	    }
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			long long int d=a[i][j];
		 	for (int r = 1;i- r>0&&j-r>0;r++)
			{
		        int lb = j-r;
		        int rb = j;	
		        d += F[i-r][rb]-F[i-r][lb-1];
		        if (d >= k) ans++;
		    }
		    
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			long long int d=a[i][j];
		 	for (int r = 1;i- r>0&&j+r<=m;r++) 
			{
		        int lb = j+r;
		        int rb = j;
		        d += F[i-r][lb] - F[i-r][rb-1];
		        if (d >= k) ans++;
		    }	    
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			long long int d=a[i][j];
		 	for (int r = 1;i+r<=n&&j-r>0;r++) 
			{
		        int lb = j-r;
		        int rb = j;
		        d += F[i+r][rb]-F[i+r][lb-1];
		        if (d >= k) ans++;
		    }
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			long long int d=a[i][j];
		 	for (int r = 1;i+r<=n&&j+r<=m;r++) 
			{
		        int lb = j+r;
		        int rb = j;
		        d += F[i+r][lb] - F[i+r][rb-1];
		        if (d >= k) ans++;
		    }	    
		}
	}

	printf("%d",ans);
}