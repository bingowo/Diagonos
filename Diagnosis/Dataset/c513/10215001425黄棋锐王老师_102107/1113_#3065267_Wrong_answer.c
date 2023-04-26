#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() 
{ 	int k,n;
	scanf("%d%d",&k,&n);
	long long co[102]={0,1};
	int i,j;
	for(i=2;i<=n-1;i++)
	{if(i>=k) for(j=1;j<=k;j++) co[i]+=co[i-j];
	else for(j=1;j<=i;j++) co[i]+=co[i-j];
	}
	printf("%lld",co[n-1]);
    return 0;
}
