#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main()
{
    int R,T;
    scanf("%d",&T);

    static long long int n[1001] = {0};
    static long long int a[500501] = {0};

    for(R = 0; R < T; R++){

        /***input***/
        int N,M,L,U;
        scanf("%d%d",&N,&M);

        n[0] = 0;
        for(int i = 1; i <= N; i++){
            scanf("%lld",&n[i]);
            n[i] += n[i-1];
        }

        /***cal***/
        a[0] = 0;
        int cnt = 0;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N - i + 1; j++){
                a[++cnt] = n[j + i - 1] - n[j - 1];
            }
        }

        /***sort***/
        qsort(a,cnt,sizeof(long long int),cmp);

        /**cal_sum***/
        for(int i = 1; i <= cnt; i++)
            a[i] += a[i-1];

        /***output***/
        printf("case #%d:\n",R);
        for(int i = 0; i < M; i++){
            scanf("%d%d",&L,&U);
            printf("%lld\n",a[U] - a[L - 1]);
        }
    }
    return 0;
}
