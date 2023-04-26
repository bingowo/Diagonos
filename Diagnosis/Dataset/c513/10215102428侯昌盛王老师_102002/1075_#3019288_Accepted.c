#include <stdio.h>
#include <string.h>
int min(int a,int b)
{
	
	if(a>b) return b;
	return a;
}
int main()
{
	int m,n,i,j,k=0;
	char s[302][302][902]={'\0'};
	//scanf("%s",s[0][0]);
	//printf("%d\n",strlen(s[0][0]));
	scanf("%d %d",&m,&n);
	int a[302][302]={0};
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++) scanf("%d",&a[i][j]);
		
	}
	int dp[302][302]={0};
	for(j=0;j<=n+1;j++) 
	{
		dp[0][j]=1000001;
		dp[m+1][j]=1000001;
	}
	for(i=1;i<=m;i++)
	{
		dp[i][0]=1000001;
		dp[i][n+1]=1000001;
	}
	dp[0][1]=0;dp[1][0]=0;
	//printf("%d\n",strlen(s[1][1]));
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(dp[i-1][j]<dp[i][j-1]) 
			{
				
				//s[i-1][j][len]='D';
				//s[i-1][j][len+1]='\0';
				//printf("%d\n",strlen(s[i][j]));
				strcpy(s[i][j],s[i-1][j]);
				int len=strlen(s[i][j]);
				s[i][j][len]='D';
				
				
			}
			else if(dp[i][j-1]<dp[i-1][j])
			{
				
				//s[i][j-1][len]='R';
				//s[i][j-1][len+1]='\0';
				strcpy(s[i][j],s[i][j-1]);
				int len=strlen(s[i][j]);
				s[i][j][len]='R';
				
			}
			 
			//printf("%d %d\n",strlen(s[1][1]),j);
			dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j];
			
		}
	}
	//printf("%d\n",strlen(s[1][3]));
	printf("%d\n",dp[m][n]);
	printf("%s\n",s[m][n]);
	return 0;
	
}