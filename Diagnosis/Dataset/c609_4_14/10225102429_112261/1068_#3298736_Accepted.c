#include <stdio.h>
#include <string.h>
#define N 101
long long height[N];
int n,p,m,t;
void dfs(int x,int u){
    if(x<=0||x>n||u>m) return;
    if(u==m) {
        height[x]++;
        return ;
    }
    dfs(x+1,u+1);
    dfs(x-1,u+1);
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&p,&m,&t);
        dfs(p,0);
        printf("%lld\n",height[t]);
        memset(height,0,sizeof height);
    }
    return 0;
}