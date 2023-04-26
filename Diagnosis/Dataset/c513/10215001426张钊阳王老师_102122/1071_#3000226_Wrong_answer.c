#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



long long arr[2000][2000];


int main()
{
    long long  t;
    scanf("%lld",&t);
    for(long long i = 0; i < t; i++)
    {
        long long a,b,k,n,m;
        scanf("%lld %lld %lld %lld %lld",&a,&b,&k,&n,&m);

        a %= 10007;
        b %= 10007;

        arr[0][0] = 1;
        for(long long i = 1; i <= k; i++)
        {
            arr[i][0] = arr[i - 1][0] * a % 10007;
        }
        for(long long i = 1; i <= k; i++)
        {
            arr[0][i] = arr[0][i - 1] * b % 10007;
        }

        for(long long i = 1; i <= k; i++)
        {
            for(long long j = 1; j <= k; j++)
            {
                arr[i][j] = (a * arr[i - 1][j] + b * arr[i][j - 1]) % 10007;
                //斜着看就是杨辉三角了
            }
        }
        printf("case #%d:\n",i);
        printf("%lld",arr[n][m]);
    }

    return 0;
}

