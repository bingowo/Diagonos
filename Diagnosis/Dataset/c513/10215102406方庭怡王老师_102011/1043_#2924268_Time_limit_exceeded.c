#include <stdio.h>
#include <string.h>
 
int f[100002];
int c[600];
int w[600];
 
int max(int a, int b)
{
    return a>b?a:b;
}
 
int main()
{
    int n, m;
    int i, j, k;
    while(scanf("%d %d", &n,  &m)!=EOF)
    {
        for(i=1; i<=n; i++ )
        {
            scanf("%d %d", &c[i], &w[i] );
        }
        memset(f, 0, sizeof(f));
 
        for(j=1; j<=n; j++)
        {
            for(k=0; k<=m; k++)
            {
                if( k>=c[j] )
                {
                    f[k]=max( f[k], f[k-c[j]]+w[j] );
                }
            }
        printf("case #j-1",j );
        printf("%d\n", f[m] );
        }
    }
    return 0;
}