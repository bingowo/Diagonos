#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
    int L;int U;
}SUB;

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){

        /***input***/
        int N,M;
        scanf("%d%d",&N,&M);

        int n[500501];
        SUB sub[500501];

        for(int i = 1; i < N; i++){
            scanf("%d",&n[i]);
            n[i] += n[i-1];
        }

        for(int i = 1; i < M; i++)
            scanf("%d%d",&sub[i].L,&sub[i].U);


        long long int a[500501] = {0};
        int cnt = 0;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N - i + 1; j++){
                a[++cnt] = (long long int)n[j + i - 1] - (long long int)n[j - 1];
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
            printf("%lld\n",a[sub[i].U] - a[sub[i].L - 1]);
        }
    }
    return 0;
}
