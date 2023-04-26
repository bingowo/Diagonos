#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*看n,m之间的差距，m为全一字符串之后，f（n，m）转化成f（n+1，m），
可以直接在后面加0/1，或者是m-1个全一字符+倒数第m的字符为0，
后面加1满足条件，前面的数随便选，但是要注意n-m-1个字符中有m的情况，（
已经包含在f（n，m）中
f（n+1，m）=2*f（n，m）+2^(n-m)-f(n-m,m)*/
int mul(int i)
{
    int cnt=1;
    for(int k=0;k<i;k++){cnt*=2;}
    return cnt;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(n!=-1&&m!=-1){
        int dp[n-m+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n-m;i++){
            if(i>=1+m)dp[i]=2*dp[i-1]+mul(i-1)-dp[i-1-m];
            else dp[i]=2*dp[i-1]+mul(i-1);
        }
        printf("%d\n",dp[n-m]);
        scanf("%d%d",&n,&m);
    }
    return 0;
}
