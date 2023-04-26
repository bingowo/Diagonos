#include <stdio.h>
#define N 95
void bigpow(int a, int *arr)
{

    int r = 0;
    int total;
    for(int i = 0; i < N; i++)
    {
        total = arr[i] * a + r;
        arr[i] = total % 10;
        r = total / 10;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int a, n;
        scanf("%d %d", &a, &n);

        int results[N] = {1};
        for(int k = 0; k < n; k++)
            bigpow(a, results);

        //输出
        int Nz = 0;
        printf("case #%d:\n", i);
        for(int j = N - 1; j >= 0; j--)
        {
            if(results[j])
                Nz = 1;
            if(Nz)
                printf("%d", results[j]);
        }
        printf("\n");
    }
    return 0;
}
