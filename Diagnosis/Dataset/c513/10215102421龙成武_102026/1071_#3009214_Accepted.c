#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//怎么说嘞，感谢python，感谢张永卓，感谢夏老师（组合数递推公式）
#define c 10007
typedef long long ll;
ll C[1001][1001] = { 0 };
ll func(int k, int n)
{
    if (C[k][n] == 0)
    {
        if (n == k)
            C[k][n] = 1;
        else if (n == 0)
            C[k][n] = 1;
        else
            C[k][n] = (func(k - 1, n - 1) % c + func(k - 1, n) % c) % c;
    }
    return C[k][n];
}
ll getmod(int a, int n)     //返回值是a的n次方对c取余
{
    if (n == 1)
        return a % c;
    else if(n==0)       //要考虑边界条件
        return 1;
    else
    {
        if (n % 2 == 0)
            return (getmod(a, n / 2) * getmod(a, n / 2)) % c;
        else
            return (getmod(a, n - 1) * (a % c)) % c;
    }
}
int main()
{
    ll ans, x1, x2, x3, x4;
    int T, a, b, k, n, m, i;
    scanf("%d", &T);
    for (i = 0;i < T;i++)
    {
        scanf("%d %d %d %d %d", &a, &b, &k, &n, &m);
        x1 = func(k,n);
        //x2 = (ll)pow(a % c, n) % c;
        x2 = getmod(a, n);
        x3 = (x1 * x2) % c;
        //x4 = (ll)pow(b % c, m) % c;
        x4 = getmod(b, m);
        ans = (x3 * x4) % c;
        printf("case #%d:\n%lld\n", i, ans);
    }
    return 0;
}
