#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    int digit;
} NUM;

int count(int x)
{
    if (x < 0) x = -x;
    int n = 0;
    do{
        x /= 10;
        n ++;
    }while (x > 0);
    return n;
}

int cmp(const void *a1, const void *b1)
{
    NUM a = *(NUM*)a1;
    NUM b = *(NUM*)b1;
    if (a.digit != b.digit){
        return b.digit - a.digit;
    }
    else{
        if (a.num > b.num) return 1;
        else return -1;
    }
}

int main()
{
    NUM *a = (NUM*)malloc(sizeof(NUM) * 1000000);
    int t, n = 0;
    while (scanf("%d", &t) != EOF){
        a[n].num = t;
        a[n].digit = count(t);
        n ++;
    }
    qsort(a, n, sizeof(NUM), cmp);
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}