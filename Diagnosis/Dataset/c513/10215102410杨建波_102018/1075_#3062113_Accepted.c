#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int elem;
    char dir;
}Dir;

int M, N;
Dir **p;


void shortway(Dir** p, int M, int N){
    for(int i = 1;i < M;i++){
        p[i][0].elem += p[i-1][0].elem;
        p[i][0].dir = 'D';
    }  

    for(int i = 1;i < N;i++){
        p[0][i].elem += p[0][i-1].elem;
        p[0][i].dir = 'R';
    }
         
    for(int i = 1;i < M;i++){
        for(int j = 1;j < N;j++){
            if(p[i-1][j].elem < p[i][j-1].elem){
                p[i][j].elem += p[i-1][j].elem;
                p[i][j].dir= 'D';
            }
            else{
                p[i][j].elem += p[i][j-1].elem;
                p[i][j].dir = 'R';
            }
        }
    }
    
}

void showway(Dir** p, int M, int N){
    if(M == 1 && N == 1){
        return;
    }
    if(p[M-1][N-1].dir == 'D'){
        showway(p, M-1, N);
        printf("D");
    }
    else{
        showway(p, M, N-1);
        printf("R");
    }
}

int main(){
    scanf("%d %d", &M, &N);
    int cnt = 0;
    p = (Dir**)malloc(M * sizeof(Dir*));
    for(int i = 0;i < N;i++){
        p[i] = (Dir*)malloc(N * sizeof(Dir));
    }
    for(int i = 0;i < M;i++){
        for(int j = 0; j < N;j++){
            scanf("%d",&p[i][j].elem);
            p[i][j].dir = 0;
        }
    }
    shortway(p, M, N);
    printf("%d\n",p[M-1][N-1].elem);
    showway(p, M, N); 
}