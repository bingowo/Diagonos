#include<stdio.h>

int main(){
    int a, b; scanf("%d %d", &a, &b);
    int resI = a / b;
    int resFz = ((a % b) + b) % b;
    int res[300] = {0}, rlen = 0, cnt = 0;
    if (resFz){
        while(b /= 3) cnt++;
        rlen = cnt;
    }
    do{
        res[rlen++] = resI % 3;
        resI /= 3;
    }while(resI);

    if (resFz){
        for (int i = 0; i < cnt; i++){
            res[i] = resFz % 3;
            resFz /= 3;
        }
    }

    int carry = 0;
    for (int i = 0; i != rlen; i++){
        int temp = res[i] + 1 + carry;
        res[i] = temp % 3;
        carry = temp / 3;
    }

    for (int i = 0; i != rlen; i++) res[i]--;
    if (carry) res[rlen++] = carry;
    while(res[rlen-1] == 0) rlen--;
    int lo = 0;
    while(res[lo] == 0) lo++;
    for (int i = rlen - 1; i >= lo; i--){
        if (i == cnt - 1) printf(".");
        if (res[i] == -1) printf("2");
        else printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}