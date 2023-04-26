#include <stdio.h>
#define LL long long
#define N 1000
void f_arr(int n)
{
    if(n == 0)
    {
        printf("0\n");
    }
    if(n == 1 || n == 2)
    {
        printf("1\n");
    }
    else if(n > 2)
    {
        //bigint 初始化
        LL arr[N][N];
        arr[1][0] = 1;
        arr[2][0] = 1;

        int in = 0; //进位标志
        int d = 0;//这个数的位数
        for(int i = 3; i <= n; i++)
        {
            in = 0;
            for(int j = 0; j <= d; j++)
            {
                arr[i][j] = arr[i - 1][j] + arr[i - 2][j] + in;//递推公式
                in = arr[i][j] / 10;
                arr[i][j] %= 10;
            }
            if(in)//如果有进位
            {
                d++;
                arr[i][d] = in;
            }
        }
        for(int k = d; k >= 0; k--)
            printf("%d", arr[n][k]);
        printf("\n");
    }
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
         f_arr(n);
    }
    return 0;
}
