#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int cura[100],cury[100],upa[100],upy[100];
int main()
{
	int a,n,m,x,y;
	scanf("%d%d%d%d",&a,&n,&m,&x);
	upa[1]=1;upa[2]=0;
	cura[1]=1;cura[2]=1;
	upy[1]=0;upy[2]=1;
	cury[1]=0;cury[2]=0;
	for (int i=3;i<=n;i++) 
	{
		upa[i]=upa[i-1]+upa[i-2];
		upy[i]=upy[i-1]+upy[i-2];
		cura[i]=cura[i-1]+upa[i-2];
		cury[i]=cury[i-1]+upy[i-2];
	}
	y=(m-cura[n-1]*a)/cury[n-1];
//	printf("%d\n",y);
	printf("%d",y*cury[x]+a*cura[x]);
	return 0;
 } 