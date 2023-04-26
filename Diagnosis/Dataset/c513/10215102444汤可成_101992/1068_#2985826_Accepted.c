#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr[32][32] = {0};

int f(int m, int n)
{
    if(n<m) return 0;
    if(m == 1) arr[m][n] = (int)pow(2,n)-1;
    if(m == n) arr[m][n] = 1;
    if(arr[m][n] != 0) return arr[m][n];
    else
    {
        arr[m][n] = 2*f(m, n-1) + (int)pow(2, n-1-m) - f(m, n-1-m);
        return arr[m][n];
    }
}

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    while(n != -1 && m != -1)
    {
        printf("%d\n", f(m,n));
        scanf("%d %d",&n, &m);
    }
    return 0;
}
