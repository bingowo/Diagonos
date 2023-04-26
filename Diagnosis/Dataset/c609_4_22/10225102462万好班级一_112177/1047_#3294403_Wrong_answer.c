#include <stdio.h>

void put_down(int * ans,int flag)
{
    while(flag > 0)
    {if(ans[flag] < 10){flag--;continue;}ans[flag-1] += ans[flag]/10;ans[flag] = ans[flag]%10;flag--;}
}

int main() {
    int base,power;
    scanf("%d %d",&base ,&power);
    int ans[302];
    for (int i = 0; i < 301; ++i) ans[i] = 0;
    ans[301] = base;
    for (int i = 0; i < power-1; ++i) {
        for (int j = 301; j >= 0; --j) {
            ans[j] = ans[j]*base;
        }put_down(ans,301);
    }
    int bool = 0;
    for (int i = 0; i < 302; ++i) {
        if(ans[i] == 0 && bool == 0)continue;
        else {bool = 1;printf("%d",ans[i]);}
    }
}

