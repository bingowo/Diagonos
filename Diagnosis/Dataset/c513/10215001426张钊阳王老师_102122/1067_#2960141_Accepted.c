#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m;

    scanf("%d",&m);

    for(int j=0;j<m;j++)
    {
        long long int z[100];
        int n;
        scanf("%d",&n);
        z[0]=0;
        z[1]=1;
        z[2]=1;

        for(int i=3;i<=n;i++)
        {
            z[i]=z[i-1]+z[i-2]+z[i-3];
        }

        printf("case #%d:\n",j);

        printf("%lld",z[n]);

        printf("\n");
    }
    return 0;
}

