#include<stdio.h>
#define N 1000

int main()
{
    int t;
    scanf("%d",&t);
    for(int z = 0; z < t; z++)
    {
        int a,n;
        scanf("%d%d",&a,&n);
        int A[N] = {0};
        A[N-1] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = N - 1; j >= 0; j--) A[j] *= a;
            for(int j = N - 1; j >= 0; j--)
            {
                if (A[j] >= 10)
                {
                    A[j-1] += A[j] / 10;
                    A[j] = A[j] % 10;
                }
            }
        }
        int t;
        for (int i = 0; i < N; i++)
        {
            if (A[i] == 0 && A[i+1] != 0)
            {
                t = i + 1;
                break;
            }
        }
        printf("case #%d:\n",z);
        for (int i = t; i < N; i++)
            printf("%d",A[i]);
        printf("\n");
    }
    return 0;
}
