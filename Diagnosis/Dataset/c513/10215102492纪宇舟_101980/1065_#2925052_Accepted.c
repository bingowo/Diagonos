#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int a,n,m,x,ans,X;
int upa[21],upx[21],dowa[21],dowx[21],suma[21],sumx[21];
void dfs(int pos)
{
	if(pos==1){upa[pos]=1;upx[pos]=dowa[pos]=dowx[pos]=0;suma[pos]=1;sumx[pos]=0;}
	else if(pos==2){upa[pos]=0;upx[pos]=1;dowa[pos]=0;dowx[pos]=1;suma[pos]=1;sumx[pos]=0;}
	else
	{
		upa[pos]=upa[pos-1]+upa[pos-2];
		upx[pos]=upx[pos-1]+upx[pos-2];
		dowa[pos]=upa[pos-1];
		dowx[pos]=upx[pos-1];
		suma[pos]=suma[pos-1]+upa[pos]-dowa[pos];
		sumx[pos]=sumx[pos-1]+upx[pos]-dowx[pos];
	}
	if(pos==n)
	{
		if(n!=1&&n!=2)
		X=(m-a*suma[pos-1])/sumx[pos-1];
		return;
	}
	dfs(pos+1);
	if(pos==x)
	{
		if(n==1||n==2)printf("%d",a);
		else printf("%d",a*suma[pos]+X*sumx[pos]);
	}
}
int main()
{
	scanf("%d%d%d%d",&a,&n,&m,&x);
	dfs(1);
	return 0;
}