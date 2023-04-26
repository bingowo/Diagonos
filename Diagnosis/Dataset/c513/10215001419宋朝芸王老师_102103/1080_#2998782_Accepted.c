#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 334

typedef struct{
    int cnt;
    int v[335];
}BIG;

void DIV2(BIG *dec){
    int carry = 0, i;
    if((dec -> v[(dec -> cnt) - 1]) < 2){
        (dec -> cnt)--;
        carry = 1;
    }
    for(i = (dec -> cnt) - 1; i >= 0; i--){
        int t = 10 * carry + (dec -> v[i]);
        (dec -> v[i]) = t/2;
        carry = t % 2;
    }
}

void dec2bin(BIG *dec, BIG *bin){
    int i = 0;
    while(dec -> cnt > 0){
        bin -> v[i++] = (dec -> v[0]) % 2;  //small to big
        DIV2(dec);
    }
    bin -> cnt = i;
}

void reverse(BIG *bin){
    int len = bin -> cnt;
    for(int i = 0; i < len/2; i++){
        char temp = bin -> v[i];
        bin -> v[i] = bin -> v[len-i-1];
        bin -> v[len-i-1] = temp;
    }
}

void bin2dec(BIG *bin){
    BIG r={1,{0}};

    for(int i = 0; i < (bin -> cnt); i++){
        int carry = bin -> v[i];

        for(int j = 0; j < (r.cnt); j++){
            int temp = carry + (r.v[j])*2;
            r.v[j] = temp % 10;
            carry = temp / 10;
        }
        if(carry > 0) r.v[(r.cnt)++] = carry;
    }

    for(int i = r.cnt - 1; i >= 0; i--){
        printf("%d",r.v[i]);
    }
    printf("\n");
}


int main()
{
    int T,R;
    scanf("%d",&T);
    for(R = 0; R < T; R++){

        BIG dec = {0,{0}}, bin = {0,{0}};
        char s[101];

        scanf("%s",s);
        dec.cnt = strlen(s);
        for(int i = dec.cnt - 1; i >= 0; i--){
            dec.v[dec.cnt - i - 1] = s[i] - '0';
        }

        dec2bin(&dec,&bin);

        printf("case #%d:\n",R);
        bin2dec(&bin);
    }
    return 0;
}


