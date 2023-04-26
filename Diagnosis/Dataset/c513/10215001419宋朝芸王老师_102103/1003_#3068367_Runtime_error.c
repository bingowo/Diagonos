#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define M 65
#define N 38

typedef struct{
    long long int a;
    int one;
}NUM;

int count1(long long int a){
    /*case 1*/
    if(a == 0) return 0;

    //all positive
    int res = 0;

    for(int i = 0; i < M; i++){
        if((a & ((long long int)1 << i)) != 0) res++;
    }

    return res;
}

int cmp(const void *a, const void *b){
    NUM c = *(NUM*)a, d = *(NUM*)b;
    if(c.one != d.one) return d.one - c.one;
    return c.a - d.a;
}

int main()
{
    int r,t;
    scanf("%d",&t);
    for(r = 0;r < t; r++){

        /*initialize*/
        long long int n;
        scanf("%lld",&n);

        NUM *num;
        num = malloc(sizeof(NUM)*n);
        memset(num,0,sizeof(NUM)*n);

        /*input*/
        for(int i = 0; i < n; i++){
            char s[N] = {'\0'};
            int cnt = 0;

            scanf("%lld",num[i].a);
            num[i].one = count1(num[i].a);
        }

        /*sort*/
        qsort(num,n,sizeof(NUM),cmp);

        /*output*/
        printf("case #%d:\n",r);
        printf("%lld",num[0].a);
        for(int i = 1; i < n; i++){
            printf(" %lld",num[i].a);
        }
        printf("\n");
    }

    return 0;
}
