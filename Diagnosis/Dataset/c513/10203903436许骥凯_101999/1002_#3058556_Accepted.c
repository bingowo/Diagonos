#include<stdio.h>
#include<string.h>

int main(){
    int T; scanf("%d", &T);
    for (int i = 0; i != T; ++i){
        printf("case #%d:\n", i);
        int table[128]; for (int j = 0; j != 128; j++) table[j] = -1;
        char InfStr[60]; scanf("%s", InfStr);
        int scare = 0, len = strlen(InfStr);
        InfStr[0] = table[InfStr[0]] = 1;
        for (int j = 1; j < len; ++j){
            if (table[InfStr[j]] != -1) InfStr[j] = table[InfStr[j]];
            else if (scare == 0){
                InfStr[j] = table[InfStr[j]] = 0;
                scare = 2;
            }
            else
                InfStr[j] = table[InfStr[j]] = scare++;
        }
        if (scare < 2) scare = 2;
        long long res = 0;
        for (int j = 0; j != len; ++j)
            res = InfStr[j] + res * scare;
        printf("%lld\n", res);
    }
}