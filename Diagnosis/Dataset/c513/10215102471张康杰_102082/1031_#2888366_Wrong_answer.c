#include <stdio.h>
#include <stdlib.h>
int cmpA(const void*a,const void*b)
{
    return *(int*)a - *(int*)b;
}
int cmpB(const void*a,const void*b)
{
    return *(int*)b - *(int*)a;
}
int main()
{
    int T,i;
    for(i = 0;i < T;i++)
    {
        int n;
        scanf("%d",&n);
        int a[n],b[n];
        for(int j = 0;j < n;j++)
        {
            scanf("%d %d",&a[j],&b[j]);
        }
        qsort(a,n,sizeof(int),cmpA);
        qsort(b,n,sizeof(int),cmpB);
        int sum = 0;
        for(int j = 0;j < n;j++)
        {
            sum += a[j]*b[j];
        }
        printf("case #%d:\n%d\n",i,sum);
        
    }
    
    return 0;
}
