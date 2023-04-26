#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int v[50];
    int cnt;
}BIG;

BIG int2BIG(int a){
    BIG res = {{0},0};

    while(a > 0){
        res.v[res.cnt++] = a%10;
        a = a/10;
    }
    if(res.cnt == 0) res.cnt++;
    return res;
}

BIG mul(BIG a, BIG b){
    BIG res = {{0},a.cnt+b.cnt};

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

    if(res.v[a.cnt+b.cnt-1] == 0) res.cnt--;
    return res;
}

BIG Pow(int t, int x){  //x^t
    BIG res = {{0},1};
    if(t == 0) return(int2BIG(1));
    if(t == 1) return(int2BIG(x));

    res = Pow(t/2,x);
    res = mul(res,res);
    if(t%2 == 1) res = mul(res,(int2BIG(x)));

    return res;
}

int main()
{
    char w[1001];
    scanf("%s",w);
    int len = strlen(w);

    if(len == 1){printf("1");return 0;}

    int two = 0, three = 0;
    if(w[0] != w[1]) two++;
    if(w[len-2] != w[len-1]) two++;
    for(int i = 1; i < len-1; i++){
        if(w[i] != w[i-1] && w[i-1] != w[i+1]
           && w[i] != w[i+1])
           three++;
        else if(w[i] == w[i-1] && w[i] == w[i+1])
            continue;
        else two++;
    }

    BIG res = {{0},0};
    res = Pow(three,3);
    res = mul(Pow(two,2),res);

    for(int i = res.cnt - 1; i >= 0; i--)
        printf("%d",res.v[i]);

    return 0;
}
