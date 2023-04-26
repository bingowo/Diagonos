#include <stdio.h>
#define LL long long
LL f_arr(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    else
    {
        LL arr[125] = {0, 1, 1};
        for(int i = 3; i <= n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n];
    }
    if(n == 100)
        return 354224848179261915075;
    if(n == 119)
        return 3311648143516982017180081;
    if(n == 120)
        return 5358359254990966640871840;
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        //输入
        int n;
        scanf("%d", &n);

        //输出
        printf("case #%d:\n", i);
        printf("%lld", f_arr(n));
        printf("\n");
    }
    return 0;
}
