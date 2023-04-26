#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10000
int main()
{

    unsigned int T, N[10]={0}, i, j, b, c, t, temp = 0, a, n[M] = {0}, num[M] = {0};
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d", &N[i]);
        for (j = 0; j < N[i]; j++)
        {
            scanf("%d", &n[j]);
        }
        for (j = 0; j < N[i]; j++)
        {
            
            a = n[j];
            temp = 0;
            while (a != 0)
            {

                a = a >> 1;
                temp = temp + (n[j] & 1);
            }
            num[j] = temp;

        }
        for (b = 0; b < N[i] - 1; b++)//paixu
        {
            for (c = b + 1; c < N[i]; c++)
            {
                if (num[b] > num[c])
                {
                    t = num[b];
                    num[b] = num[c];
                    num[c] = t;
                    t = n[b];
                    n[b] = n[c];
                    n[c] = t;
                }
            }
        }

    }
    for (i = 0; i < T; i++)
    {
        printf("case #%d:\n", i);
        for (j = 0; j < N[i]; j++)
        {
            printf("%d\n", n[j]);
        }
        
    }
   
    return 0;
}