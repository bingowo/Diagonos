#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T, i, j, r;
    int n, m, k, h;

    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        int t = 1;
        scanf("%d%d", &n, &m);
        k = n*(n+1)/2;
        int num[n];
        int nw[k];
        for(j=0; j<k; j++)
            nw[j] = 0;
        for(j=0; j<n; j++)
        {
            scanf("%d", &num[j]);
            nw[j] = num[j];
        }
        while(j<k)
        {
            for(r=0; r<k-t-1; r++)
            {
                for(h=0; h<=t; h++)
                {
                    nw[j] += num[r+h];
                }
                j++;
            }

            t++;
        }

        for(j=0; j<k; j++)
            printf("%d ", nw[j]);


    }

    return 0;
}
