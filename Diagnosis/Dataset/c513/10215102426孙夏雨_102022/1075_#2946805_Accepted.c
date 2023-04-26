#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int val;
    char dir;
}Elem;

void shortpath(Elem p[][200],int M,int N)
{
    for(int i=1;i<M;i++){
        p[i][0].val+=p[i-1][0].val;
        p[i][0].dir='D';
    }
    for(int j=1;j<N;j++){
        p[0][j].val+=p[0][j-1].val;
        p[0][j].dir='R';
    }
    for(int i=1;i<M;i++){
        for(int j=1;j<N;j++){
            if(p[i-1][j].val<p[i][j-1].val){
                p[i][j].val+=p[i-1][j].val;
                p[i][j].dir='D';
            }
            else {
                p[i][j].val+=p[i][j-1].val;
                p[i][j].dir='R';
            }
        }
    }
}

void outpath(Elem p[][200],int M,int N,int r,int c)
{
    if(r==0&&c==0) return;
    if(p[r][c].dir=='D'){
        outpath(p,M,N,r-1,c);
        printf("D");
    }
    else {
        outpath(p,M,N,r,c-1);
        printf("R");
    }
}

int main()
{
    int M=0,N=0;
    scanf("%d %d",&M,&N);
    Elem p[200][200];
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&p[i][j].val);
            p[i][j].dir=0;
        }
    }
    shortpath(p,M,N);
    printf("%d\n",p[M-1][N-1].val);
    outpath(p,M,N,M-1,N-1);
    printf("\n");
    return 0;
}
