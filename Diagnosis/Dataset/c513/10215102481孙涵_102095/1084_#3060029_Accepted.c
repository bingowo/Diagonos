#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        int N;
        scanf("%d",&N);
        long long int ans;
        ans = (1<<N);
        printf("case #%d:\n",t);
        printf("%lld\n",ans);

    }
    return 0;
}
