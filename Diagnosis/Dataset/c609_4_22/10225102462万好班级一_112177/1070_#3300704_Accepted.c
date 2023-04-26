#include <stdio.h>
int main()
{
    int a[21] = {0, 2, 4, 7};
    for(int i = 4; i < 21; ++i)
        a[i] = 2 * a[i - 1] - a[i - 2] + a[i - 3];
    int n;
    while(scanf("%d",&n)){
        if(n == -1) break;
        printf("%d\n",a[n]);
    }
    return 0;
}


