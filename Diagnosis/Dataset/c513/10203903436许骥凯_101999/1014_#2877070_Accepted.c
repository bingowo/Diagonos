#include<stdio.h>
#include<stdlib.h>

void Print(int *num, int point, int len){
    int index = len - 1;
    if (num[199] == 1) printf("1");
    for (; index >= point; index--)
        if (num[index] != 0) break;
    for (int i = 0; i <= index; i++){
        if(i == point) printf(".");
        printf("%d", num[i]);
    }
    printf("\n");
}

void sub(int *num, int len){
    for (int i = 0; i != len; i++){
        num[i] -= 1;
        if (num[i] == -1) num[i] = 2;
    }
}

void add(int *num, int len){
    int carry = 0;
    for (int i = len - 1; i >= 0; i--){
        num[i] += carry + 1;
        if (num[i] >= 3){
            num[i] -= 3;
            carry = 1;
        }
        else carry = 0;
    }
    if (carry == 1) num[199] = 1;
}

void reverse(int *num, int lo, int hi){
    while (lo <= hi){
        int temp = num[lo];
        num[lo++] = num[hi];
        num[hi--] = temp;
    }
}

void transform(int integer, int mantissa, int fac){
    int num[300];
    for (int i = 0; i != 300; i++)
        num[i] = -2;
    int index = 0;
    do{
        num[index++] = integer % 3;
        integer /= 3;
    }while(integer != 0);
    reverse(num, 0, index-1);
    int midx = index;
    for (int i = 0; i != fac; i++){
        num[midx++] = mantissa % 3;
        mantissa /= 3;
    }
    reverse(num, index, midx-1);
    add(num, midx);
    sub(num, midx);
    Print(num, index, midx);
}
int main(){
    int div, divd;
    scanf("%d %d", &divd, &div);
    int num = divd / div;
    int fac = 0;
    for (int i = div; (i / 3) != 0; i /= 3, fac++);
    transform(num, divd - num * div, fac);
    return 0;
}