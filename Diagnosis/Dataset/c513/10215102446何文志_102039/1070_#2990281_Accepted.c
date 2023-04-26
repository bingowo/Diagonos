#include <stdio.h>
#include <stdlib.h>

int main()
{
//    int dp[21];memset(dp,0,21*sizeof(int));
//    dp[1] = 2;
//    dp[2] = 4;
//    dp[3] = 7;
//    for(int i = 4;i<21;i++){
//        dp[i] = 2*dp[i-1] - dp[i-2] + dp[i-3];
//    }

    int a[21];memset(a,0,21*sizeof(int));//以0结尾且不包含101
    int b[21];memset(b,0,21*sizeof(int));//以1结尾且不包含101
    a[1]=b[1]=1;
    a[2]=b[2]=2;
    a[3]=4; b[3]=3;
    for(int i = 4;i<21;i++){
        a[i] = a[i-1] + b[i-1];
        b[i] = b[i-1] + (a[i-1]-b[i-2]);
    }


    int n = 0;
    while(1){
        scanf("%d",&n);
        if(n==-1){
            break;
        }
        int res = a[n] + b[n];
        printf("%d\n",res);
    }
    return 0;
}
