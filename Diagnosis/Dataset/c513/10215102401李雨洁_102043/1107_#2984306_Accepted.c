#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        int b[3][3];
        int A[3][3];
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                b[j][i] = 1;
                A[j][i] = 0;
            }
        }
        int a;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
            {
                scanf("%d",&a);
                if(j > 0) A[i][j - 1] += a;
                if(j < 2) A[i][j + 1] += a;
                if(i > 0) A[i - 1][j] += a;
                if(i < 2) A[i + 1][j] += a ;
                A[i][j] += a;
            }
        for(int i = 0; i < 3 ;i++)
            for(int j = 0; j < 3; j++)
            {
            if(A[i][j] % 2 == 1)
                b[i][j] = 0;
            }
        printf("case #%d:\n",i);
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 2; j++)
                printf("%d ",b[i][j]);
            printf("%d\n",b[i][2]);
        }
    }
    return 0;
}


