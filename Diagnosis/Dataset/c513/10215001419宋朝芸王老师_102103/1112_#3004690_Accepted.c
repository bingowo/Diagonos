#include <stdio.h>
#include <stdlib.h>
#define M 1000
int main()
{
    unsigned long long int index[M+1] = {0};
    index[0] = 1;
    int type[4] = {1,2,3,4};
    for(int i = 0; i < 4; i++){
        for(int j = type[i]; j < M+1; j++){
            index[j] += index[j - type[i]];
        }
    }

    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        int n;
        scanf("%d",&n);
        printf("%llu\n",index[n]);
    }
    return 0;
}
