#include <math.h>
#include <stdio.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        int n,j;
        scanf("%d",&n);
        int res[1001] = {1,1,2,3,4};
        for(j = 5;j<=n;j++)
            {
                res[j] = res[j-1] + 3;
                printf("%d ",res[j]);
            }
        printf("%d\n",res[n]);
    }
    return 0;
}
