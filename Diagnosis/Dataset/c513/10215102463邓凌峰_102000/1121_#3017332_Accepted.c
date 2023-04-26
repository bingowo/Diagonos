#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 1000
#define BigNUm 10007
#define N 100000

void dfs(int *ans,int *weights,int pos,int sum,int n){
    if(sum>0) ans[sum]=1;
    if(pos==n) return;
    dfs(ans,weights,pos+1,sum,n);
    dfs(ans,weights,pos+1,sum+weights[pos],n);
    dfs(ans,weights,pos+1,sum-weights[pos],n);
}

int main(){
    int n;scanf("%d",&n);
    int weights[n];
    memset(weights,0,sizeof(weights));
    int max=0;
    for(int k=0;k<n;k++){
        scanf("%d",&weights[k]);
        max+=weights[k];
    }
    int ans[LEN]={0};
    dfs(ans,weights,0,0,n);
    for(int k=1;k<=max;k++){
        printf("%d",ans[k]);
    }
    return 0;
}

