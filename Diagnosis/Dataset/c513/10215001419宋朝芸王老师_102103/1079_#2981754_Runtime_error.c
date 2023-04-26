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

        int *n = (int*)malloc(N*sizeof(int));
        SUB *sub= (SUB*)malloc(M*sizeof(SUB));

        for(int i = 0; i < N; i++)
            scanf("%d",&n[i]);
        for(int i = 0; i < M; i++)
            scanf("%d%d",&sub[i].L,&sub[i].U);

        /*
        /binary_enum/
        long long int *a=(long long int*)malloc(N*(N+1)/2);
        memset(a,0,sizeof(long long int)*N*(N+1)/2);

        int digits = 0;
        while((1 << digits) <= N*N) digits++;
        int cnt = 0;
        for(int i = 1; i <= digits; i++){  //enum number of ele
            for(int j = 0; j <= digits - i; j++){  //enum how far it moves
                int jtemp = (((1 << i)-1) << j);
                for(int k = 0; k <= jtemp; k++)  //enum every position
                    if(jtemp & (1<<k)) a[cnt] += n[k];  //get sum
                cnt++;
            }
        }
        */

        long long int a[500501] = {0};
        int cnt = 0;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N - i + 1; j++){
                a[++cnt] = n[j + i - 1] - n[j - 1];
            }
        }

        /***sort***/
        qsort(a,cnt,sizeof(long long int),cmp);

        /**cal_sum***/
        long long int *sum = (long long int*)malloc(N*(N+1)/2*sizeof(long long int));
        sum[0] = 0;
        for(int i = 1; i <= N*(N+1)/2;i++)
            sum[i] = sum[i-1] + a[i-1];

        /***output***/
        printf("case #%d:\n",R);
        for(int i = 0; i < M; i++){
            printf("%lld\n",sum[sub[i].U] - sum[sub[i].L - 1]);
        }
    }
    return 0;
}
