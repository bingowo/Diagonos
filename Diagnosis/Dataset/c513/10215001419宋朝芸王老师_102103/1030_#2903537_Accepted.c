#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    long long int fa = *(long long int*)a, fb = *(long long int*)b;
    if(fa < 0) fa = -fa;
    if(fb < 0) fb = -fb;

    while(fa >= 10) fa /= 10;
    while(fb >= 10) fb /= 10;

    if(fa != fb) return (int)(fb-fa);
    if(*(long long int*)a > *(long long int*)b) return 1;
    if(*(long long int*)a < *(long long int*)b) return -1;
    return 0;

}

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        int N;
        scanf("%d",&N);

        long long int *input = (long long int*)malloc(N*sizeof(long long int));
        for(int i = 0; i < N; i++){
            scanf("%lld",&input[i]);
        }

        qsort(input,N,sizeof(long long int),cmp);

       printf("case #%d:\n",R);
       printf("%lld",input[0]);
       for(int i = 1; i < N; i++){
            printf(" %lld",input[i]);
       }
       printf("\n");

    }
    return 0;
}
