#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m;
    scanf("%d",&m);
    for(int z=0;z<m;z++)
    {
        int n;
        scanf("%d",&n);
        long long int s[51];
        s[0]=1;s[1]=2;s[2]=4;s[3]=8;s[4]=15;
        int j;
        for(j=5;j<=n-1;j++)
        {
            s[j]=s[j-1]+s[j-2]+s[j-3]+s[j-4]+s[j-5];
        }

        printf("case #%d:\n",z);

        printf("%lld",s[n-1]);
        printf("\n");

    }
    return 0;
}

