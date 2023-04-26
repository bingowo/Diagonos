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
    int diflen = n-m+1;
    long long dif[diflen];memset(dif,0,diflen*sizeof(long long));
    for(int i = 0;i<diflen;i++)
    {
        long long tmp = num[i+m-1];
        for(int j = i;j<i+m-1;j++)
        {
            dif[i]+=tmp-num[j];
        }
    }
    long long ans = dif[0];
    for(int i = 0;i<n-m+1;i++)
    {
        if(dif[i]<ans){ans = dif[i];}
    }

    //for(int j = 0;j<n;j++)
    //{
    //    printf("%d\n",num[j]);
    //}
    //for(int i = 0;i<n-m+1;i++)
    //{
    //    printf("dif[%d] = %lld\n",i,dif[i]);
    //}
    printf("%lld\n",ans);
    return 0;
}
