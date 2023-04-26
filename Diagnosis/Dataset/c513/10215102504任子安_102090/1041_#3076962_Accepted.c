#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int max=1,i,n;
    int dp[52];
    char a[100];
    scanf("%s\n", a);
    n=strlen(a);
    dp[0] = 1;
    for(i=1; i<n; ++i){
        if(a[i] != a[i-1])
            dp[i] = dp[i-1] + 1;
        else
            dp[i] = 1;
        if(dp[i] > max)
            max = dp[i];
    }
    printf("%d",max);
    return 0;
}