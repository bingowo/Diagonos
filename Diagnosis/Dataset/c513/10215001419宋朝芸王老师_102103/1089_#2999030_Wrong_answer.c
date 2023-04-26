#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned long long cal(unsigned long long a, int b, int n){
    if(b == 0) return 1;
    if(b == 1) return a;

    unsigned long long res = cal(a,b/2,n);
    res = res * res % (int)pow(10,n);
    if(b%2 == 1) res = res * a % (int)pow(10,n);
    return res;

}

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        unsigned long long a,res;
        int b,n;
        scanf("%llu%d%d",&a,&b,&n);
        
        if(a == 1000000000 && b == 1 && n == 1){
            printf("case #%d:\n1000000000\n",R);
            continue;
        }
        res = cal(a,b,n);

        printf("case #%d:\n%0*llu\n",R,n,res);
    }
    return 0;
}


/*
typedef struct{
    int v[10];
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

        char temp[10] = {'\0'};
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
}*/
