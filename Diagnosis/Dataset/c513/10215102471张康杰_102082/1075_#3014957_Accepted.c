#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int steps,signal;
    char move[500];
}STEP;

STEP record[201][201];
int ar[201][201];

STEP f(int n,int m)
{
    STEP out,out1,out2;
    if(record[n][m].signal != 0)
        return record[n][m];
    if(n == 0 && m == 0)
    {
        out.signal = 1;
        out.steps = ar[0][0];
        record[0][0] = out;
        return out;
    }
    else if(n != 0 && m == 0)
    {
        out = f(n - 1,m);
        out.steps += ar[n][m];
        sprintf(out.move,"%s%c",out.move,'D');
        record[n][m] = out;
        return out;
    }
    else if(n == 0 && m != 0)
    {
        out = f(n,m - 1);
        out.steps += ar[n][m];
        sprintf(out.move,"%s%c",out.move,'R');
        record[n][m] = out;
        return out;
    }
    out1 = f(n - 1,m);
    out2 = f(n,m - 1);
    if(out1.steps + ar[n][m] > out2.steps + ar[n][m])
    {
        out.steps = out2.steps + ar[n][m];
        out.signal = 1;
        sprintf(out.move,"%s%c",out2.move,'R');
    }
    else
    {
        out.steps = out1.steps + ar[n][m];
        out.signal = 1;
        sprintf(out.move,"%s%c",out1.move,'D');
    }
    record[n][m] = out;
    return out;
}

int main()
{
    int M,N,i,j;
    scanf("%d %d",&M,&N);
    memset(record,0,sizeof(STEP) * 201 * 201);
    for(i = 0;i < M;i++)
    {
        for(j = 0;j < N;j++)
        {
            scanf("%d",&ar[i][j]);
        }
    }
    f(M - 1,N - 1);
    printf("%d\n%s\n",record[M - 1][N - 1].steps,record[M - 1][N - 1].move);
    return 0;

}