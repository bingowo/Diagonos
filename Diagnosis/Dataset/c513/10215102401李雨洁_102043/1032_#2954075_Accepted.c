#include <stdio.h>
#include <stdlib.h>

int cmp( const void *a, const void *b )
{
    int *x = (int*)a;
    int *y = (int*)b;
    int i;
    for(i = 0; (x[i] != EOF)&&(y[i] != EOF); i++)
    {
        if ( x[i] > y[i]) return -1;
        else if ( x[i] < y[i]) return 1;
    }
    if ( (x[i] == EOF) && (y[i] == EOF)) return 0;
    if (y[i] == EOF) return -1;
    return 1;
}

int main()
{
    int t;
    scanf("%d",&t);
    int num[1001][51];
    for (int q = 0; q < t; q++)
    {
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; ++i )
        {
            int a = 1;
            for (int j = 0; a != EOF; j++)
            {
                scanf("%d",&a);
                num[i][j] = a;
            }
        }
        qsort(num,n,sizeof(num[0]),cmp);
        for (int i = 0; i < n; i++)
        {
            if (num[i][0] != EOF)
            {
                printf("%d",num[i][0]);
                for (int j = 1; num[i][j] != EOF; j++)
                {
                    printf( " %d", num[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
