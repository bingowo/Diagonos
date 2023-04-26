#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int cmp(const void* a,const void* b)
{
    int* c = (int*)a; int* d = (int*) b;
    int i = 0;
    while (c[i]==d[i]) i++;
    return d[i]-c[i];
}

main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int a[1001][51] = {};
        int j = 0;
        for (int i=0;i<n;i++)
        {
            while (scanf("%d",&a[i][j])!=EOF)
            {
                if (a[i][j]==-1) break;
                j++;
            }
            j = 0;
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for (int i=0;i<n;i++)
        {
            for (int j=0;a[i][j]!=-1;j++) printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}