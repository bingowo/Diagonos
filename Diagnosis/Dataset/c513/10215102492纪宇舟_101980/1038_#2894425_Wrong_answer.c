#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int MIN(int x,int y)
{
	if(x<y)return x;return y;
}
int main()
{
	int n,m,K,ans=0;
	long long a[200][200],s[200][200][200][4],subx[200][200],suby[200][200];
	scanf("%d%d%d",&n,&m,&K);//memset(s,-1,sizeof(s));
	for(int i=1;i<=n;i++)subx[i][0]=0;
	for(int i=1;i<=m;i++)suby[0][i]=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		scanf("%lld",&a[i][j]);
		s[i][j][1][0]=s[i][j][1][1]=s[i][j][1][2]=s[i][j][1][3]=0;
		subx[i][j]=subx[i][j-1]+a[i][j];
		suby[i][j]=suby[i-1][j]+a[i][j];
	}
	for(int k=1;k<n&&k<m;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(i-k>=1&&j-k>=1)//up-left
		{
			s[i][j][k+1][0]=s[i-1][j-1][k][0]+subx[i][j]-subx[i][j-k-1]+suby[i-1][j]-suby[i-k-1][j];
			if(s[i][j][k+1][0]>=K)ans++;
		}
		if(i-k>=1&&j+k<=m)//up-right
		{
			s[i][j][k+1][1]=s[i-1][j+1][k][1]+subx[i][j+k]-subx[i][j-1]+suby[i-1][j]-suby[i-k-1][j];
			if(s[i][j][k+1][1]>=K)ans++;
		}
		if(i+k<=n&&j-k>=1)//down-left
		{
			s[i][j][k+1][2]=s[i+1][j-1][k][2]+subx[i][j]-subx[i][j-k-1]+suby[i+k][j]-suby[i][j];
			if(s[i][j][k+1][2]>=K)ans++;
		}
		if(i+k<=n&&j+k<=m)//down-right
		{
			s[i][j][k+1][3]=s[i+1][j+1][k][3]+subx[i][j+k]-subx[i][j-1]+suby[i+k][j]-suby[i][j];
			if(s[i][j][k+1][3]>=K)ans++;
		}
	}
	/*for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		sum=a[i][j];//up-left
		for(int k=1;i-k>=1&&j-k>=1;k++)
		{
			sum+=a[i][j-k]+a[i-k][j];
			if(sum>=k){ans+=MIN(i-k,j-k);break;}
		}
		sum=a[i][j];//up-right
		for(int k=1;i-k>=1&&j+k<=m;k++)
		{
			sum+=a[i][j+k]+a[i-k][j];
			if(sum>=k){ans+=MIN(i-k,m-j-k+1);break;}
		}
		sum=a[i][j];//down-left
		for(int k=1;i+k<=n&&j-k>=1;k++)
		{
			sum+=a[i][j-k]+a[i+k][j];
			if(sum>=k){ans+=MIN(n-i-k+1,j-k);break;}
		}
		sum=a[i][j];//down-right
		for(int k=1;i+k<=n&&j+k<=m;k++)
		{
			sum+=a[i][j+k]+a[i+k][j];
			if(sum>=k){ans+=MIN(n-i-k+1,m-j-k+1);break;}
		}
	}*/
	printf("%d",ans);
	return 0;
} 