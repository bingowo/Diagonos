
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long cal(int n)
{
	
}
int main()
{    int k,T;
    scanf("%d\n",&T);
	for(k=0;k<T;k++)
	{    int n;
		scanf("%d\n",&n);
		long long cnt=cal(n);
		printf("case #%d:\n",k);
		printf("%lld\n",cnt);
	}
	return 0;
}
 
