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
	int n,m,ans=0;
	long long K,a[200][200],s[200][200][200][4],subx[200][200],suby[200][200];
	scanf("%d%d%lld",&n,&m,&K);
	for(int i=1;i<=n;i++)subx[i][0]=0;
	for(int i=1;i<=m;i++)suby[0][i]=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		scanf("%lld",&a[i][j]);
		s[i][j][0][0]=s[i][j][0][1]=s[i][j][0][2]=s[i][j][0][3]=0;
		s[i][j][1][0]=s[i][j][1][1]=s[i][j][1][2]=s[i][j][1][3]=a[i][j];
		subx[i][j]=subx[i][j-1]+a[i][j];
		suby[i][j]=suby[i-1][j]+a[i][j];
	}
	for(int k=1;k<n&&k<m;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(i-k>=1&&j-k>=1)//up-left
		{
			s[i][j][k+1][0]=s[i-1][j-1][k-1][0]+subx[i][j]-subx[i][j-k-1]+suby[i-1][j]-suby[i-k-1][j];
			if(s[i][j][k+1][0]>=K)ans++;
			//if(s[i][j][k+1][0]>=K)printf("%d %d %d ×óÉÏ£º%lld\n",i,j,k,s[i][j][k+1][0]);
		}
		if(i-k>=1&&j+k<=m)//up-right
		{
			s[i][j][k+1][1]=s[i-1][j+1][k-1][1]+subx[i][j+k]-subx[i][j-1]+suby[i-1][j]-suby[i-k-1][j];
			if(s[i][j][k+1][1]>=K)ans++;
			//if(s[i][j][k+1][1]>=K)printf("%d %d %d ÓÒÉÏ£º%lld\n",i,j,k,s[i][j][k+1][1]);
		}
		if(i+k<=n&&j-k>=1)//down-left
		{
			s[i][j][k+1][2]=s[i+1][j-1][k-1][2]+subx[i][j]-subx[i][j-k-1]+suby[i+k][j]-suby[i][j];
			if(s[i][j][k+1][2]>=K)ans++;
			//if(s[i][j][k+1][2]>=K)printf("%d %d %d ×óÏÂ£º%lld\n",i,j,k,s[i][j][k+1][2]);
		}
		if(i+k<=n&&j+k<=m)//down-right
		{
			s[i][j][k+1][3]=s[i+1][j+1][k-1][3]+subx[i][j+k]-subx[i][j-1]+suby[i+k][j]-suby[i][j];
			if(s[i][j][k+1][3]>=K)ans++;
			//if(s[i][j][k+1][3]>=K)printf("%d %d %d ÓÒÏÂ£º%lld\n",i,j,k,s[i][j][k+1][3]);
		}
	}
	printf("%d",ans);
	return 0;
} 