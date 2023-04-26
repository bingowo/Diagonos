#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int a[105][105],s[10];
int ans[105][105],x[8]={-1,-1,-1,0,1,1,1,0},y[8]={-1,0,1,1,1,0,-1,-1};
int cal(int pos)
{
	int j=pos,sum=0,cnt=0;
	while(cnt<8)
	{
		sum=sum*2+s[j];
		cnt++;j++;
		j%=8;
	}
	return sum;
}
int main()
{
	int m,n;scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	for(int i=2;i<n;i++)
	for(int j=2;j<m;j++)
	{
		int maxm=256;
		for(int k=0;k<8;k++)
		{
			if(a[i][j]<=a[i+x[k]][j+y[k]])s[k]=1;
			else s[k]=0;
		}
		for(int k=0;k<8;k++)
		{
			int H=cal(k);
			if(H<maxm)maxm=H;
		}
		ans[i][j]=maxm;
	}
	for(int i=2;i<n;i++)
	{
		for(int j=2;j<m;j++)
		{
			printf("%d",ans[i][j]);
			if(j!=m-1)printf(" ");
		}
		printf("\n");
	}
	return 0;
}