#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*void process(int *in, int n, int m){
    if(n == m) return 1;
    if(n < m) return 0;
    return 2*in[n-1][m]-in[n-m-1][m]+pow(2,n-1-m);
}*/


int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    long long int in[32][32] = {0};
    int most[32] = {0};

    for(int i = 1; i < 32; i++){
        for(int j = i; j < 32; j++){
            if(i < j) in[i][j] = 0;
            if(i == j) in[i][j] = 1;
        }
        most[i] = i;
    }


    while(n != -1 && m != -1){

        for(int k = most[m] + 1; k <= n; k++){
            in[k][m] = 2*in[k-1][m] - in[k-m-1][m] + pow(2,k-1-m);
        }

        printf("%lld\n",in[n][m]);
        most[m] = n;

        scanf("%d%d",&n,&m);
    }

    return 0;
}
