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
    scanf("%d%d",&n,&m);
    long long num[n];memset(num,0,n*sizeof(long long));
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    qsort(num,n,sizeof(num[0]),cmp);
    long long ans = 0;
    long long dif[n-1];memset(dif,0,(n-1)*sizeof(long long));
    for(int i = 0;i<n-1;i++)
    {
        dif[i] = num[i+1]-num[i];
        //printf("i = %d, dif[i] = %d ",i,dif[i]);
    }
    long long cur = 0;
    for(int j = 0;j<m-1;j++)
    {
        cur+=dif[j]*(j+1);//initialize cur
    }
    ans = cur;
    for(int j = 1;j<n-m+1;j++)
    {
        for(int k = j;k<j+m-2;k++)
        {
            cur-=dif[j];
        }
        cur+=dif[j+m-1]*m;
        if(cur<ans){ans = cur;}
    }
    printf("%lld\n",ans);
    return 0;
}
