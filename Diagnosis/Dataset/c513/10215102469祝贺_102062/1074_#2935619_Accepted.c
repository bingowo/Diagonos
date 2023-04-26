#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define mole 1000000007
int dp2[101][101];//记录第i位到第j位的数字对210的模
long long dp1[101][210];//记录0-第j位为止模210所有可能方案数
int f(int x){
    return x<0?-x:x;
}
int main()
{
    int pro;scanf("%d",&pro);
    for(int index=0;index<pro;index++){
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        char s[105];scanf("%s",s);int len=strlen(s);
        dp1[0][s[0]-'0']=1;dp2[0][0]=s[0]-'0';
        for(int i=1;i<len;i++){
            int t=s[i]-'0';
            /*for(int j=0;j<210;j++){
                if(dp1[i-1][j]!=0){
                    dp1[i][f(j+t)%210]=(dp1[i][f(j+t)%210]+dp1[i-1][j])%mole;
                    dp1[i][f(j-t)%210]=(dp1[i][f(j-t)%210]+dp1[i-1][j])%mole;
                }
            }*/
            for(int j=0;j<=i;j++){//最后+-号位置后一位的数字的位置
                if(j<i)dp2[j][i]=(dp2[j][i-1]*10+t)%210;
                else dp2[j][i]=t;
                if(j==0){
                    dp1[i][f(dp2[j][i]) % 210] = (dp1[i][f(dp2[j][i]) % 210] + 1) % mole;
                }
                else{
                    for(int k=0;k<210;k++) {
                        if (dp1[j-1][k] != 0) {
                            dp1[i][f(k + dp2[j][i]) % 210] = (dp1[i][f(k + dp2[j][i]) % 210] + dp1[j-1][k]) % mole;
                            dp1[i][f(k - dp2[j][i]) % 210] = (dp1[i][f(k - dp2[j][i]) % 210] + dp1[j-1][k]) % mole;
                        }
                    }
                }
            }
        }
        long long ans=0;
        for(int i=0;i<210;i++){
            if(i%2==0 || i%3==0 || i%5==0 || i%7==0)
                ans+=dp1[len-1][i];
        }
        printf("%lld\n",ans%mole);
    }

    return 0;
}