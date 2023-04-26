#include<stdio.h>
int k,n,m;
int array[200][200];
int judge1(int l,int a,int b)//右上 
{
	int i,j,sum;
	for(i=a;i<a+l;i++)
	{
		for(j=b;j<b+l-i+a;j++)
			sum+=array[i][j];
	}
	if(sum>=k)return 1;
	else return 0;
}
int judge2(int l,int a,int b)//左上 
{
	int i,j,sum;
	for(i=a;i<a+l;i++)
	{
		for(j=b;j>b-l+i-a;j--)
			sum+=array[i][j];
	}
	if(sum>=k)return 1;
	else return 0;
}
int judge3(int l,int a,int b)//右下 
{
	int i,j,sum;
	for(i=a;i>a-l;i--)
	{
		for(j=b;j<b+l-a+i;j++)
			sum+=array[i][j];
	}
	if(sum>=k)return 1;
	else return 0;
}
int judge4(int l,int a,int b)//左下
{
	int i,j,sum;
	for(i=a;i>a-l;i--)
	{
		for(j=b;j>b-l-i+a;j--)
			sum+=array[i][j];
	}
	if(sum>=k)return 1;
	else return 0;
} 
int main()
{
	int l,a,b;scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)scanf("%d",&array[i][j]);
	}
	int maxl=n<m?n:m,cnt=0;
	
	
	for(l=2;l<=maxl;l++)//确定边长
	{
		//右上： 
		for(a=0;a<=n-l;a++)//确定起始位置行标 
		{
			for(b=0;b<=m-l;b++)//确定起始位置列标 
			{
				//printf("(%d,%d)",a,b);
				if(judge1(l,a,b))cnt++; 
			}
		}
		
		//左上：
		for(a=0;a<=n-l;a++) 
		{
			for(b=m-1;b>=l-1;b--)
			{
				//printf("(%d,%d)",a,b);
				if(judge2(l,a,b))cnt++; 
			}
		}
		
		//右下： 
		for(a=n-1;a>=l-1;a--)
		{
			for(b=0;b<=m-l;b++)
			{
				//printf("(%d,%d)",a,b);
				if(judge3(l,a,b))cnt++; 
			}
		}
		
		//左下； 
		for(a=n-1;a>=l-1;a--)
		{
			for(b=m-1;b>=l-1;b--)
			{
				//printf("(%d,%d)",a,b);
				if(judge4(l,a,b))cnt++; 
			}
		}
	}
	printf("%d",cnt);
	return 0;
	
	 
}