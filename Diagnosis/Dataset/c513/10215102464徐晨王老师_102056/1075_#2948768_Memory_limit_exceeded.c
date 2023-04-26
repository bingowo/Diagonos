#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int path(int x,int y,int M,int N,char** psum){
    if(psum[x+1,y]!=-1&&psum[x,y+1]!=-1){
        psum[x,y]=psum[x+1]>psum[x,y+1]?psum[x,y+1]:psum[x+1,y];
    }
    else {
        psum[x,y]=path(x+1,y,M,N,psum)>path(x,y+1,M,N,psum)?path(x,y+1,M,N,psum):path(x+1,y,M,N,psum);
    }
    if(x>=M-1||y>=N-1)return;
    if(x==M-1&&y==N-1)return psum[x,y];
}

int main(){
    int M,N;
    scanf("%d%d",&M,&N);
    int tran[M][N];
    int psum[M][N];
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&tran[i][j]);
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            psum[i][j]=-1;
        }
    }
    psum[M-1][N-1]=tran[M-1][N-1];
    printf("%d",path(0,0,M,N,psum));
}
