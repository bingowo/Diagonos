#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 103

typedef struct{
    int v[M];
    int cnt;
    int sum;
}BIG;

BIG up(BIG a, int k){   //[k+1]++, [n]=0 (n<=k);
    int t, carry = 1;
    a.sum = 0;
    for(int i = k; i < a.cnt; i++){
        t = a.v[i] + carry;
        a.v[i] = t%10;
        //a.sum += a.v[i];
        carry = t/10;
    }
    if(carry > 0) a.v[a.cnt++] = carry;
    for(int i = 0; i < k; i++) a.v[i] = 0;

    for(int i = k; i < a.cnt; i++) a.sum += a.v[i];

    return a;
}


BIG nine_add(BIG a){
    int t, carry = 1;
    for(int i = 0; i < a.cnt; i++){
        t = a.v[i] + carry;
        a.v[i] = t%9;
        carry = t/9;
    }
    if(carry > 0) a.v[a.cnt++] = carry;

    a.sum = 0;
    for(int i = 0; i < a.cnt; i++) a.sum += a.v[i];

    return a;
}

int main()
{
    BIG dec = {{0},0,0};
    char temp[M];
    scanf("%s",temp);
    int len = strlen(temp);

    for(int i = len-1; i >= 0; i--){
        dec.v[len-1-i] = temp[i] - '0';
        dec.sum += temp[i] - '0';
    }
    dec.cnt = len;

    dec = nine_add(dec);

    for(int i = dec.cnt-1; i >= 0; i--)
        if(dec.v[i] == 9) dec = up(dec,i);

    if(dec.sum%9 == 0) dec = nine_add(dec);

    for(int i = dec.cnt-1; i >= 0; i--)
        printf("%d",dec.v[i]);

    return 0;
}
