#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    long long A = *(long long*)a,B = *(long long*)b;
    return A>B;
}
int main()
{
    int n = 0,m = 0;
    scanf("%lld%lld",&n,&m);
    long long num[n];memset(num,0,n*sizeof(long long));
    for(int i = 0;i<n;i++)
    {
        scanf("%lld",&num[i]);
    }
    qsort(num,n,sizeof(num[0]),cmp);

    long long dif[n-1];memset(dif,0,(n-1)*sizeof(long long));
    for(int i = 0;i<n-1;i++)
    {
        dif[i] = num[i+1]-num[i];
    }
    int difSumLen = n-m+1;
    long long difSum[difSumLen];memset(difSum,0,difSumLen*sizeof(long long));
    for(int i = 0;i<difSumLen;i++)
    {
        for(int j = 0;j<i+m-1;j++)
        {
            difSum[i]+=dif[j]*(j+1);
        }
    }
    long long ans = difSum[0];
    for(int i = 0;i<difSumLen;i++)
    {
        if(difSum[i]<ans)
        {
            ans = difSum[i];
        }
    }
    printf("%lld",ans);
    return 0;
}
