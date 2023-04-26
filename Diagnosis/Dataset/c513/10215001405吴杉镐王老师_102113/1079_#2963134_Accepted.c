#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T,n,m,a[1005],cnt;
long long sum[1000005];

int cmp(const void* a,const void *b)
{
    long long x=*(long long *)a;
    long long y=*(long long *)b;
    if(x>y)
        return 1;
    else if(x<y)
        return -1;
    else
        return 0;
}

int main()
{
    scanf("%d",&T);
    for(int c=0;c<T;c++)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        //以下是本题的关键
        a[0]=0;
        cnt=0;
        for(int i=1;i<=n;i++)
            a[i]+=a[i-1];
        //关键的算法！
        for(int i=1;i<=n;i++)
            for(int j=1;j+i-1<=n;j++)
                sum[++cnt]=a[j+i-1]-a[i-1];
        //可以得到所有子数组的和！
        //
        qsort(sum+1,cnt,sizeof(long long),cmp);
        sum[0]=0;
        //同样的道理
        for(int i=1;i<=cnt;i++)
            sum[i]+=sum[i-1];
        int L,R;
        printf("case #%d:\n",c);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&L,&R);
            printf("%lld\n",sum[R]-sum[L-1]); //这样得到结果就非常的方便
        }
    }
    return 0;
}
//纯纯算法题 算法是灵魂！
