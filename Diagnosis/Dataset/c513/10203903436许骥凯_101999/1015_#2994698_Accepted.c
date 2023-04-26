#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 26

int table[26], tlen = 0;

int isPrime(int a){
    if (a <= 1) return 0;
    if (a == 2) return 1;
    if (!(a % 2)) return 0;
    for (int i = 3; i <= sqrt(a); i += 2)
        if (!(a % i)) return 0;
    return 1;
}

void Init(){
    for (int i = 2; i <= 10000; i++){
        if (isPrime(i)) table[tlen++] = i;
        if (tlen == 26) return; 
    }
}

void reverse(int *a, int lo, int hi){
    while(lo <= hi){
        int temp = a[lo];
        a[lo++] = a[hi];
        a[hi--] = temp;
    }
}

int main(){
    Init();
    int T; scanf("%d", &T);
    for (int i = 0; i != T; i++){
        printf("case #%d:\n", i);
        char c;
        int I1[60] = {0}, I2[60] = {0}, Ilen1 = 0, Ilen2 = 0;
        do{scanf("%d", &I1[Ilen1++]);}while((c = getchar()) != ' ');
        do{scanf("%d", &I2[Ilen2++]);}while((c = getchar()) != '\n');

        reverse(I1, 0, Ilen1 - 1); reverse(I2, 0, Ilen2 - 1);

        int res[26] = {0}, rlen = 0, carry = 0;
        for (int i = 0; i != Ilen1; i++){
            int temp = I1[i] + I2[i] + carry;
            res[rlen++] = temp % table[i];
            carry = temp / table[i];
        }
        for (; rlen < Ilen2;){
            int temp = I1[rlen] + I2[rlen] + carry;
            res[rlen] = temp % table[rlen];
            carry = temp / table[rlen++];
        }
        
        while(carry){
            res[rlen] = carry % table[rlen];
            carry /= table[rlen++];
        }
        while(rlen > 1 && res[rlen - 1] == 0) rlen--;
        for (int i = rlen - 1; i >= 0; i--) printf("%d%c", res[i], i == 0? '\n': ',');
    }
    return 0;
}

