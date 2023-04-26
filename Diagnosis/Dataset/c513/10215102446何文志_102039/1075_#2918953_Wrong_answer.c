#include <stdio.h>
#include <stdlib.h>

int main()
{
    int M = 0,N = 0;
    scanf("%d%d",&M,&N);
    int A[M][N];memset(A,0,M*N*sizeof(int));
    for(int i = 0;i<M;i++)
    {
        for(int j = 0;j<N;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }

    int val[M][N];memset(val,0,M*N*sizeof(int));
    val[0][0] = A[0][0];
    for(int i = 1;i<M;i++)
    {
        val[i][0] = val[i-1][0] + A[i][0];
    }
    for(int j = 1;j<N;j++)
    {
        val[0][j] = val[0][j-1] + A[0][j];
    }

    char s[1000];memset(s,0,1000*sizeof(char));
    int cnt = 0,ans = 0;

    for(int i = 1;i<M;i++)
    {
        for(int j = 1;j<N;j++)
        {
            if(val[i][j-1]<val[i-1][j])//left < up
            {
                val[i][j] = val[i][j-1]+A[i][j];
            }
            else//left >= up
            {
                val[i][j] = val[i-1][j]+A[i][j];
            }
        }
    }

    int i1 = 0,j1 = 0;
    while(!((i1==M-1)&&(j1==N-1)))
    {
        if(i1 == M-1)//lase row
        {
            s[cnt] = 'R';
            //printf("val[%d][%d] = %d, R\n",i1,j1,val[i1][j1]);
            j1++;
            cnt++;
            continue;
        }
        else if(j1 == N-1)//last column
        {
            s[cnt] = 'D';
            //printf("val[%d][%d] = %d, D\n",i1,j1,val[i1][j1]);
            i1++;
            cnt++;
            continue;
        }
        if(val[i1][j1+1]<val[i1+1][j1])
        {
            s[cnt] = 'R';
            //printf("val[%d][%d] = %d, R\n",i1,j1,val[i1][j1]);
            j1++;
            cnt++;
            continue;
        }
        else
        {
            s[cnt] = 'D';
            //printf("val[%d][%d] = %d, D\n",i1,j1,val[i1][j1]);
            i1++;
            cnt++;
            continue;
        }
    }
    ans = val[M-1][N-1];
    //printf("cnt = %d\n",cnt);

    for(int i = 0;i<M;i++)
    {
        for(int j = 0;j<N;j++)
        {
            //printf("val[%d][%d] = %d, A[%d][%d] = %d    "
            //       ,i,j,val[i][j],i,j,A[i][j]);
        }
        //printf("\n");
    }

    printf("%s\n%d",s,ans);
    return 0;
}
