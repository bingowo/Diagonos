#include<stdio.h>
#include<stdlib.h>

long long *dp; // declare the memoization array globally

long long count_step(int n);

int main(){
    int T;
    scanf("%d",&T);
    int n;
    dp = (long long *)malloc(1000001 * sizeof(long long)); // allocate memory for memoization array
    for(int i = 0;i < T;i++){
        scanf("%d",&n);
        printf("case #%d:\n",i+1); 
        printf("%lld\n",count_step(n));
    }
    free(dp); // free memoization array after all computations are done
} 

long long count_step(int n){
    if (n == 0 || n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if (n == 3) {
        return 4;
    } else if (dp[n] != 0) {
        return dp[n]; // return memoized result if available
    } else {
        dp[n] = count_step(n-1) + count_step(n-2) + count_step(n-3) + count_step(n-4); // store result in memoization array
        return dp[n];
    }
}