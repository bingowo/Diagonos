#include <stdio.h>

#define N 1000

typedef struct
{
    int pos, num[N];
}BIGINT;

void Cal(BIGINT *I, int a)
{
    int carry = 0, cal = a;
    for (int i = N - 1;i >= N - I->pos;i--){
        cal = I->num[i] * a + carry;
        I->num[i] = cal % 10;
        carry = cal / 10;
    }
    if (carry > 0){
        I->pos += 1;
        I->num[N - I->pos] = carry;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0;i < T;i++){
        int a, n;
        BIGINT O;
        scanf("%d%d", &a, &n);
        O.pos = 1;O.num[N - 1] = 1;
        for (int j = 0;j < n;j++) Cal(&O, a);
        printf("case #%d:\n", i);
        for (int j = N - O.pos;j < N;j++) printf("%d", O.num[j]);
        printf("\n");
    }
    return 0;
}
