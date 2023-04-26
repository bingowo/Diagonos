#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct {int val; char dir;} Elem;
void shortestpath(Elem A[][SIZE],int M,int N){
    int i,j;
    for(i=1;i<M;i++){
        A[i][0].val+=A[i-1][0].val;//计算第一列的路程
        A[i][0].dir='D'//向下走
    }
    for(i=1;i<N;i++){
        A[0][i].val+=A[i-1][0.val;
        A[0][i].dir='R';
    }
    for(i=1;i<M;i++){
        for(j=1;j<N;j++){
            if(A[i-1][j].val<A[i][j-1].val){
                A[i][j].val+=A[i-1][j].val;//向下移动
                A[i][j].dir='D';
            }else{
                //向右移动
                A[i][j].val+=A[i][j-1].val;
                A[i][j].dir='R';
            }
        }
    }
}
void outpath(Elem A[][SIZE],int r,int c){//递归输出到A[r][c]的最短路径
    if(r==0&&c==0) return;
    if(A[r][c].dir=='D'){
        outpath(A,r-1,c);
        putchar('D');
    }else{
        outpath(A,r,c-1);
        putchar('R');
    }
}
int main(){
    Elem A[SIZE][SIZE];
    int M,N;
    int i,j;
    scanf("%d %d",&M,&N);
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%d",&A[i][j].val);
            A[i][j].dir=0;
        }
    }
    shortestpath(A,M,N);
    printf("%d\n",A[M-1][N-1].val);
    outpath(A,M-1,N-1);
    putchar('\n');
    return 0;
}