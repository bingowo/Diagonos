#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int n=0;n<T;n++)
    {
        printf("case #%d:\n",n);
        int arr[3][3],light[3][3];
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                scanf("%d",&arr[i][j]);
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                light[i][j]=1;
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
            {
                if (arr[i][j]%2)
                {
                    light[i][j]=light[i][j]^1;
                    if (i==0 && j==0)
                    {
                        light[i][j+1]^=1;
                        light[i+1][j]^=1;
                    }
                    if (i==0 && j==1)
                    {
                        light[i][j+1]^=1;
                        light[i+1][j]^=1;
                        light[i][j-1]^=1;
                    }
                    if (i==0 && j==2)
                    {
                        light[i+1][j]^=1;
                        light[i][j-1]^=1;
                    }
                    if (i==1 && j==0)
                    {
                        light[i+1][j]^=1;
                        light[i][j+1]^=1;
                        light[i-1][j]^=1;
                    }
                    if (i==1 && j==1)
                    {
                        light[i+1][j]^=1;
                        light[i][j+1]^=1;
                        light[i-1][j]^=1;
                        light[i][j-1]^=1;
                    }
                    if (i==1 && j==2)
                    {
                        light[i+1][j]^=1;
                        light[i-1][j]^=1;
                        light[i][j-1]^=1;
                    }
                    if (i==2 && j==0)
                    {
                        light[i-1][j]^=1;
                        light[i][j-1]^=1;
                    }
                    if (i==2 && j==1)
                    {
                        light[i-1][j]^=1;
                        light[i][j-1]^=1;
                        light[i][j+1]^=1;
                    }
                    if (i==2 && j==2)
                    {
                        light[i-1][j]^=1;
                        light[i][j-1]^=1;
                    }
                }
            }
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                printf("%d%c",light[i][j],(j==2)?'\n':' ');

    }
    return 0;
}
