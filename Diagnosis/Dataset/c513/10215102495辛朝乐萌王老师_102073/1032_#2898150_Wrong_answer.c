#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    int *s1,*s2;
    s1 = (int *)a;
    s2 = (int *)b;
    while(*s1 != -1 && *s2 != -1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return *s2-*s1;
}

int main()
{
    int line_data[10000][51];
    int n;
    int j=0;
    scanf("%d",&n);
    for (int k=0; k<n; k++) {
        while (scanf("%d",&line_data[k][j]) && line_data[k][j] != -1) {
            j++;
        }
    }
    qsort(line_data, n, sizeof(line_data[0]), cmp);
    for (int k=0; k<n; k++)
    {
        for (int j=0; line_data[k][j] != -1; j++)
            printf("%d ",line_data[k][j]);
    }
}
