#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int T;
    scanf("%d",&T);

    for(int R = 0; R < T; R++){
        int N;
        scanf("%d",&N);

        unsigned long long ans = 0;
        ans = pow(2,N);

        printf("case #%d:\n%llu\n",R,ans);
    }

    return 0;
}
