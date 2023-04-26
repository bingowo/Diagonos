#include <stdio.h>
#include <stdlib.h>

#define N 100

void mul(int* num, int a)
{
    int n = 0;
    for(int i = 0; i<N-1; i++)
    {
        num[i] = num[i]*a + n;
        n = num[i] / 10;
        num[i] = num[i]%10;
    }
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    int i = 0;
    for(i = 0; i<T; i++)
    {
        int a = 0;
        int n = 0;
        scanf("%d %d",&a,&n);
        printf("case #%d:\n", i);
        if(n == 0) printf("1\n");
        else
        {
            int num[N] = {0};
            for(int j = 0; j<N; j++)
            {
                num[j] = 0;
            }
            num[0] = 1;
            for(int j = 0; j<n; j++)
            {
                mul(num, a);
            }
            int j = N-1;
            while(num[j] == 0) j--;
            for(; j>=0; j--)
            {
                printf("%d", num[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
