#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int tr1(int ans,long long(*a)[200],long long(*f)[200],int n,int m,long long k);
int tr2(int ans,long long(*a)[200],long long(*f)[200],int n,int m,long long k);
int tr3(int ans,long long(*a)[200],long long(*f)[200],int n,int m,long long k);
int tr4(int ans,long long(*a)[200],long long(*f)[200],int n,int m,long long k);
 int main()
 {   int n,m;
 	long long k;
 	scanf("%d %d %lld\n",&n,&m,&k);//四种等腰三角形，都可看成1+2+3+。。。。行数叠成
	long long a[200][200];
	long long f[200][200]={0};
	int ans=0;
	int i,j;
	for(i=1;i<=n;i++)
	 for(j=1;j<=m;j++) 
	 	{
		 scanf("%lld",&a[i][j]);
	      f[i][j]=f[i][j-1]+a[i][j];//为取每行部分数的顺序加和，先预处理 
	 	}
	ans=tr1(ans,a,f,n,m,k);
	ans=tr2(ans,a,f,n,m,k);
	ans=tr3(ans,a,f,n,m,k);
	ans=tr4(ans,a,f,n,m,k);
	printf("%d\n",ans);
 	return 0;
 }
 int tr1(int ans,long long(*a)[200],long long(*f)[200],int n,int m,long long k)//从一点往左上依次加一行 
 {  int x,y;
 	for(x=1;x<=n;x++)
 	{ for(y=1;y<m;y++)
 	 {  int r; 
 	 	long long s=a[x][y];//从x行y列这个数出发
	 	for(r=1;x-r>0&&y-r>0;r++)//第x-r行 
	 	{   int ly=y-r;//最左列 
	 		int ry=y;//最右列 
	 		s+=f[x-r][ry]-f[x-r][ly-1];
	 		if(s>=k) ans++;
		 }
	  }
	}
	return ans;
 }
 int tr2(int ans,long long(*a)[200],long long(*f)[200],int n,int m,long long k)//往右上 
 {	int x,y;
 	for(x=1;x<=n;x++)
 	{ for(y=1;y<m;y++)
 	 {  int r; 
 	 	long long s=a[x][y];//从x行y列这个数出发
	 	for(r=1;x-r>0&&y+r<=m;r++)//第x-r行 
	 	{   int ly=y;//最左列 
	 		int ry=y+r;//最右列 
	 		s+=f[x-r][ry]-f[x-r][ly-1];
	 		if(s>=k) ans++;
		 }
	  }
	}
 	return ans;
 }
 int tr3(int ans,long long(*a)[200],long long(*f)[200],int n,int m,long long k)//往左下 
 {int x,y;
 	for(x=1;x<=n;x++)
 	{ for(y=1;y<m;y++)
 	 {  int r; 
 	 	long long s=a[x][y];//从x行y列这个数出发
	 	for(r=1;x+r<=n&&y-r>0;r++)//第x+r行 
	 	{   int ly=y-r;//最左列 
	 		int ry=y;//最右列 
	 		s+=f[x+r][ry]-f[x+r][ly-1];
	 		if(s>=k) ans++;
		 }
	  }
	}
	return ans;
 }
 int tr4(int ans,long long(*a)[200],long long(*f)[200],int n,int m,long long k)//往右下 
 {int x,y;
 	for(x=1;x<=n;x++)
 	{ for(y=1;y<m;y++)
 	 {  int r; 
 	 	long long s=a[x][y];//从x行y列这个数出发
	 	for(r=1;x+r<=n&&y+r<=m;r++)//第x+r行 
	 	{   int ly=y;//最左列 
	 		int ry=y+r;//最右列 
	 		s+=f[x+r][ry]-f[x+r][ly-1];
	 		if(s>=k) ans++;
		 }
	  }
	}
	return ans;
 }