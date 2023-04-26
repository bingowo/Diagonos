#include <stdio.h>
#include <stdlib.h>

struct data{
    int val;
    char dir;
};


void shortestpath(struct data s[200][200],int M, int N);
void output(struct data s[200][200],int M, int N,int r, int c);


int ans_val = 0;

char ans_dir[401];


int main()
{
    int M, N;
    scanf("%d %d",&M,&N);
    struct data s[200][200];
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            scanf("%d",&s[i][j]);
        }
    }
    shortestpath(s,M,N);
    printf("%d\n",s[M-1][N-1].val);
    output(s,M,N,M-1,N-1);
    printf("\n");
    return 0;
}

void shortestpath(struct data s[200][200],int M, int N){
    int i,j;
    for(i = 0; i < M; i++){
        s[i][0].val = s[i-1][0].val + s[i][0].val;
        s[i][0].dir = 'D';
    }
    for(i = 0; i < N; i++){
        s[0][i].val = s[0][i-1].val + s[0][i].val;
        s[0][i].dir = 'R';
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(s[i-1][j].val<s[i][j-1].val)
            {
                s[i][j].val += s[i-1][j].val;
                s[i][j].dir = 'D';
            }else{
                s[i][j].val += s[i][j-1].val;
                s[i][j].dir = 'R';
            }
        }
    }
}

void output(struct data s[200][200],int M, int N,int r, int c){
    if(r==0 && c == 0) return;
    if(s[r][c].dir == 'D')
    {
        output(s,M,N,r-1,c);
        putchar('D');
    }
    else
    {
        output(s,M,N,r,c-1);
        putchar('R');

    }
}
