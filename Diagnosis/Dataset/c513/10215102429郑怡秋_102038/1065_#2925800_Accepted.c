#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

int main()
{
	int a,n,m,x;
	scanf("%d%d%d%d",&a,&n,&m,&x);
	int a1=0,a2=a,x1=1,x2=1;
	for(int i=3;i<n-1;i++)
	{
		int a=a1,z0=x1;
		a1=a2;a2=a+a1;
		x1=x2;x2=z0+x1;
		//printf("%d %d \n",a2,x2);
	}
	int z;
	for(z=0;z<20;z++)
	{//printf("%d\n",a2+x2*z+a-z);
		if(a2+x2*z+a-z==m) 
		{
			break;
		}
	}//printf("%d\n",z);
	int z1=a,z2=z;
	for(int i=2;i<x;i++)
	{
		int zz=z1;
		z1=z2;
		z2=z1+zz;	
	}
	printf("%d",z2+a-z);
	return 0;
	
	
	
}