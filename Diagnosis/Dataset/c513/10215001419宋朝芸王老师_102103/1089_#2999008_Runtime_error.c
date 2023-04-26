#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int v[11];
}BIG;

BIG int2big(int i){
    BIG res = {0};
    int cnt = 0;
    while(i > 0){
        res.v[cnt++] = i%10;
        i = i/10;
    }
    return res;
}

BIG mul(BIG a, BIG b, int n){
    BIG res = {0};
    for(int i = 0; i < n; i++){
        int t,carry = 0;
        for(int j = 0; j < n; j++){
            t = carry + b.v[i] * a.v[j] + res.v[j+i];
            res.v[j+i] = t%10;
            carry = t/10;
        }
    }
    return res;
}

BIG cal(BIG a, int b, int n){
    BIG res = {0};
    if(b == 0)
        return int2big(1);
    if(b == 1)
        return a;

    res = cal(a,b/2,n);
    res = mul(res,res,n);
    if(b%2 == 1)
        res = mul(res,a,n);

    return res;
}


int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){

        char temp[11] = {'\0'};
        BIG a = {0},res = {0};
        int b,n;

        scanf("%s%d%d",temp,&b,&n);
        for(int i = 0; i < strlen(temp); i++)
            a.v[i] = temp[strlen(temp) - 1 - i] - '0';

        res = cal(a,b,n);

        printf("case #%d:\n",R);
        for(int i = 0; i < n; i++){
            printf("%d",res.v[i]);
        }
        printf("\n");
    }
    return 0;
}
