#include<stdio.h>
#define uc unsigned char

int cal(uc c){
    int cnt = 0;
    for (int i = 0; i != 8; i++){
        cnt += (c & 1); c >>= 1;
    }
    return cnt;
}

int gcd(int a, int b){
    if (!(b % a)) return a;
    return gcd(b % a, a);
}

int main(){
    int T; scanf("%d", &T); getchar();
    while(T--){
        uc c; int slen = 0;
        int sum = 0;;
        while((c = getchar()) != '\n') sum += cal(c), slen++;
        int div = gcd(sum, 8 * slen);
        printf("%d/%d\n", sum / div, 8 * slen / div);
    }
    return 0;
}