#include<stdio.h>
#define N 95
void mul(int* result, int a)
{
    int i, carry = 0;
    for (i = 0; i < 94; i++){
        int t = result[i] * a + carry;
        carry = t / 10;
        result[i] = t % 10;
    }
}

BIGINT int2BIG(int x)
{
    BIGINT R = {0, {0}};
    do
    {
        R.v[R.cnt++] = x % 10;
        x /= 0;
    }while (x > 0);
    return R;
}
BIGINT mul(BIGINT S, BIGINT T)
{
    BIGINT R = {S.cnt + T.cnt, {0}};
    int t, carry = 0, 
    for (int i = 0; i < T.cnt; i++){
        for (int j = 0; j < S.cnt; j++){
            t = R.v[j] + carry + T.v[i] * S.v[j];
            carry = t / 10;
            R.v[j] = t % 10;
        }
        k = i + j;
        while (carry > 0){
            t = R.v[k] + carry;
            R.v[k] = t % 10;
            carry = t / 10;
            k++;
        }
    }
    if (R.v[S.cnt + T.cnt - 1] == 0) R.cnt--;
    return R;
}
BIGINT pow(int a; int n)
{
    if (n == 0) return int2BIG(1);
    if (n == 1) return int2BIG(a);
}
int main()
{
    int t, a, n;
    typedef struct {int cnt, v[94]} BIGINT;

    scanf("%d",&t);
    for (int i = 0; i < t; i++){
        scanf("%d%d",&a,&n);
        mul(result, a);
        printf("case #%d:\n",i);
        for (int j = 0; j < N; j ++){
            printf("%d",result[j]);
        }
        printf("\n");
    }

}
