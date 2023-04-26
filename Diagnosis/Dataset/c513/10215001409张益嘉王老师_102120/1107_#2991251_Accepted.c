#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int a[5][5],re[5][5];
        int j,k;
        for(j=1;j<4;j++)
        {
            for(k=1;k<4;k++)
            {
                scanf("%d",&a[j][k]);
            }
        }

        for(j=1;j<4;j++)
        {
            for(k=1;k<4;k++)
            {
                re[j][k]=1;
            }
        }

        for(j=1;j<4;j++)
        {
            for(k=1;k<4;k++)
            {
                if(a[j][k]%2==0);
                else
                {
                    re[j][k]=re[j][k]^1;
                    re[j+1][k]=re[j+1][k]^1;
                    re[j-1][k]=re[j-1][k]^1;
                    re[j][k+1]=re[j][k+1]^1;
                    re[j][k-1]=re[j][k-1]^1;
                }
            }
        }

        printf("case #%d:\n",i);

        for(j=1;j<4;j++)
        {
            for(k=1;k<3;k++)
            {
                printf("%d ",re[j][k]);
            }
            printf("%d\n",re[j][k]);
        }

    }
    return 0;
}
