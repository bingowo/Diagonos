//另一种方法，动态规划
#include <stdio.h>

//一定要降序排列
int factor[4] = {4,3,2,1};

int dfs(int n,int cur);
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
    int n;
    scanf("%d",&n);
    printf("%d\n",dfs(n,0));
    }
    return 0;
}

int dfs(int n,int cur){
    if(cur==3) return 1;
    int ret = 0;
    for (int i = 0; i*factor[cur]<=n; i++) {
        ret+=dfs(n-i*factor[cur],cur+1);
    }
    return ret;
}