#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[21], b[21];
    a[0] = b[0] = 0;
    a[1] = b[1] = 1;
    for (int i = 2; i <= 20; ++i){
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i] - b[i-2];
    }

    for (int n; scanf("%d",&n), n != -1;)
        printf("%u\n",a[n] + b[n]);
    return 0;
}
