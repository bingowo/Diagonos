#include <stdio.h>
#define N 10007
int main()
{
    int t;
    scanf("%d",&t);
    long long A[N][N];
    for(int i = 0; i < t; i++)
    {
        long long a,b;
        int k,n,m;
        scanf("%lld %lld %d %d %d",&a,&b,&k,&n,&m);
        A[0][0] = 1;
        for(int i = 1; i <= k; i++)
        {
            A[i][0] = A[i-1][0] * a % N;
        }
        for(int i = 1; i <= k; i++)
        {
            A[0][i] = A[0][i-1] * b % N;
        }
        for(int i = 1; i <= k; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                A[i][j] = (a * A[i-1][j] + b * A[i][j-1]) % N;
            }
        }
        printf("case #%d:\n",i);
        printf("%lld\n",A[n][m]);
    }
    return 0;
}

