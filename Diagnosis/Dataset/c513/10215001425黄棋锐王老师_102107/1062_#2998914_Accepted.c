#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{    int k,T;
    scanf("%d\n",&T);
    long long f[53]={0,1,2,4,8,15};
	for(k=0;k<T;k++)
	{    int n,i;
		scanf("%d",&n);
		long long cnt=0;
		if(n<=5) cnt=f[n];
	   else
	   {   for(i=6;i<=n;i++)
	   f[i]=2*f[i-1]-f[i-5];
	   cnt=f[n];
	   }
		printf("case #%d:\n",k);
		printf("%lld\n",cnt);
	}
	return 0;
}
 
