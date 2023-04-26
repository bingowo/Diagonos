#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

typedef struct{
    int v[MAX];
    int cnt;
}BIG;

BIG int2big(int a){
    BIG res = {{0},0};

    if(a == 0){
        res.cnt = 1;
        return res;
    }
    while(a > 0){
        res.v[res.cnt++] = a%10;
        a = a/10;
    }
    return res;
}

BIG mul(BIG a, BIG b){
    BIG res = {{0},0};
    //start mul for v
    for(int m = 0; m < b.cnt; m++){
        int t,k,n;
        int carry = 0;

        for(n = 0; n < a.cnt; n++){
            t = a.v[n]*b.v[m] + carry + res.v[n+m];
            res.v[n+m] = t % 10;
            carry = t / 10;
        }
        k = m + n;
        while(carry > 0){
            t = carry + res.v[k];
            res.v[k] = t % 10;
            carry = t / 10;
            k++;
        }
    }

    //len
    res.cnt = a.cnt + b.cnt;
    if(res.v[a.cnt+b.cnt-1] == 0) res.cnt--;
    return res;
}

int max(int a, int b){
    return a > b ? a : b;
}

BIG minus(BIG a, BIG b){
    BIG res = {{0},0};
    int t,carry = 0;

    for(int i = 0; i < max(a.cnt,b.cnt); i++){
        if(a.v[i] < b.v[i]){
            carry = 1;
            a.v[i+1]--;
        }
        t = a.v[i] - b.v[i] + 10*carry;
        res.v[res.cnt++] = t;
        carry = 0;
    }
    if(res.v[res.cnt-1] == 0) res.cnt--;

    return res;
}

int main()
{
    BIG arr[MAX+3] = {{{0},0}};
    int k,n;
    scanf("%d%d",&k,&n);
    arr[1] = int2big(0), arr[2] = int2big(1);

    for(int i = 3; i <= k+1; i++)
        arr[i] = int2big((int)pow(2,i-3));

    for(int i = k+2; i <= n; i++){
        arr[i] = mul(int2big(2),arr[i-1]);
        arr[i] = minus(arr[i],arr[i-k-1]);
    }

    for(int i = arr[n].cnt - 1; i >= 0; i--)
        printf("%d",arr[n].v[i]);

    return 0;
}
