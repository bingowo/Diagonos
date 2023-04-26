#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int ret=0;
void dfs(int n,int p,int m,int t){//递归：每次都当成一次
    if(m==0&&p==t)ret++;
    if(m<=0)return;
    if(p==1){
        dfs(n,p+1,m-1,t);
    }
    else if(p==n){
        dfs(n,p-1,m-1,t);
    }
    else{
        dfs(n,p+1,m-1,t);
        dfs(n,p-1,m-1,t);}
}
int main(){
    int cas;
    scanf("%d",&cas);getchar();
    while(cas--){
        int n,p,m,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        ret=0;
        dfs(n,p,m,t);
        printf("%d\n",ret);
    }
}