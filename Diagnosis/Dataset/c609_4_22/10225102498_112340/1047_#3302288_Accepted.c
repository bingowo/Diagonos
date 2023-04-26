#include <stdio.h>
#include <stdlib.h>
#define N 1000

typedef struct{
    int cnt;
    int v[N];
}BIGINT;

BIGINT MUL(BIGINT R, int a)
{
    int carry = 0, j, t;
    for(j=0; j<R.cnt; j++)
    {
        t = R.v[j]*a + carry;
        R.v[j] = t%10;
        carry = t/10;
    }
    if(carry > 0)
    {
        R.v[R.cnt++] = carry%10;
        carry /= 10;
    }
    return R;
}
void printBIGINT(BIGINT R)
{
    int i;
    for(i=R.cnt-1; i>=0; i--)
        printf("%d", R.v[i]);
}

int main()
{
    int I, T;
    scanf("%d", &T);
    for(I=0; I<T; I++)
    {
        int a, n, i;
        BIGINT ans = {1,{1}};
        printf("case #%d:\n", I);
        scanf("%d%d", &a, &n);
        for(i=0; i<n; i++)
            ans = MUL(ans,a);
        printBIGINT(ans);
        printf("\n");
    }

    return 0;
}
