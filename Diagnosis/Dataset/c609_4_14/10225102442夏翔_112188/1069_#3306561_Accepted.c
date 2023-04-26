//dp
#include<stdio.h>
#include<string.h>
int dp[33];  //dp[i]表示长度i，含m个1子串的个数
int main(){
    int n, m, temp;
    scanf("%d %d", &n, &m);
    while(n != -1){
        memset(dp, 0, sizeof(dp));
        dp[m] = 1;
        temp = 1;
        for(int i = m+1; i <= n; i ++){
            if(i-m-1 >= m && m != 1)  //需要确保最后m位全为1时，前面的字符没有符合题意的
                dp[i] = 2*dp[i-1]+temp-dp[i-m-1];
            else dp[i] = 2*dp[i-1] + temp;
            if(m != 1) temp *= 2; //注意考虑特殊的1
            //2*dp[i-1]为当前i位放1 0的情况
            //temp为当前第i位为1的情况,相当于最后m位均为1(且不算第i位时，不符合题意)，temp是前面的可能性
        }
        printf("%d\n", dp[n]);
        scanf("%d %d", &n, &m);
    }
    return 0;
}