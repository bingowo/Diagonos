#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f(long long int n)
{
    int cnt=0;
    for(int i=0;i<64;i++)
    {
        if(n&1==1)cnt++;
        n>>=1;
    }
    return cnt;
}
int cmp(const void*a,const void*b)
{
long long int p1=*((long long int *)a);
long long int p2=*((long long int *)b);
if(f(p1)!=f(p2))return f(p2)-f(p1);
else {if(p1>p2)return 1;
else return -1;
}

}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
       long long int n;
        scanf("%lld",&n);
        long long int *a=(long long int *)malloc(sizeof(long long int)*n);
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&a[j]);

        }
qsort(a,n,sizeof(a[0]),cmp);
 for(int j=0;j<n;j++)
        {
            printf("%lld ",a[j]);
        }
printf("\n");
    }

}
