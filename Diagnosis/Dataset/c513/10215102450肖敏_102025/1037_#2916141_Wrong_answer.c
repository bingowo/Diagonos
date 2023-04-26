#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n];
    for(int i = 0;i < n;i ++)
        scanf("%d",&a[i]);
    int cmp(const void *a,const void *b)
    {
        int *aa = (int*)a,*bb = (int*)b;
        return *aa - *bb;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int sum = 0,b[10000],j,min;
    if(m == n)
    {
        for(int x = 0;x < m;x++)
            sum += a[m-1] - a[x];
        min =sum;
    }  
    for(j = 0;j <n - m;j++)
    {
        sum = 0;
        for(int k = j;k < m;k ++)
        {
            sum += a[j+m-1] - a[j+k];
        }
        b[j] = sum;
    }
    for(int y= 0;y < j;y ++)
    {
        min = b[0];
        if(b[y] < min)
            min = b[y];
    }
    printf("%d",min);
    return 0;
}
