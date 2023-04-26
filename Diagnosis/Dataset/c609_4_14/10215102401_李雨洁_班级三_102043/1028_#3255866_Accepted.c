#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    int *s1,*s2;
    s1=(int *)a;
    s2=(int *)b;
    while(*s1!=-1&&*s2!=-1&&*s1==*s2) s1++,s2++;
    return *s2-*s1;
}
int main()
{
    int t;int n;
    scanf("%d", &t);
    int num[1001][51];
    for (int q = 0; q < t; q++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            int a = 1;
            for (int j = 0; a != -1; j++)
            {
                scanf("%d", &a);
                num[i][j] = a;
            }
        }
        qsort(num, n, sizeof(num[0]), cmp);
        for (int i = 0; i < n; i++)
        {
            if (num[i][0] != -1)
            {
                printf("%d", num[i][0]);
                for (int j = 1; num[i][j] != -1; j++)
                    printf(" %d", num[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}