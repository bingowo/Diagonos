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

         /***binary_enum***/
        long long int *a=(long long int*)malloc(N*(N+1)/2);
        memset(a,0,sizeof(long long int)*N*(N+1)/2);

        int most = log(N*(N+1)) - log(2);   //digits in bin
        int temp = 1;   //start of enum, at least one ele
        int cnt = 0;
        for(int i = 0; i < most; i++){  //enum number of ele - 1
            temp += (1<<i);     //initialize

            for(int j = 0; j < most - i; j++){  //enum how far it moves
                int jtemp = temp << j;

                for(int k = 0; k < jtemp; k++)  //enum every position
                    if(jtemp & (1<<k)) a[cnt] += n[k];  //get sum

                cnt++;
            }
        }

        /***sort***/
        qsort(a,(1<<N)-1,sizeof(long long int),cmp);

        /***output***/
        printf("case #%d:\n",R);
        for(int i = 0; i < M; i++){
            long long int ans = 0;
            for(int j = sub[i].L; j <= sub[i].U; j++)
                ans += a[j-1];
            printf("%lld\n",ans);
        }
    }
    return 0;
}
