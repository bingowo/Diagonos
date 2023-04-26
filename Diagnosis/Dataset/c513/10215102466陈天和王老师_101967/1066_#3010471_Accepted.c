
#include <stdio.h>
int dfs(int n,int p,int m,int t);
int main(){
    int cas,n,p,t,m;
    scanf("%d",&cas);
    for(int _=0;_<cas;_++){
        scanf("%d%d%d%d",&n,&p,&m,&t);
        printf("%d\n",dfs(n,p,m,t));
    }
}
//n总数，p起点，m分钟，t终点
//没对一些不合理数据进行特殊处理
int dfs(int n,int p,int m,int t){
    int ret=-1;
    if(m==0){
        if(p==t) ret=1;
        else ret=0;
    }
    else{
        if(p==1) ret = dfs(n,2,m-1,t);
        else if(p==n) ret = dfs(n,n-1,m-1,t);
        else ret = dfs(n,p-1,m-1,t)+ dfs(n,p+1,m-1,t);
    }
    return ret;
}