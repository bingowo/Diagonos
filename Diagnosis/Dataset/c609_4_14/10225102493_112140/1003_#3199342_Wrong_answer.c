#include <stdio.h>
#include <stdlib.h>





int main()
{

    long long n;
    int T;int i=0;
    scanf("%d",&T);
    while(T>0) {
        scanf("%lld", &n);
        if (n > 0.1e10) {
            long long r = 2333;
            long long a[6];
            long long p = n;
            a[0] = 0;
            while (p) {
                a[i] = p % r;
                p = p / r;
                i++;
            }
            if (i != 0) i = i - 1;
            while (i >= 0) {
                if (i == 0)
                    printf("%lld\n", a[i]);
                else printf("%lld ", a[i]);
                i--;
            }
        } else {
            int r = 2333;
            int a[6];
            int p = (int) n;
            a[0] = 0;
            while (p) {
                a[i] = p % r;
                p = p / r;
                i++;
            }
            if (i != 0) i = i - 1;
            while (i >= 0) {
                if (i == 0)
                    printf("%d\n", a[i]);
                else printf("%d ", a[i]);
                i--;
            }
            i = 0;
            T--;
        }
    }
    return 0;
}
