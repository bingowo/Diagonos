#include <stdio.h>
#include <stdlib.h>
#define N 40

int input(int n[])
{
    int i = 0;
    char c = 0;
    do
    {
        scanf("%d%c", &n[i++], &c);
    }
    while(c == ',');
    return i;
}

int main()
{
    int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,43,41,47,53,59,61,67,71,73,79,83,89,97};
    int T = 0;
    scanf("%d", &T);
    int i = 0;
    for(i = 0; i<T; i++)
    {
        printf("case #%d:\n", i);
        int num1[N] = {0};
        int num2[N] = {0};
        int d[N] = {0};
        int n1 = input(num1);
        int n2 = input(num2);
        if(n1<=n2)
        {
            int j = 0;
            int q = 0;
            for(j = N-1,q = 0; q<n1 && j>0 && q<25; j--,q++)
            {
                d[j] += num1[n1-1-q] + num2[n2-1-q];
                d[j-1] += d[j]/p[q];
                d[j] = d[j]%p[q];
            }
            if(n1<n2)
            {
                for(; n1<n2; n1++)
                {
                    d[N-1-n1] += num2[n2-n1-1];
                    d[N-2-n1] += d[N-1-n1]/p[q];
                    d[N-1-n1] = d[N-1-n1]%p[q];
                    q++;
                }
            }
        }
        else
        {
            int j = 0;
            int q = 0;
            for(j = N-1, q = 0; q<n2&&j>0; q++,j--)
            {
                d[j] += num1[n1-1-q]+num2[n2-1-q];
                d[j-1] += d[j]/p[q];
                d[j] = d[j]%p[q];
            }
            for(; n2<n1; n2++)
            {
                d[N-1-n2] += num1[n1-n2-1];
                d[N-2-n2] += d[N-1-n2]/p[q];
                d[N-1-n2] = d[N-1-n2]%p[q];
                q++;
            }
        }
        int j = 0;
        for(; j<=N-1; j++)
        {
            if(d[j] != 0) break;
        }
        if(j == N) printf("0");
        else
        {
            for(; j<=N-1; j++)
            {
                printf("%d",d[j]);
                if(j!=N-1) printf(",");
            }
        }
        printf("\n");

    }

    return 0;
}
