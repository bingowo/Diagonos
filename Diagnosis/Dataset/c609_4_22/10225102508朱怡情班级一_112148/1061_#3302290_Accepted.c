#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int ans[200]={0};
    int k=0;
    for(int i=2;i<1000;i++){
        int flag=1;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                flag=0;
                break;
            }
        }
        if(flag)ans[k++]=i;
    }
    int n;
    scanf("%d",&n);
    long long dp[1001]={1};
    for(int i=0;ans[i]<=n;i++){
        for(int j=ans[i];j<=n;j++){
            dp[j]+=dp[j-ans[i]];
        }
    }
    printf("%lld",dp[n]);
    return 0;
}
