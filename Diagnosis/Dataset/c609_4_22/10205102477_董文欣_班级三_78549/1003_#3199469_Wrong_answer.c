#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        long long int n;
        scanf("%lld",&n);
        int a[20] = {0};
        int j = 0;
        while (n) {
            a[j++] = n % 2333;
            n = n / 2333;
        }

        while (j--)
        {
            printf("%d ",a[j]);
        }
        printf("\n");
    }
    return 0;
}
