#include<stdio.h>
#include<stdlib.h>
long long int dfs(int i,int j,int **mat,int k,int n,int m,int cnt){
    static int idx=1;
    static int k1=0,k2=0,k3=0,k4=0;
    if((i+idx<n)||(i-idx>=0)||(j+idx<m)||(j-idx>=0)){
        if(i+idx<n&&j+idx<m){
            int c=j,r=i+idx;
            for(;c<=j+idx&&r>=i;c++,r--){
                k1+=mat[r][c];
            }
            if(k1>=(k-mat[i][j]))cnt++;
        }
        if(i+idx<n&&j-idx>=0){
            int c=j-idx,r=i;
            for(;c<=j&&r<=i+idx;c++,r++){
                k2+=mat[r][c];
            }
            if(k2>=(k-mat[i][j]))cnt++;
        }
        if(i-idx>=0&&j-idx>=0){
            int c=j-idx,r=i;
            for(;c<=j&&r>=i-idx;c++,r--){
                k3+=mat[r][c];
            }
            if(k3>=(k-mat[i][j]))cnt++;
        }
        if(i-idx>=0&&j+idx<m){
            int c=j,r=i-idx;
            for(;c<=j+idx&&r<=i;c++,r++){
                k4+=mat[r][c];
            }
            if(k4>=(k-mat[i][j]))cnt++;
        }
        idx++;
        dfs(i,j,mat,k,n,m,cnt);
    }
    else{idx=1;k1=k2=k3=k4=0;return cnt;}
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