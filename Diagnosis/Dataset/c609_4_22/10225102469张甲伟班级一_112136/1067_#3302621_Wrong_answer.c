#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int up[100],down[100],f[100];
int main()
{
	int a,n,m,x,y;
	scanf("%d%d%d%d",&a,&n,&m,&x);
	up[1]=a;
	down[1]=0;
	f[1]=1;
	f[2]=1;
	for(int i=3;i<=21;i++)
		f[i]=f[i-1]+f[i-2];
	y=(m-f[n-3]*a)/f[n-2];
	up[2]=y;
	down[2]=y;
	for(int i=3;i<n;i++)
	{
		up[i]=up[i-1]+up[i-2];
		down[i]=up[i-1];
		}
	int ans=0;	
	if(x==1||x==2)
		printf("%d",a);
	else if(x==n)
		printf("%d",m);
	else
	{
		for(int i=1;i<=x;i++)
			ans=ans+up[i]-down[i];
		printf("%d",ans);
	}
	return 0;
 } 