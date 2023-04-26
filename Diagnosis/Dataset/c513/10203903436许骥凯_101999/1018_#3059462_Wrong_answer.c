#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

typedef struct {
    int cnt;
    int v[MAXLEN];
} BIG;

BIG* ItoB(int i) {
    BIG* res = (BIG*)malloc(sizeof(BIG));
    res->cnt = 0;
    do {
        res->v[res->cnt++] = i % 10;
        i /= 10;
    } while (i);
    for (int j = res->cnt; j < MAXLEN; ++j)
        res->v[j] = 0;
    return res;
}

void ADD(BIG* A, BIG* B) {
    int carry = 0, i = 0;
    for (; i < A->cnt && i < B->cnt; ++i) {
        int temp = A->v[i] + B->v[i] + carry;
        A->v[i] = temp % 10;
        carry = temp / 10;
    }
    for (; i < B->cnt; ++i) {
        int temp = B->v[i] + carry;
        A->v[i] = temp % 10;
        carry = temp / 10;
    }
    while (carry) {
        int temp = (A->v[i] + carry);
        A->v[i] = temp % 10;
        carry = temp / 10;
        ++i;
    }
    if (i > A->cnt)
        A->cnt = i;
}

BIG* MULT(BIG* A, int I) {
    BIG* res = ItoB(0);
    int carry = 0, i = 0;
    for (; i != A->cnt; ++i) {
        int temp = A->v[i] * I + carry;
        res->v[i] = temp % 10;
        carry = temp / 10;
    }
    while (carry) {
        res->v[i++] = carry % 10;
        carry /= 10;
    }
    res->cnt = i;
    return res;
}

#include <math.h>
int isPrime(int num) {
    if (num <= 1)
        return 0;
    if (num == 2)
        return 1;
    if (!(num % 2))
        return 0;
    for (int i = 3; i <= sqrt(num); i += 2)
        if (!(num % i))
            return 0;
    return 1;
}

#include <string.h>
#define TABLELEN 26
int main() {
    int table[TABLELEN] = {2}, prime = 3;
    for (int i = 1; i != TABLELEN; prime += 2) {
        if (isPrime(prime))
            table[i++] = prime;
    }

    BIG* weight[TABLELEN] = {ItoB(1)};
    for (int i = 1; i != TABLELEN; ++i)
        weight[i] = MULT(weight[i - 1], table[i - 1]);

    int nums[25], nlen = 0;
    char c;
    do {
        scanf("%d", &nums[nlen++]);
    } while ((c = getchar()) != '\n');

    BIG* res = ItoB(0);
    for (int i = 0; i != nlen; ++i) {
        BIG* temp = MULT(weight[nlen - i - 1], nums[i]);
        ADD(res, temp);
        free(temp);
    }

    while(res->v[res->cnt - 1] == 0)
        --res->cnt;
    for (int i = res->cnt - 1; i >= 0; --i)
        printf("%d", res->v[i]);
    printf("\n");
    free(res);
    for (int i = 0; i != TABLELEN; ++i)
        free(weight[i]);
    return 0;
}