#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main()
{
    int T, n, i, j, t;
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        int bgt[2][25];
        int cp, sum;
        scanf("%d", &n);
        if(n==0)
        {
            printf("case #%d:\n0\n", i);
            continue;
        }
        for(j=0; j<2; j++)
            for(t=0; t<25; t++)
                bgt[j][t] = 0;
        bgt[1][0] = 1;
        for(j=1; j<n; j++)
        {
            int carry = 0;
            for(t=0; t<=24; t++)
            {
                cp = bgt[1][t];
                sum = bgt[1][t] + bgt[0][t] + carry;
                bgt[1][t] = sum%10;
                carry = sum/10;
                bgt[0][t] = cp;
            }
        }
        printf("case #%d:\n", i);
        int flag = 0;
        for(j=24; j>=0; j--)
        {
            if(bgt[1][j] != 0)
            {
                flag = j;
                break;
            }
        }
        //printf("%d\n", bgt[1][24]);
        for(j=flag; j>=0; j--)
            printf("%d", bgt[1][j]);
        printf("\n");
    }

    return 0;
}
