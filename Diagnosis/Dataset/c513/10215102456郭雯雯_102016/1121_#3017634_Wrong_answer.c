#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int w[n+1],sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    int ans[n+1][sum+1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=sum;j++)ans[i][j]=0;
    ans[1][w[1]]=1;
    for(int i=2;i<=n;i++){
        int t=w[i];
        ans[i][t]=1;
        for(int j=1;j<=sum;j++)ans[i][j]=ans[i-1][j];
        for(int j=1;j<=sum;j++){
            if(ans[i-1][j]==1){
                ans[i][j+t]=1;
                ans[i][abs(t-j)]=1;
            }
        }
    }
    for(int j=1;j<=sum;j++)printf("%d",ans[n][j]);
    printf("\n");
}