#include<stdio.h>
#define uc unsigned char

int cal(uc c){
    int cnt = 0;
    for (int i = 0; i != 8; i++){
        if (c & 1) cnt++;
        c >>= 1;
    }
    return cnt; 
}

int gcd(int a, int b){
    if (!(b % a)) return a;
    return gcd(b % a, a);
}

int main(){
    int n; scanf("%d", &n); getchar();
    while(n--){
        uc s[120];
        uc c; int len = 0;  
        int sum = 0;
        while((c = getchar()) != '\n'){
            s[len++] = c;
            sum += cal(c);
        }
        int div = gcd(sum, len * sizeof(uc) * 8);
        printf("%d/%d\n", sum / div, len * sizeof(uc) * 8 / div);
    }
    return 0;
}