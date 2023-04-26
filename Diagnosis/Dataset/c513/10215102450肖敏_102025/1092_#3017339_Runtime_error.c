#include <stdio.h>
#include <string.h>
#define N 95
typedef struct {
    int cnt, v[N];
} BIGINT;

BIGINT mul(BIGINT S, BIGINT T)     //两个大整数相乘
{
    BIGINT R = {S.cnt + T.cnt, {0}};
    for (int i = 0; i < T.cnt; i++) {
        int t, k, j;
        int carry = 0;
        for (j = 0; j < S.cnt; j++) {
            t = S.v[j] * T.v[i] + carry + R.v[i + j];
            R.v[i + j] = t % 10;
            carry = t / 10;
        }
        k = i + j;
        while (carry > 0) {
            t = carry + R.v[k];
            R.v[k] = t % 10;
            carry = t / 10;
            k++;
        }
    }
    if (R.v[S.cnt + T.cnt - 1] == 0) R.cnt--; //最高位0不统计在一个大整数的位数中
    return R;
}

BIGINT int2BIG(int x)  //int 转换成BIGINT
{
    BIGINT R = {0, {0}};
    do {
        R.v[R.cnt++] = x % 10;
        x /= 10;
    } while (x > 0);
    return R;
}

int main()
{
    char w[1000];
    scanf("%s",w);
    BIGINT s1,s2;
    int len = strlen(w);
    if(len == 1)
        printf("1\n");
    else if(len == 2)
        printf("%d\n",(w[0] == w[1]) ? 1 : 4);
    else {
        int r = 1;
        if (w[0] != w[1]) r = 2;
        s2= int2BIG(r);
        for (int i = 1; i < len - 1; i++) {
            int c = 1;
            if (w[i] != w[i - 1])
                c++;
            if (w[i] != w[i + 1] && w[i - 1] != w[i + 1])
                c++;
            s1= int2BIG(c);
            s2=mul(s2,s1);
        }
        if (w[len - 1] != w[len - 2])
            s2 = mul(s2, int2BIG(2));
        for(int j=s2.cnt-1;j>=0;j--)
            printf("%d",s2.v[j]);
        printf("\n");
    }
    return 0;
}