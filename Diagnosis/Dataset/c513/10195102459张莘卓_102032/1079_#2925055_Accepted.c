#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int n, m, k=0;
        scanf("%d %d",&n, &m);
        int s[1001] = {0}, sub[500000]={0};
        for(int i=1; i<=n; ++i) {
            scanf("%d",&s[i]);
            s[i] += s[i-1];
        }
        for(int len=1; len<=n; ++len) {
            for(int i=1; i<=n-len+1; ++i){
                sub[++k] = s[i+len-1] - s[i-1];
            }
        }
        qsort(sub+1, k-1, sizeof(int), cmp);
        int U, L;
        printf("case #%d:\n",j);
        for(int t=0; t<m; ++t){
            scanf("%d %d",&U, &L);
            long long sum = 0;
            for(int i=U; i<=L; ++i)
                sum += sub[i];
            printf("%lld\n",sum);
        }
    }
    return 0;
}
