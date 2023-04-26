#include <stdio.h>
int dp[21];
int main() {

    dp[1]=2;
	dp[2]=4;
	dp[3]=7;

        for(int i = 4; i < 21; i++)
	{
		dp[i]=2*dp[i-1]-dp[i-2]+dp[i-3];
	}

    int n;
    scanf("%d",&n);
    do {
        printf("%d\n",dp[n]);
        scanf("%d",&n);
    } while (n!=-1);
    return 0;
}
