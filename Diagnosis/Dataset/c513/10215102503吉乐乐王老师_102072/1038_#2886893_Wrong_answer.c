#include<stdio.h>
#include<stdlib.h>
long long int dfs(int i,int j,int **mat,int k,int n,int m,int cnt){
    static int idx=1;
    static int k1=0,k2=0,k3=0,k4=0;
    if(i+idx<n&&j+idx<m){
        if((k1+=mat[i][j+idx]+mat[i+idx][j])>=(k-mat[i][j]))cnt++;
    }
    if(i+idx<n&&j-idx>=0){
        if((k2+=mat[i][j-idx]+mat[i+idx][j])>=(k-mat[i][j]))cnt++;
    }
    if(i-idx>=0&&j-idx>=0){
        if((k3+=mat[i-idx][j]+mat[i][j-idx])>=(k-mat[i][j]))cnt++;
    }
    if(i-idx>=0&&j+idx<m){
        if((k4+=mat[i-idx][j]+mat[i][j+idx])>=(k-mat[i][j]))cnt++;
    }
    idx++;
    if((i+idx>=n)&&(i-idx<0)&&(j+idx>=m)&&(j-idx<0)){
        idx=1;k1=k2=k3=k4=0;return cnt;}
    return dfs(i,j,mat,k,n,m,cnt);
}
int main(){
    int n,m,k;
    scanf("%d %d %d\n",&n,&m,&k);
    int **mat=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        mat[i]=(int *)malloc(sizeof(int)*m);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)scanf("%d",&mat[i][j]);
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        cnt+=dfs(i,j,mat,k,n,m,0);
    }
    printf("%d",cnt);
}