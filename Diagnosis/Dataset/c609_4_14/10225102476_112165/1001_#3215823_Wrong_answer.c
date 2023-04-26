#include<stdio.h>
void main()
{
    int a;
    scanf("%d\n", &a);
    int i = 0;
    while (i < a) {
        int m, n = 0;
        scanf("%d %d", &m, &n);
        int d = 0;
        int u = m;
        while (u) {
            u = u / n;
            d++;
        }
        char M[20];
        int t = 0;
        int c = 0;
        while (m) {
            c = m % n;
            if (c >= 10)
                M[d-1] = 'A' + c - 10;
            else
                M[d-1] = '0' + c;
            m = m / n;
            d--;
        }
        printf("%s", M);
        printf("\n");
        i = i + 1;
    }
}