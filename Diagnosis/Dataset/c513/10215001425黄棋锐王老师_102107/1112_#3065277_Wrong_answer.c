#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 200


int main() 
{ 	int T;
	scanf("%d\n",&T);
	while(T--)
{
	int i,j,k,n,cn=0;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{ int x=0,y;
		while(3*x<=i)
		{
			if((i-3*x)%2==0) y=(i-3*x)/2,cn++;
			if(y>0&&y%2==0) cn++;
			x++;
		}
	}
	printf("%d\n",cn);
	
}


    return 0;
}
