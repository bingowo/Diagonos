#include <stdio.h>
#define N 10007
long long A[2000][2000];
int main()
{
    int t;
    scanf("%d",&t);
    for(int s = 0; s < t; s++)
    {
        int a,b,k,n,m;
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        a %= 10007;
        b %= 10007;
        A[0][0] = 1;
        for(int i = 1; i <= k; i++)
        {
            A[i][0] = (A[i-1][0] * a) % N;
            A[0][i] = (A[0][i-1] * b) % N;
        }
        for(int i = 1; i <= k; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                A[i][j] = (a * A[i-1][j] + b * A[i][j-1]) % N;
            }
        }
        printf("case #%d:\n",s);
        printf("%lld\n",A[n][m]);
    }
    return 0;
}

