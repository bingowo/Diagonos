#include <stdio.h>
#include <stdlib.h>
int cmp(const void*s1,const void*s2)
{
    if(*(long long int*)s1 > *(long long int*)s2)
        return 1;
    else
        return -1;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        long long int a[1001] = {0};
        long long int b[500501] = {0};
        int n,m,j,k,count = 1;
        scanf("%d %d",&n,&m);
        for(j = 1;j <= n;j++)
        {
            scanf("%lld",&a[j]);
            a[j] += a[j - 1];
        }
        for(j = 1;j <= n;j++)
        {
            for(k = j+1;k <= n;k++)
            {
                b[count++] = a[k] - a[j];
            }
        }
        qsort(b,count,sizeof(long long int),cmp);
        for(j = 1;j < count;j++)
        {
            b[j] += b[j - 1];   
        }
        int L,U;
        printf("case #%d:\n",i);
        for(k = 0;k < m;k++)
        {
            scanf("%d %d",&L,&U);
            printf("%lld\n",b[U] - b[L - 1]);
        }
        
    }
}