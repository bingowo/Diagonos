#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);

    int f[21] = {0};
    int f1[21] = {0};
    int most = 2;

    f[1] = 2, f[2] = 4;
    f1[1] = 1, f1[2] = 2;

    while(n != -1){

        for(int k = most + 1; k <= n; k++){
            f[k] = 2*f[k-1] - f1[k-2];
            f1[k] = f[k-1] - f1[k-2];
        }

        most = n;
        printf("%d\n",f[n]);

        scanf("%d",&n);
    }

    return 0;
}
