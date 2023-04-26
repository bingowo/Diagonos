#include <stdio.h>

int main()
{
    int T, n, r1, r2, count, max;
    scanf("%d", &T);
    for (int t = 0; t < T;t ++){
        printf("case #%d:\n", t);
        scanf("%d", &n);
        count = 1;
        max = 0;
        r2 = n % 2;
        n /= 2;
        while (n > 0){
            r1 = r2;
            r2 = n % 2;
            n /= 2;
            if (r2 != r1){
                count ++;
            }
            else{
                if (count > max) max = count;
                count = 1;
            }
        }
        if (count > max) max = count;
        printf("%d\n", max);
    }
    return 0;
}
