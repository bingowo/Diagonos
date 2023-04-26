#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int i[100];
    int d;
}BIGINT;


BIGINT int2big(int a){
    BIGINT r = {{0},0};

    do{
        r.i[(r.d)++] = a % 10;
        a = a / 10;
    }while(a > 0);

    return r;
}


BIGINT mul(BIGINT a, BIGINT b){
    BIGINT r = {{0},a.d+b.d};

    for(int m = 0; m < b.d; m++){
        int t,k,n;
        int carry = 0;

        for(n = 0; n < a.d; n++){
            t = a.i[n]*b.i[m] + carry + r.i[n+m];
            r.i[n+m] = t % 10;
            carry = t / 10;
        }
        k = m + n;
        while(carry > 0){
            t = carry + r.i[k];
            r.i[k] = t % 10;
            carry = t / 10;
            k++;
        }
    }

    if(r.i[a.d+b.d-1] == 0) r.d--;
    return r;
}


BIGINT big_pow(BIGINT a, int n){
    BIGINT r;
    if(n == 0) return( int2big(1) );
    if(n == 1) return a;

    r = big_pow(a,n/2);
    r = mul(r,r);
    if(n%2 == 1) r = mul(r,a);

    return r;
}


int main()
{
    int T,R;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        int a,n;
        scanf("%d%d",&a,&n);

        BIGINT r,A;
        A = int2big(a);
        r = big_pow(A,n);

        printf("case #%d:\n",R);
        for(int k = r.d; k > 0; k--)
            printf("%d",r.i[k-1]);
        printf("\n");
    }

    return 0;
}
