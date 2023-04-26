#include <stdio.h>
#include <stdio.h>

int main()
{
    int M,N;
    int i,j;
    int ar[M][N];
    scanf("%d %d",&M,&N);
    char way[M + N + 1];
    for(i = 0;i < M;i++)
    {
        for(j = 0;j < N;j++)
        {
            scanf("%d",&ar[i][j]);
        }
    }
    i = 0,j = 0;
    int steps = ar[0][0],cnt = 0;
    while(i != M - 1 && j !=  N - 1)
    {
        if(ar[i + 1][j] < ar[i][j + 1])
        {
            steps += ar[i++][j];
            way[cnt++] = 'D';
        }
        else
        {
            steps += ar[i][j++];
            way[cnt++] = 'R';
        }

    }
    if(i == M - 1 && j != N - 1)
    {
        for(j;j < N - 1;j++)
        {
            steps += ar[i][j];
            way[cnt++] = 'R';
        }
    }
    else
    {
        for(i;i < M - 1;i++)
        {
            steps += ar[i][j];
            way[cnt++] = 'D';
        }
    }
    way[cnt] = '\0';
    printf("%d\n%s\n",steps,way);
    putchar('\n');


}