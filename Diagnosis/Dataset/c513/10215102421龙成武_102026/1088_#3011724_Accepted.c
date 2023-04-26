#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long C[41][41];
void getC()
{
    int n, m;
    for (n = 1;n < 41;n++)
    {
        C[n][0] = 1;
        C[n][n] = 1;
    }
    for (n = 1;n < 41;n++)
    {
        for (m = 0;m < n;m++)
        {
            if(C[n][m]==0)          //这两种for循环差别没那么大，都能ac，但是我写的这一跟要多加一个if判断
                C[n][m] = C[n - 1][m] + C[n - 1][m - 1];
        }
    }
    /*for (m = 1;m < 41;m++)
    {
        for (n = m + 1;n < 41;n++)
        {
            C[n][m] = C[n - 1][m] + C[n - 1][m - 1];
        }
    }*/
}
int main()
{
    int T, n, m,x;
    scanf("%d", &T);
    getC();
    for (x = 0;x < T;x++)
    {
        printf("case #%d:\n", x);
        scanf("%d %d", &n, &m);
        printf("%lld\n", C[n][m]);
    }
    return 0;
}

