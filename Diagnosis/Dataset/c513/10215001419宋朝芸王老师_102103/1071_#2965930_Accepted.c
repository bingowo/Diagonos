#include <stdio.h>
#include <stdlib.h>
#define N 10007

int main()
{
    int R,T;
    scanf("%d",&T);

    for(R = 0; R < T; R++){
        int a,b,k,n,m;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);

        long long int in[1001][1001] = {0};
        in[0][0] = 1;

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){

                if(i + j == 0) continue;

                if(i == 0)
                    in[i][j] = b*in[i][j-1] % N;
                else if(j == 0)
                    in[i][j] = a*in[i-1][j] % N;
                else
                    in[i][j] = (a*in[i-1][j] + b*in[i][j-1]) % N;
            }
        }

        printf("case #%d:\n%lld\n",R,in[n][m]);

    }

    return 0;
}
