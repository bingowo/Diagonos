#include<stdio.h>
int F[201][201];
int a[201][201];
int get_num1(int i,int j,int l);
int get_num2(int i,int j,int l);
int get_num3(int i,int j,int l);
int get_num4(int i,int j,int l);
int main()
{
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	int i,j,q,l,maxl=n>m?n:m,cnt=0;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	}
	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
			F[i][j]=0; 
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			for(q=1;q<=j;q++)
				F[i][j]+=a[i][q];
		}
	}
	
	for(l=2;l<=maxl;l++)
	{
		//从左上开始 
		for(i=1;i<=n-l+1;i++)
		{
			for(j=1;j<=m-l+1;j++)
			{
				if(get_num1(i,j,l)>=k)
					cnt++;
			}
		}
		
		//从右上开始
		for(i=1;i<=n-l+1;i++) 
		{
			for(j=m;j>=l;j--)
			{
				if(get_num2(i,j,l)>=k)
					cnt++;
			}
		}
		
		//从左下开始 
		for(i=n;i>=l;i--)
		{
			for(j=1;j<=m-l+1;j++)
			{
				if(get_num3(i,j,l)>=k)
					cnt++;
			}
		}
		
		//从右下开始
		for(i=n;i>=l;i--) 
		{
			for(j=m;j>=l;j--)
			{
				if(get_num4(i,j,l)>=k)
					cnt++;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}

int get_num1(int i,int j,int l)
{
	int ans=0;
	for(int q=0;q<l;q++)
		ans+=F[i+q][j+l-q-1]-F[i+q][j-1];
	return ans;
}
int get_num2(int i,int j,int l)
{
	int ans=0;
	for(int q=0;q<l;q++)
		ans+=F[i+q][j]-F[i+q][j-l+q];
	return ans;
}
int get_num3(int i,int j,int l)
{
	int ans=0;
	for(int q=0;q<l;q++)
		ans+=F[i-q][j+l-q-1]-F[i-q][j-1];
	return ans;
}
int get_num4(int i,int j,int l)
{
	int ans=0;
	for(int q=0;q<l;q++)
		ans+=F[i-q][j]-F[i-q][j-l+q];
	return ans;
}