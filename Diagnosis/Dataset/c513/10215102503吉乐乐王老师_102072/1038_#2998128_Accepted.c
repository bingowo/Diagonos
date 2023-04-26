#include<stdio.h>
#include<stdlib.h>
int mat[201][201];
int n,m,k;
int k1,k2,k3,k4;
int cnt;
void dfs(int i,int j,int idx){
    if(i+idx<=n||i-idx>0||j+idx<=m||j-idx>0){
        if(i-idx>0&&j+idx<=m){
            for(int p=i-idx,q=j;p>=i,q<=j+idx;p++,q++){
                k1+=mat[p][q];
            }
            if(k1>=k)cnt++;
        }
        if(i+idx<=n&&j+idx<=m){
            for(int p=i+idx,q=j;p<=i,q<=j+idx;p--,q++){
                k2+=mat[p][q];
            }
            if(k2>=k)cnt++;
        }
        if(i+idx<=n&&j-idx>0){
            for(int p=i+idx,q=j;p>=i,q>=j-idx;p--,q--){
                k3+=mat[p][q];
            }
            if(k3>=k)cnt++;
        }
        if(i-idx>0&&j-idx>0){
            for(int p=i-idx,q=j;p<=i,q>=j-idx;p++,q--){
                k4+=mat[p][q];
            }
            if(k4>=k)cnt++;
        }
        dfs(i,j,idx+1);
    }
    else return ;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int ret=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            k1=k2=k3=k4=mat[i][j];
            cnt=0;
            dfs(i,j,1);
            ret+=cnt;
        }
    }
    printf("%d",ret);
}
