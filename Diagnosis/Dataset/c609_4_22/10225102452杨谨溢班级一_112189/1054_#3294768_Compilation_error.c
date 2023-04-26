#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef struct{
int cnt;// 存位数
int v[N];
}BIGINT;

// 大整数*某个位数
void mul1(int *result,int a)
{
    int i;
    int carry = 0;  // 进位
    for (i = 0;i<N;++i)
    {
        int t = result[i] * a + carry;
        result[i] = t%10;
        carry = t/10;
        /*当然程序还可以进行优化，
        每次做乘法时，
        不需要循环N次。
        通过记录运算过程中当前的位数，
        减少循环次数*/
    }

}

// 大整数*大整数
BIGINT mul(BIGINT S,BIGINT T)
{
    BIGINT R = {S.cnt + T.cnt,{0}};
    //printf("R.cnt   %d\n",R.cnt);
    for (int i = 0;i<T.cnt;++i)
    {
        int t,k,j;
        int carry = 0;
        for (j = 0;j<S.cnt;++j)
        {
            t = S.v[j]*T.v[i] + carry + R.v[i+j];
            R.v[i+j] = t%10;
            carry = t/10;
        }
        k = i + j;
        while(carry > 0)
        {
            t = carry + R.v[k];
            R.v[k] = t%10;
            carry = t/10;
            k++;
        }
    }
    if (R.v[S.cnt + T.cnt - 1] == 0)  R.cnt--;
    return R;
}

// int 转化为bigint
BIGINT int2BIG(int x)
{
    BIGINT R = {0,{0}}; // 0 的特殊表示
    do {
        R.v[R.cnt++] = x % 10;
        x = x/10;
    }while(x>0);
    //printf("R.cnt   %d\n",R.cnt);
    return R;
}


// 计算a的n次方
BIGINT pow(BIGINT a,int n)
{
    BIGINT r;
    if (n == 0)  return int2BIG(1);
    if (n == 1)  return a;

    r = pow(a,n/2);//printf("r.cnt   %d\n",r.cnt);
    r = mul (r,r);
    if (n%2)  r = mul(r,a);
    return r;
}

void DIV2(BIGINT *n)
{
    int carry = 0;
    if (n->v[n->cnt-1]<2) n->cnt--,carry = 1;
    for(int i = n->cnt-1;i>=0;i--)
    {
        int t = 10*
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int cas = 0;cas <T;++cas)
    {
        char num[105] = {0};
        scanf("%s",num);
        
        printf("case #%d:\n",cas);
        
    }
    return 0;
}
