#include <stdio.h>
#include <stdlib.h>

typedef struct{
    long long int num;
    long long int minus;
}NUM;


int cmp(const void *a, const void *b){
    long long int ia = ((NUM*)a)->num, ib = ((NUM*)b)->num;
    if(ia > ib) return 1;
    if(ia < ib) return -1;
    return 0;
}


int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    /***input***/
    NUM* in = (NUM*)malloc(n*sizeof(NUM));
    for(int i = 0; i < n; i++){
        scanf("%lld",&(in[i].num));
    }

    /***ascendent_sort***/
    qsort(in,n,sizeof(in[0]),cmp);

    /***cal_minus***/
    in[0].minus = 0;
    for(int i = 1; i < n; i++){
        in[i].minus = in[i].num - in[i-1].num;
    }

    /***cal_ans***/
    long long int ans = 0, temp = 0, tempn = 0;

    for(int i = 1; i < m; i++){
            tempn += i * in[i].minus;
    }
    ans = tempn;

    for(int i = m; i < n;i++){
        temp = tempn - (in[i-1].num - in[i-m].num) + (m-1) * in[i].minus;

        if(temp < ans) ans = temp;

        tempn = temp;
        temp = 0;
    }

    /***output_ans***/
    printf("%lld",ans);

    return 0;
}
