#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int n,p,m,t;
int count[100];
int step[2]={-1,1};
//map[100]   map[1]记录到1号楼的行走方案数 map[t]记录到t号楼的行走方案数
int cal(int a){
    static depth=0;
    if(depth==m){
        count[a]++;
        return;
    }else{
        for(int i=0;i<2;i++){
            depth++;
            if(a+step[i]>0&&a+step[i]<n+1){
                cal(a+step[i]);
            }
            depth--;
        }
    }
}
int main(){
    int cas,i;
    scanf("%d",&cas);
    for(i=0;i<cas;i++){
        scanf("%d %d %d %d",&n,&p,&m,&t);
        memset(count,0,sizeof(count));
        cal(p);
        printf("%d",count[t]);
    }
}