#include<stdio.h>
#include<stdlib.h>

int count_one(a)
{
    //计数二进制中1的位数
    int n = 0, cnt = 0;
    while(a > 0){
        n = a % 2;
        a = a / 2;
        if(n == 1){
            cnt++;
        }
    }
    return cnt;
}

int cmp(long long int *a, long long int *b)
{
    int one_a;
    one_a = count_one(*a);
    int one_b;
    one_b = count_one(*b);
    if(one_a != one_b){
        return one_a - one_b;
    }
    else{
        return *b - *a;
    }
}

int main()
{
    int T,i;
    scanf("%d",&T);
    getchar();
    for(i = 0; i < T; i++){
        int N = 0;
        scanf("%d",&N);
        getchar();
        long long int n[10000];
        int j = 0;
        for(j = 0; j < N; j++){
            scanf("%lld",&n[j]);
        }
        qsort(n[0],sizeof(n)/sizeof(n[0]),sizeof(n[0]),cmp);
        printf("case #%d:\n",i);
        for(j = 1; j < sizeof(n)/sizeof(n[0]);j++){
            long long int t = n[j];
            printf("%lld",t);
            if(j < sizeof(n)/sizeof(n[0])-1){
                printf(" ");
            }
            else{
                printf("\n");
            }
        }
    }
    return 0;
}
