#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 51

long long int f[N];

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        f[0] = 1;
        printf("case #%d:\n",i);
        int res;scanf("%d",&res);
        for(int j = 1;j <= res;j++){
            for(int k = 1;k <= 4;k++){
                if(j >= k){
                    f[j] += f[j-k];
                }
            }
        }
        printf("%lld\n",f[res]);
        memset(f,0,sizeof(f));
    }
}