#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int a, b, c, d, index = 0, flag = 0, fuhao = 1;
    int res1[100] = {0}, res2[100] = {0};
    scanf("%d %d", &a, &b);
    if (a <= 0){
        fuhao = -1;
        a = -a;
    } 
    c = a / b;
    d = a % b;
    for (int i = 0; i < 32; i++){
        res1[31-i] = c % 3;
        c /= 3;
    }
    int temp = 0;int in = 0;
    if (d != 0){
        flag = 1;
        for (int i = 0; i < 32; i++){
            if (pow(3, i) == b){
                temp = i;
                break;
            }
        }
        for (int i = 0; i < temp; i++){
            res2[temp-i-1] = d % 3;
            d /= 3;
        }

        for (int i = temp-1; i >= 0; i--){
        res2[i] += 1 + in;
        in = 0;
        if (res2[i] >= 3){
            in += 1;
            res2[i] -= 3;
        }
        res2[i] -= 1;
        if (res2[i] == -1) res2[i] = 2;
        }   
    }
    for (int i = 31; i >= 0; i--){
        res1[i] += 1 + in;
        in = 0;
        if (res1[i] >= 3){
            in += 1;
            res1[i] -= 3;
        }
        res1[i] -= 1;
        if (res1[i] == -1) res1[i] = 2;
    }
    index = 0;
    while (index < 32 && res1[index] == 0) index++;
    if (index == 32) printf("0");
    else if (fuhao == -1) printf("-");
    for (int i = index; i < 32; i++) printf("%d", res1[i]);
    if (flag){
        printf(".");
        while (res2[temp] == 0) temp--;
        for (int i = 0; i <= temp; i++) printf("%d", res2[i]);
    }
    printf("\n");
    return 0;
}