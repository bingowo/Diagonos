#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    while(T-->0){
        int res[1111];
        res[0] = 1;
        int type[4] = {4,3,2,1};
        for(int i = 0;i <4;i++){
            for(int j = type[i];j<=100;j++){
                dp[j]+=dp[j-type[i]];
            }
        }
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",cnt);
        printf("%d\n",dp[n]);
        cnt++;
    }
}
