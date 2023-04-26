#include<stdio.h>
#include<string.h>

int  gcd(int a, int b){
    return (b? gcd(b, a % b): a);
}

int main(){
    int T; scanf("%d", &T); getchar();
    for (int i = 0; i != T; ++i){
        char s[120], c;
        int len = 0;
        while((c = getchar()) != '\n')
            s[len++] = c;
        int oneOccur = 0;
        for (int j = 0; j != len; ++j){
            for (int k = 0; k != sizeof(char) * 8; ++k){
                oneOccur += 1 & s[j];
                s[j] >>= 1; 
            }
        }
        int total = len * sizeof(char) * 8;
        int div = gcd(total, oneOccur);
        printf("%d/%d\n", oneOccur / div, total / div);   
    }
    return 0;
}