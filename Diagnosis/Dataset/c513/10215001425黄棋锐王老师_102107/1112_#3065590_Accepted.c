#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 200


int main() 
{ 	int T;
	scanf("%d\n",&T);
	int dp[1111]={1};
	int type[4]={4,3,2,1};
	int i,j;
	for (i = 0; i < 4; i++) {
        for (j = type[i]; j <= 1000; j++) 
		{
            dp[j] += dp[j - type[i]];
        }
    }
	while(T--)
{	
	int n;
	scanf("%d",&n);
	printf("%d\n",dp[n]);
	
}


    return 0;
}
