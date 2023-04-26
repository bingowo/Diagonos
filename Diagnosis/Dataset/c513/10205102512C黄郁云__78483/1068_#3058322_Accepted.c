//dp
#include <stdio.h>
#include <math.h>

int dp[32];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    while(n != -1 && m!= -1){
        for(int i = 0; i <32;i++){
            dp[i] = 0;
        }
        for(int i = 1; i <= n;i++){
            if(i < m){
                dp[i] = pow(2,i);
            }else if( i == m){
                dp[i] = pow(2,i)-1;
            }else{
                for(int j = i-1; j > i-m-1;j--){
                    dp[i]+=dp[j];
                }
            }
        }
        int k= pow(2,n)-dp[n];
        printf("%d\n",k);
        scanf("%d %d",&n,&m);
    }
}