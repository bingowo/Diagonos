#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n;
    scanf("%d",&n);
    int w[11]= {0};
    int sum=0;
    int f[11][1005]= {0};
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&w[i]);
        sum+=w[i];
    }

    //f[i][j] 使用前i个砝码能否称出重量j
    f[0][0]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            if(f[i-1][j])
            {
                f[i][j] = 1;
                f[i][abs(j + w[i])] = 1;
                f[i][abs(j - w[i])] = 1;
            }
        }
    }
    for(int j=1; j<=sum; j++)
    {
        printf("%d",f[n][j]);
    }
    printf("\n");
    return 0;
}



