#include <stdio.h>
#include <stdlib.h>
int min(int a, int b)
{
    return a>b?b:a;
}
int num[201][201];
int dis[201][201];
int main()
{
    int M,N;
    scanf("%d %d",&M,&N);
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&num[i][j]);
    dis[0][0]=num[0][0];
    for(int i=1; i<M; i++)
        dis[i][0] = dis[i-1][0]+ num[i][0];     //对于第一列的点D[i][0]，只可能是从上面的点D[i-1][0]往下走
    for(int j=1; j<N; j++)
        dis[0][j] = dis[0][j-1]+ num[0][j];     //对于第一行的点D[0][j]，只可能是从左边的点D[0][j-1]往右走
    for(int i=1; i<M; i++)
        for(int j=1; j<N; j++)              //点D[i][j]，是从D[i][j-1]和D[i-1][j]较小的而来
            dis[i][j] = min(dis[i-1][j],dis[i][j-1]) + num[i][j];
    printf("%d\n",dis[M-1][N-1]);
    int i=0;
    int j=0;
    while((i<M-1)||(j<N-1))
    {
        if(i==M-1)
        {
            printf("R");
            j++;
        }
        else if(j==N-1)
        {
            printf("D");
            i++;
        }
        else if(dis[i+1][j]<dis[i][j+1])
        {
            printf("D");
            i++;
        }
        else if(dis[i+1][j]>dis[i][j+1])
        {
            printf("R");
            j++;
        }
    }

    return 0;
}
