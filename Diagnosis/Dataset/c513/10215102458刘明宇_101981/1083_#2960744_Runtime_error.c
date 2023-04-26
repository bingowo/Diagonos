#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

struct bigint
{
    int cnt;
    int v[400];
};

struct bigint int2big(int x)
{
    struct bigint R = {0,{0}};
    do
    {
        R.v[R.cnt++] = x%10;
        x/= 10;
    }while(x>0);
    return R;
}

struct bigint multi(int N)
{
    if(N == 1) return int2big(1);
    struct bigint N1 = int2big(N);
    struct bigint N2 = multi(N-1);
    struct bigint R = {N1.cnt+N2.cnt,{0}};
    for(int i = 0;i<N1.cnt;i++){
        int t,k,j;
        int carry = 0;
        for(j = 0;j<N2.cnt;j++){
            t = N1.v[i] *N2.v[j] + carry + R.v[i+j];
            R.v[i+j] = t%10;
            carry = t/10;
        }
        k = i+j;
        while(carry > 0){
            t = carry + R.v[k];
            R.v[k] = t%10;
            carry = t/10;
            k++;
        }
    }
    if(R.v[N1.cnt + N2.cnt-1] == 0) R.cnt--;
    return R;
}

int main()
{
    int T,cnt = 0;
    scanf("%d",&T);
    while(T-->0){
        int N;
        scanf("%d",&N);
        struct bigint NN = multi(N);
        int num = 0;
        int y = NN.cnt-1;
        if(!NN.v[NN.cnt-1]) printf("hello");
        while(NN.v[y] == 0){
            num++;
            y--;
        }
        printf("case #%d:\n",cnt);
        printf("%d",num);
        if(T)printf("\n");
        for(int k = NN.cnt-1;k>=0;k--){
            printf("%d",NN.v[k]);
        }
        cnt++;
    }
}
