#include<stdio.h>
#include<stdlib.h>
int A[200][200]={0};
int dA[200][200]={0};
int MIN(int x, int y)
{
    if(x<y)
        return x;
    else 
        return y;
}
int paht(int x, int y);
{
    if((x==0)&&(y==0))
        return A[0][0];
    else if(x==0)
        return dA[0][y-1];
    else if(y==0)
        return dA[x-1][0];
    else
        return MIN(dA[x][y-1],dA[x-1][y])+A[x][y];
}
int main()
{
    int M,N;
    int i,j;
    scanf("%d%d",&M,&N);
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d",A[i][j]);
        }
    }
    dA[0][0]=A[0][0];
    printf("%d\n",dA[M][N]);
    
    return 0;
}