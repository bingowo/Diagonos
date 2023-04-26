#include <stdio.h>

int n,p,m,t;
int ans;

void dfs(int begin,int step)
{
    if(step == m){
        if(begin == t) ans++;
        return;
    }
    if(begin > 1 && begin < n) {
        dfs(begin+1,step+1);
        dfs(begin-1,step+1);
    }
    else if(begin == 1){
        dfs(2,step+1);
    }
    else{
        dfs(n-1,step+1);
    }
}

int main()
{
    int T;scanf("%d",&T);
    for(int i = 0;i < T;i++){
//        printf("case #%d:\n",i);
        scanf("%d %d %d %d",&n,&p,&m,&t);
        dfs(p,0);
        printf("%d\n",ans);
        ans = 0;
    }
}