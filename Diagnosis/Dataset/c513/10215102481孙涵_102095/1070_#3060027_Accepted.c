#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[21] = {0, 2, 4, 7};
    for(int i = 4; i < 21; ++i)
        a[i] = 2 * a[i - 1] - a[i - 2] + a[i - 3];
    int n;
    scanf("%d",&n);
    while(n != -1){
        printf("%d\n",a[n]);
        scanf("%d",&n);
    }
    return 0;
}