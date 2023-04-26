#include<stdio.h>

int main(){
    int a, b; scanf("%d%d", &a, &b);
    int res[100] = {0}, resI = a / b, resFz = ((a % b) + b) % b, cnt = 0, rlen = 0;
    if (resFz){
        while(b /= 3) cnt++;
        rlen = cnt;
    } 
    do{
        res[rlen++] = resI % 3;
        resI /= 3;
    }while(resI);
    for (int i = 0; i < cnt; i++){
        res[i] = resFz % 3;
        resFz /= 3;
    }

    int carry = 0;
    for (int i = 0; i != rlen; i++){
        int temp = carry + res[i] + 1;
        res[i] = temp % 3;
        carry = temp / 3;
    }
    for (int i = 0; i != rlen; i++) res[i]--;
    if (carry) res[rlen++] = carry;
    
    int lo = 0; while(lo < cnt && res[lo] == 0) lo++;
    for (int i = rlen - 1; i >= lo; i--){
        if (i == cnt - 1) printf(".");
        if (res[i] == -1) printf("2");
        else printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}