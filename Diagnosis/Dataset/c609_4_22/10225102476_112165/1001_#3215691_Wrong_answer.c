#include<stdio.h>
void main()
{
    int a;
    scanf("%d\n", &a);
    int i = 0;
    while (i < a) {
        int m, n = 0;
        scanf("%d %d", &m, &n);
        char M[20];
        int t = 1;
        int c = 0;
        while (m) {
            c = m % n;
            if (c >= 10)
                M[t] = 'A' + c - 10;
            else
                M[t] = '0' + c;
            m = m / n;
        }
        printf("%s", M);
        printf("\n");
        i = i + 1;
    }
}