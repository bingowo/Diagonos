#include<stdio.h>

int main(){
    int a, b; scanf("%d%d", &a, &b);
    int IntPart = a / b, top = a % b, bottom = b, flag = 0;
    if (IntPart < 0) IntPart = -IntPart, top = -top, flag = 1;
    int res[100], len = 0; 
    while (top){
        res[len++] = top % 3;
        top /= 3;
    }
    int dotIdx = len - 1;
    while (IntPart){
        res[len++] = IntPart % 3;
        IntPart /= 3;
    }

    int carry = 0;
    for (int i = 0; i != len; ++i){
        int temp = res[i] + carry + 1;
        res[i] = temp % 3;
        carry = temp / 3;
    }
    int subIdx = len;
    while(carry){
        res[len++] = carry % 3;
        carry /= 3;
    }

    for (int i = 0; i != subIdx; ++i)
        res[i] -= 1;
    while(len - 1 > dotIdx && res[len - 1] == 0) --len;
    int lower = 0;
    while(lower <= dotIdx && res[lower] == 0) ++lower;

    if (flag){
        for (int i = 0; i != len; ++i){
            if (res[i] == -1) res[i] = 1;
            else if (res[i] == 1) res[i] = 2; 
        }
    }
    for (int i = len - 1; i >= lower; --i){
        if (i == dotIdx) printf(".");
        if (res[i] == -1) printf("2");
        else printf("%d", res[i]);
    }
    printf("\n");
}