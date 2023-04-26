#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T,R;
    scanf("%d",&T);

    for(R = 0; R < T; R++){
        int N;
        scanf("%d",&N);

        int ans = 0;
        for(int i = 1; pow(5,i) <= N; i++){
            ans += N/pow(5,i);
        }

        printf("case #%d:\n%d\n",R,ans);
    }

    return 0;
}
