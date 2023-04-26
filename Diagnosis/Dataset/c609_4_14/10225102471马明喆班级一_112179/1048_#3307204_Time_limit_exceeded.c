#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
    int num;
    int v[100];
}BIGINT;

BIGINT add(BIGINT a,BIGINT b){
    int carry = 0;
    int max = a.num > b.num ? a.num : b.num;
    BIGINT back = {0,{0}};
    int i = 0;
    for(;i < max;i++){
        int temp = a.v[i]+b.v[i]+carry;
        carry = temp/10;
        back.v[i] = temp%10;
        back.num++;
    }
    while(carry){
        back.v[i++] = carry%10;
        carry = carry/10;
    }
    return back;
}

BIGINT fx(int n){
    if(n <= 2 && n > 0){
        BIGINT a = {1,{0}};
        a.v[0] = 1;
        return a;
    }
    else if(n == 0){
        BIGINT b = {1,{0}};
        return b;
    }
    else
        return add(fx(n-1),fx(n-2));
}

int main(){
    int n;
    scanf("%d\n",&n);
    for(int i = 0;i < n;i++){
        int T;
        scanf("%d\n",&T);
        BIGINT ans = {0,{0}};
        ans = fx(T);
        printf("case #%d:\n",i);
        for(int t = ans.num-1;t >= 0;t--){
            printf("%d",ans.v[t]);
        }
        printf("\n");
    }
    return 0;
}