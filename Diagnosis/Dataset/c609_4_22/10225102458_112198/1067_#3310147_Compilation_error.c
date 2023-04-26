#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sta{
    int cura;
    int upa;
    int curb;
    int upb;

}STA;
int main()
{
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    STA dp[x+1];
    dp[1].cura=1;dp[1].upa=1;
    dp[1].curb=0;dp[1].upb=0;
    dp[2].cura=1;dp[2].upa=0;
    dp[2].curb=0;dp[2].upb=1;
    for(int i=3;i<=x;i++){
        dp[i].upa=dp[i-1].upa+dp[i-2].upa;
        dp[i].upb=dp[i-1].upb+dp[i-2].upb;
        dp[i].cura=dp[i-1].cura+dp[i-2].upa;
        dp[i].curb=dp[i-1].curb+dp[i-2].upb;
    }
    dp[n-1].curb
    if(x!=n)printf("%d",dp2[x]);
    else printf("0");
    return 0;

}
