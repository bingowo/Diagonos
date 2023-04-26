#include <stdio.h>
#include <stdlib.h>
int main()
{
    
    int n;
    scanf("%d",&n);
    while(n!=-1){
        int a[21] = {0, 2, 4, 7};
    for(int i = 4; i < 21; ++i)
        a[i] = 2 * a[i - 1] - a[i - 2] + a[i - 3];
    printf("%d",a[n]);
    scanf("%d",&n);
    }
}
