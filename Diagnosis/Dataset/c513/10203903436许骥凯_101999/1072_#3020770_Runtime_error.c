#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long
int canGet(LL d){
    return (d % 2);
}

LL table[100] = {1}; int tlen = 1;
LL fac(int n){
    if (n < tlen) return table[n];
    for(; tlen <= n; ++tlen)
        table[tlen] = table[tlen - 1] * 2;
    return table[n];
}

int cal(LL d){
    int res = 0;
    while(fac(res) < d) ++res;
    return res;
}

int main(){
    LL x, y; scanf("%lld%lld", &x, &y);
    char res[1000] = {0};
    int cnt = 0; 
    if (canGet(x + y))
        cnt = cal(llabs(x) + llabs(y));
    else if (x != 0 && y != 0){
        cnt = -1; x = 0; y = 0;
    }
    int _cnt = cnt;
    while(x != 0 || y != 0){ 
        if (llabs(x) > llabs(y)){
            if (x > 0) res[--cnt] = 'E';
            else res[--cnt] = 'W';
            x = x + (x > 0? -1: 1) * fac(cnt);
        }
        else{
            if (y > 0) res[--cnt] = 'N';
            else res[--cnt] = 'S';
            y = y + (y > 0? -1: 1) * fac(cnt);
        }
    }
    printf("%d\n", _cnt);
    for (int i = 0; i < _cnt && printf("%c", res[i]); ++i);
    printf("\n");
    return 0;
}