#include <stdio.h>
#include <stdlib.h>

typedef struct{
    long long int num;
    long long int minus;
}NUM;


int cmp(const void *a, const void *b){
    long long int ia = (NUM*)a->num , ib = (NUM*)b->num;
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
        scanf("%lld",&NUM[i].num);
    }

    /***ascendent_sort***/
    qsort(in,n,sizeof(in[0]),cmp);

    /***cal_minus***/
    NUM[0].minus = 0;
    for(int i = 1; i < n; i++){
        NUM[i].minus = NUM[i].num - NUM[i-1].num;
    }

    /***cal_ans***/
    long long int ans = 0, temp = 0;
    for(int i = 0; i < n;i++){
        for(int j = 1; j < m; j++){
            temp += j * NUM[i+j].minus;
        }

        if(i == 0) ans = temp;
        if(temp < ans) ans = temp;

        temp = 0;
    }

    /***output_ans***/
    printf("%lld",ans);

    return 0;
}
