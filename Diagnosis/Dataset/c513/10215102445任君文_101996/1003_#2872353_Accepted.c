#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10000
int main()
{
    int T,i,j, N[10] = { 0 },num[10][M] = { 0 };
    long b, c, t, temp = 0, n[10][M] = { 0 };
    unsigned long a;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
       scanf("%d", &N[i]);
       for (j = 0; j < N[i]; j++)
       {
           scanf("%ld", &n[i][j]);
       }
    }
    for(i=0;i<T;i++)
    {
        for (j = 0; j < N[i]; j++)
        {
            
            a = n[i][j];
            temp = 0;
            while (a != 0)
            {

                
                temp = temp + (a & 1);
                a = a >> 1;
            }
            num[i][j] = temp;

        }
        for (b = 0; b < N[i] - 1; b++)//paixu
        {
            for (c = b + 1; c < N[i]; c++)
            {
                if (num[i][b] < num[i][c])
                {
                    t = num[i][b];
                    num[i][b] = num[i][c];
                    num[i][c] = t;
                    t = n[i][b];
                    n[i][b] = n[i][c];
                    n[i][c] = t;
                }
                else if (num[i][b] == num[i][c])
                {
                    if (n[i][b] > n[i][c])
                    {
                        t = num[i][b];
                        num[i][b] = num[i][c];
                        num[i][c] = t;
                        t = n[i][b];
                        n[i][b] = n[i][c];
                        n[i][c] = t;
                    }
                }
            }
        }
        printf("case #%d:\n", i);
        for (j = 0; j < N[i]; j++)
        {
            printf("%ld ", n[i][j]);
        }
        printf("\n");
    }  
    return 0;
}