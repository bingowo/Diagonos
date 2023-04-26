#include <stdio.h>

int main()
{
    long long cnt[51] = {0,1,2,4,8};
    for(int i=5; i<=50; ++i){
        cnt[i] = cnt[i-1] + cnt[i-2] + cnt[i-3] + cnt[i-4];
    }
    int T, n;
    scanf("%d",&T);
    for(int i=0; i<T; ++i) {
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,cnt[n]);
    }
    return 0;
}