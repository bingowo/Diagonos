#include <stdio.h>
#include <string.h>

int prime[] = {1,2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void trans(int *array) {
    for (int i = 99; i > 0; i--) {
        array[i - 1] += array[i] / 10;
        array[i] %= 10;
    }
}

void multi(int *array, int num) {
    for (int i = 99; i > 0; i--) {
        array[i] *= num;
    }
    trans(array);
}

void add(int *array, int *num) {
    int d=0;  //进位
    for(int i=99;i>=0;i--)
    {
        int tmp=d+array[i]+num[i];
        array[i]=tmp%10;
        d=tmp/10;
    }
}

int main() {
    
    int n;
    scanf("%d",&n);
    printf("%d\n",n);
    return 0;
}