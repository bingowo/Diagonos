#include <stdio.h>
#define MAX(a, b) (a > b? a: b)
int bin(int *buf, unsigned int N) {
    int k = 0;
    do
    {
        buf[k++] = N % 2;
        N = N / 2;
    } while (N);
    return k;
}
int main()
{
    int T;
    scanf("%d", &T);
    int i = 0; 
    for (int i = 0; i < T; ++i)
    {
        unsigned int n;
        scanf("%u", &n);
        int buf[32];
        int b = bin(buf, n);
        int count = 1, mc = 1;
        for (int i = 1; i < b; ++i)
        {
            if (buf[i] != buf[i - 1])
            {
                count++;
                mc = MAX(count, mc);
            }
            else
            {
                count = 1;
            }
        }
        printf("case #%d:\n%d\n", i, mc);
    }
    return 0;
}